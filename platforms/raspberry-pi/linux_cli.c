#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "fis_virtual_fs.h"
#include "fuzzy_runner.h"

static int read_line(char *buf, size_t len) {
	if (!fgets(buf, len, stdin)) return 0;
	size_t n = strlen(buf);
	if (n && (buf[n-1] == '\n')) buf[n-1] = '\0';
	return 1;
}

static void print_usage(const char *prog) {
	fprintf(stderr, "Usage: %s [--fis <path>] [<in1> <in2> ...]\n", prog);
	fprintf(stderr, "  --fis <path>   Optional path to a .fis file (default: tipper.fis)\n");
	fprintf(stderr, "  <in1> ...      Optional numeric inputs. If all are supplied, runs once\n");
	fprintf(stderr, "                 non-interactively and prints results; otherwise enters\n");
	fprintf(stderr, "                 interactive prompt.\n");
}

int main(int argc, char **argv) {
	const char *fis_path = "tipper.fis";
	int argi = 1;
	while (argi < argc) {
		if ((strcmp(argv[argi], "--help") == 0) || (strcmp(argv[argi], "-h") == 0)) {
			print_usage(argv[0]);
			return 0;
		}
		if (strcmp(argv[argi], "--fis") == 0 && (argi + 1) < argc) {
			fis_path = argv[argi + 1];
			argi += 2;
		} else {
			break;
		}
	}

	fis_virtual_fs_init();
	if (!fis_virtual_fs_load_file(fis_path)) {
		if (argi == 1) {
			fprintf(stderr, "Failed to load default FIS; falling back failed.\n");
		} else {
			fprintf(stderr, "Failed to load FIS: %s\n", fis_path);
			print_usage(argv[0]);
		}
		return 1;
	}

	/* Discover system dimensions and names */
	const uint32_t num_inputs  = fis_virtual_fs_get_input_count();
	const uint32_t num_outputs = fis_virtual_fs_get_output_count();
	if (num_inputs == 0 || num_outputs == 0) {
		fprintf(stderr, "Invalid FIS metadata (inputs=%lu, outputs=%lu)\n",
		        (unsigned long)num_inputs, (unsigned long)num_outputs);
		return 1;
	}

	/* Configure runner and filename hint */
	fuzzy_runner_set_fis_filename(fis_path);
	fuzzy_runner_configure(num_inputs, num_outputs);
	fuzzy_runner_init();

	/* Print banner */
	const char *loaded_name = fis_virtual_fs_get_loaded_filename();
	printf("fuzzy_cli\n");
	printf("FIS: %s\n", loaded_name ? loaded_name : "(unknown)");
	printf("System: %lu input(s) x %lu output(s)\n",
	       (unsigned long)num_inputs, (unsigned long)num_outputs);

	/* Show input names */
	for (uint32_t i = 0; i < num_inputs; ++i) {
		const char *nm = fis_virtual_fs_get_input_name(i);
		printf("  In%lu: %s\n", (unsigned long)(i+1), nm ? nm : "(input)");
	}
	/* Show output names */
	for (uint32_t i = 0; i < num_outputs; ++i) {
		const char *nm = fis_virtual_fs_get_output_name(i);
		printf("  Out%lu: %s\n", (unsigned long)(i+1), nm ? nm : "(output)");
	}

	/* Allocate IO buffers */
	float *inputs  = (float *)calloc(num_inputs, sizeof(float));
	float *outputs = (float *)calloc(num_outputs, sizeof(float));
	if (inputs == NULL || outputs == NULL) {
		fprintf(stderr, "Allocation failed\n");
		free(inputs); free(outputs);
		return 1;
	}

	/* If sufficient positional inputs are provided, run once non-interactively */
	int remaining_args = argc - argi;
	if (remaining_args > 0 && remaining_args != (int)num_inputs) {
		print_usage(argv[0]);
		free(outputs);
		free(inputs);
		return 1;
	}
	if (remaining_args == (int)num_inputs) {
		/* One-shot mode: do not print interactive banner */
		const char *loaded_name = fis_virtual_fs_get_loaded_filename();
		for (uint32_t i = 0; i < num_inputs; ++i) {
			inputs[i] = (float)strtof(argv[argi + (int)i], NULL);
		}
		struct timespec start, end;

		clock_gettime(CLOCK_MONOTONIC, &start);

		(void)fuzzy_runner_execute(inputs, num_inputs, outputs, num_outputs);

		clock_gettime(CLOCK_MONOTONIC, &end);

		long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);

		long elapsed_us = elapsed_ns / 1000;

		double elapsed_ms = elapsed_us / 1000.0;
		printf("\nFuzzy Inference Result\n");
		printf("----------------------\n");
		printf("FIS file : %s\n", loaded_name ? loaded_name : "(unknown)");
		printf("Inputs   : ");
		for (uint32_t i = 0; i < num_inputs; ++i) {
			const char *nm = fis_virtual_fs_get_input_name(i);
			printf("%s%s = %f", (i ? ", " : ""), (nm ? nm : "in"), inputs[i]);
		}
		printf("\n");
		for (uint32_t i = 0; i < num_outputs; ++i) {
			const char *on = fis_virtual_fs_get_output_name(i);
			printf("Output%s : %f\n", (on ? " " : ""), outputs[i]);
		}
		printf("Execution time: %ld us (%.3f ms)\n", elapsed_us, elapsed_ms);
		free(outputs);
		free(inputs);
		fuzzy_runner_deinit();
		return 0;
	}

	/* Interactive banner */
	printf("fuzzy_cli\n");
	printf("FIS: %s\n", loaded_name ? loaded_name : "(unknown)");
	printf("System: %lu input(s) x %lu output(s)\n",
	       (unsigned long)num_inputs, (unsigned long)num_outputs);
	for (uint32_t i = 0; i < num_inputs; ++i) {
		const char *nm = fis_virtual_fs_get_input_name(i);
		printf("  In%lu: %s\n", (unsigned long)(i+1), nm ? nm : "(input)");
	}
	for (uint32_t i = 0; i < num_outputs; ++i) {
		const char *nm = fis_virtual_fs_get_output_name(i);
		printf("  Out%lu: %s\n", (unsigned long)(i+1), nm ? nm : "(output)");
	}
	puts("Enter inputs separated by spaces, or Ctrl-D to exit.");

	char line[512];
	while (1) {
		/* Prompt showing input names */
		fputs("> ", stdout);
		for (uint32_t i = 0; i < num_inputs; ++i) {
			const char *nm = fis_virtual_fs_get_input_name(i);
			printf("%s%s", (nm ? nm : "in"), (i + 1U < num_inputs) ? " " : "");
		}
		fputs(" = ", stdout);
		fflush(stdout);

		if (!read_line(line, sizeof(line))) {
			puts("");
			break;
		}

		/* Parse exactly num_inputs floats */
		char *ptr = line;
		int ok = 1;
		for (uint32_t i = 0; i < num_inputs; ++i) {
			char *endp = NULL;
			while (*ptr == ' ' || *ptr == '\t') ptr++;
			if (*ptr == '\0') { ok = 0; break; }
			float v = strtof(ptr, &endp);
			if (endp == ptr) { ok = 0; break; }
			inputs[i] = v;
			ptr = endp;
		}
		if (!ok) {
			puts("Parse error. Please enter space-separated numbers for all inputs.");
			continue;
		}

		/* Execute */


		struct timespec start, end;


		clock_gettime(CLOCK_MONOTONIC, &start);
		(void)fuzzy_runner_execute(inputs, num_inputs, outputs, num_outputs);


		clock_gettime(CLOCK_MONOTONIC, &end);


		long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);


		long elapsed_us = elapsed_ns / 1000;


		double elapsed_ms = elapsed_us / 1000.0;

		
		for (uint32_t i = 0; i < num_outputs; ++i) {
			const char *on = fis_virtual_fs_get_output_name(i);
			printf("%s%s= %.6f%s",
			       (i == 0 ? "" : " "),
			       (on ? on : "out"),
			       outputs[i],
			       "");
		}
		printf(" [%ld us (%.3f ms)]\n", elapsed_us, elapsed_ms);
	}

	free(outputs);
	free(inputs);
	fuzzy_runner_deinit();
	return 0;
}
