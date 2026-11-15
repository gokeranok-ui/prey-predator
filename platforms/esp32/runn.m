cfg = coder.config('exe'); cfg.TargetLang = 'C++';
cfg.CustomSource = 'opkene_main.cpp';
cfg.CustomInclude = 'C:\Users\prizy\Desktop\Azkaldi';
codegen -config cfg -args {fileName, x} opkene_main.cpp opkene.m -report 