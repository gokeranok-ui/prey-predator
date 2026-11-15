function y = opkene(fileName,x)
    %#codegen
    
    fis = getFISCodeGenerationData(fileName);
    opt = evalfisOptions('NumSamplePoints',51);
    y = evalfis(fis,x,opt);
end