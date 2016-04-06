class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor==0)
        return INT_MAX;
        int res=0;
        if (dividend==INT_MIN)
        {res+=1;dividend+=abs(divisor);
        if(divisor==1) return INT_MIN;
        if(divisor==-1) return INT_MAX;}
        if (divisor==INT_MIN)
        return res;
        bool isNeg=((dividend<0)^((divisor<0)))?true:false;
        dividend=abs(dividend);
        divisor=abs(divisor);
        int digit=0;
        while(divisor<=(dividend>>1)){
            digit++;
            divisor<<=1;
        }
        while(digit>=0){
            if (dividend>=divisor)
            {dividend-=divisor;
            res+=1<<digit;
            }
            divisor>>=1;
            digit--;
        }
        return isNeg?-res:res;
        
    }
};