function y=PRBS(seed,ts,b)
tb=ts/10;
t=0:tb:b*ts;
[m n] = size(t);
y=zeros(size(t));
k = 0;
for i=1:n
   if(k==b)
      break; 
   end    
   y(i) = seed(end); 
   if(mod(t(i),ts)==0 && t(i)>0) 
        k = k+1;    
        [m n]=size(seed);
        fseed = xor(seed(end),seed(end-1));
        for j=0:1:n
            if(n-j>1)
                seed(n-j) = seed(n-j-1);
            end    
        end
        seed(1)=fseed;
   end
   plot(t,y)
end
end