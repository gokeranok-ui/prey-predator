/*
** main.c
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "coder_array.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "getFileID.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
//#include "Matrix_Import_From_TXT.h"
#include <stddef.h>
#include "opkene.h"
#include "opkene_main.h"
#include "opkene_terminate.h"
#include "opkene_rtwutil.h"
#include "opkene_types.h"
#include "fileManager.h"
//#include <SPIFFS.h>
//#include "spiffs_example_main.h"
#include <sys/unistd.h>
#include <sys/stat.h>
#include "hemen.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spiffs.h"
#include <dirent.h> 
#include <vector>
static const char *TAG = "example";
using namespace std;

int ReadNumbers( const string & s, vector <double> & v );

vector <double>& import_matrix_from_txt_file(const char* filename_X, vector <double>& v, int& rows, int& cols);
int main(void);

double opkene_main()

{

  ESP_LOGI(TAG, "Initializing SPIFFS");

    esp_vfs_spiffs_conf_t conf = {
      .base_path = "/spiffs",
      .partition_label = NULL,
      .max_files = 5,
      .format_if_mount_failed = true
    };

    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    ESP_LOGI(TAG, "Opening file");
    FILE* f = fopen("/spiffs/hello.txt", "w");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return 0;
    }
    fprintf(f, "Hello World!\n");
    fclose(f);
    ESP_LOGI(TAG, "File written");
printf("cemyilmaz=%f\n");
printf("ergin=%f\n");
coder::array<char, 2U> isim;
isim.set_size(1,14);

isim[0,0]='/';
isim[0,1]='s';
isim[0,2]='p';
isim[0,3]='i';
isim[0,4]='f';
isim[0,5]='f';
isim[0,6]='s';
isim[0,7]='/';
isim[0,8]='t';
isim[0,9]='i';
isim[0,10]='.';
isim[0,11]='f';
isim[0,12]='i';
isim[0,13]='s';
  

signed char fileid;
          fileid = cfopen(isim, "rt");
         
          if (fileid < 0) {
           printf("EmelSayin=%f\n");
          }

          printf("BarisManco=%d\n",fileid);

    std::vector <double> v;
    int rows=0;
    int cols=0;
vector <double> donn = import_matrix_from_txt_file("/spiffs/x.txt",v,rows,cols);

//printf("Sorun ne %f \n", donn[0] );
  
   // return v;
    
//std::cout<<donn.size()<<std::endl;

coder::array<double, 2U> iks;
        iks.set_size(1,donn.size());
        /*iks.set_size(1,3);
        iks[0,0] = 80;
        iks[0,1] = 120;
        iks[0,2] = 0.8;*/
        for (int dongel=0;dongel<donn.size();++dongel) {
        iks[0,dongel] = donn[dongel];
        }

  int fisOutputSize = 0;
       coder::array<double, 2U> ye;
       ye.set_size(1,1);
       fisOutputSize = opkene(isim,iks,ye);
        ye.set_size(1,fisOutputSize);
       for(int dongu=0;dongu<fisOutputSize;++dongu){
       ye[0,dongu] = 0.0d;  }
opkene(isim,iks,ye);
             for(int loop=0;loop<fisOutputSize;++loop)
{
              printf("sonucCCC=%f\n",ye[0,loop]);
}             
              
//printf("Ciktiii=%i\n",fisOutputSize);
      /* coder::array<double, 2U> ye;
       ye.set_size(1,2);
       ye[0,0] = 0;
       ye[0,1] = 0;*/
       //opkene(isim,iks,ye);
    opkene_terminate();
    double ttt = ye[0,0];
   // printf("Rahile=%f\n",ttt);
    //printf("Rahi=%f\n",ye[0,1]);
   // esp_vfs_spiffs_unregister(conf.partition_label);
    ESP_LOGI(TAG, "SPIFFS unmounted");
    return ttt;
}


int ReadNumbers( const string & s, vector <double> & v ) {
    istringstream is( s );
    double n;
    while( is >> n ) {
        v.push_back( n );
    }
    return v.size();
}


vector <double>& import_matrix_from_txt_file(const char* filename_X, vector <double>& v, int& rows, int& cols){
    
    ifstream file_X;
    string line;
    static double p[2];
    file_X.open(filename_X);
    if (file_X.is_open())
    {
        int i=0;
        getline(file_X, line);
        
        
        cols =ReadNumbers( line, v );
        cout << "cols:" << cols << endl;
        
        
        for ( i=1;i<32767;i++){
            if ( !getline(file_X, line) ) break;
            ReadNumbers( line, v );
            
        }
        
        rows=i;
        cout << "rows :" << rows << endl;
        if(rows >32766) cout<< "N must be smaller than MAX_INT";
        
        file_X.close();
    }
    else{
        cout << "file open failed";
    }
    
    cout << "v:" << endl;
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
         p[i*cols+j] = v[i*cols+j];
            cout << v[i*cols+j] << "\t" ;
         
        }
        cout << endl;
    }
    //p=v.data();
    return v;
}
