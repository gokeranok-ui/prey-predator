clc
clear all

tf=0;
while(tf~=1)
chickeninput=input('Enter Chicken population between 1000 and 5000 inclusive: ');
if (chickeninput < 1000) || (chickeninput > 5000)
        disp(sprintf('Invalid number of chickens, please input a value between 1000 and 5000'));
        tf=0;
        continue;
end
foxinput=input('Enter Fox population between 500 and 3000 inclusive: ');
if (foxinput < 500) || (foxinput > 3000)
        disp(sprintf('Invalid number of foxes, please input a value between 500 and 3000'));
        tf=0;
        continue;
end

wght=input('Enter weight of rule list, 1 for clipping and 2 for scaling: ');
if (wght<1)||(wght>2)
        disp(sprintf('Invalid weight entered, please input 1 or 2'));
        tf=0;
        continue;
end
tf=1;
end
%code1 is the object name
code1=newfis('Predatorprey');
code1=addvar(code1,'input','chicken',[1000 5000]);
code1=addvar(code1,'input','fox',[500 3000]);
code1=addvar(code1,'output','chickenchange',[-800 800]);
code1=addvar(code1,'output','foxchange',[-400 400]);

%Chicken membership functions
code1=addmf(code1,'input',1,'small','trapmf',[1000 1000 1200 1700]);
code1=addmf(code1,'input',1,'midsmall','trimf',[1200 1700 2500]);
code1=addmf(code1,'input',1,'mid','trimf',[1700 2500 3400]);
code1=addmf(code1,'input',1,'midlarge','trimf',[2500 3400 4600]);
code1=addmf(code1,'input',1,'large','trapmf',[3400 4600 5000 5000]);

%Fox membership functions
code1=addmf(code1,'input',2,'small','trapmf',[500 500 600 1000]);
code1=addmf(code1,'input',2,'midsmall','trimf',[600 1000 1500]);
code1=addmf(code1,'input',2,'mid','trimf',[1000 1500 2100]);
code1=addmf(code1,'input',2,'midlarge','trimf',[1500 2100 2800]);
code1=addmf(code1,'input',2,'large','trapmf',[2100 2800 3000 3000]);

%Change of chicken membership functions
code1=addmf(code1,'output',1,'NL','trimf',[-800 -800 -400]);
code1=addmf(code1,'output',1,'N','trimf',[-800 -400 0]);
code1=addmf(code1,'output',1,'O','trimf',[-400 0 400]);
code1=addmf(code1,'output',1,'P','trimf',[0 400 800]);
code1=addmf(code1,'output',1,'PL','trimf',[400 800 800]);

%Change of Fox membership functions (Output)
code1=addmf(code1,'output',2,'NL','trimf',[-400 -400 -200]);
code1=addmf(code1,'output',2,'N','trimf',[-400 -200 0]);
code1=addmf(code1,'output',2,'O','trimf',[-200 0 200]);
code1=addmf(code1,'output',2,'P','trimf',[0 200 400]);
code1=addmf(code1,'output',2,'PL','trimf',[200 400 400]);


%RULES

rules=[1 1 4 3 wght 1; 1 2 4 3 wght 1;1 3 4 2 wght 1;1 4 5 1 wght 1;1 5 5 1 wght 1;
    2 1 3 4 wght 1; 2 2 3 3 wght 1;2 3 4 3 wght 1;2 4 4 2 wght 1;2 5 5 1 wght 1;
    3 1 2 4 wght 1; 3 2 3 4 wght 1;3 3 3 3 wght 1;3 4 4 3 wght 1;3 5 4 2 wght 1;
    4 1 2 4 wght 1; 4 2 2 4 wght 1;4 3 3 4 wght 1;4 4 3 3 wght 1;4 5 4 3 wght 1;
    5 1 1 5 wght 1; 5 2 2 4 wght 1;5 3 2 4 wght 1;5 4 3 4 wght 1;1 5 2 3 wght 1];

code1 = addrule(code1,rules);

Results=evalfis([chickeninput;foxinput],code1);

 disp(sprintf('\nSuggested change in chicken population: %d\nSuggested change in fox population: %d\n For a specified weight of: %d', ceil(Results(1)), ceil(Results(2)),wght));





