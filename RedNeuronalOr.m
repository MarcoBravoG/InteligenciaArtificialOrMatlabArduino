clc
clear all
p= [0 0 1 1; %Entrada 1
    0 1 0 1]; %Entrada 2
 t=[0 1 1 1]; 
net=newff(minmax(p),[2 1],{'tansig','purelin'},'traincgf');
net=init(net);
net.trainParam.epochs = 500 ;
net.trainParam.goal=1e-6;
net=train(net,p,t); 
a=sim(net,p)
pesos1=net.iw{1,1}
bias1=net.b{1,1}
peso2=net.lw{2,1}
bias2=net.b{2,1}

    



