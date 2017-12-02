function[]=taylor()

    a=1.2;
    t=.2;
    h=1;
    er(1)=abs((t-a)/t)
    
    f= @(x) -(.4*(x^3))-(.45*(x^2))-x-.25;
    a=a+f(0);
    er(2)=abs((t-a)/t)
    
    f= @(x) -1.2*(x^2) -.9*x-1.;
    a=a+ f(0)/factorial(2);
    er(3)=abs((t-a)/t)
    
    f= @(x) -2.4*x -.9;
    a=a+ f(0)/factorial(3);
    er(4)=abs((t-a)/t)
    
    a=a+ (-2.4)/factorial(4);
    er(5)=abs((t-a)/t)
    
    i=1:5;
    plot(i,er);
    
end