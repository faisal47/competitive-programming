function[]=maclaurin(p,t)

    sum=0;
    x=.5;
    for i=0:5
       
        presum=sum;
        if i==0
            sum=1;
        else
            sum= sum + (x^i / factorial(i));
        end
        
        ea(i+1)=(sum - presum)*100;
        
        et(i+1)=(t-sum)/t*100;
        
    end
    
    tr=0:5
    subplot(2,1,1);
    plot(tr,et);
    subplot(2,1,2);
    plot(tr,ea);
    
end