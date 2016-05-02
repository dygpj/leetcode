class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA=0;
        vector<int>::iterator it1,it2;
        it1=height.begin();
        it2=height.end()-1;
        while(it1<it2){
               int tmp=min(*it1,*it2)*(it2-it1);
               if (tmp>maxA) maxA=tmp;
               bool flag=0;
               while(flag==0 && it1<it2){
               if (*it1<*it2) {it1++;flag=(*it1>*(it1-1));}
               else if(*it1==*it2) {
                   if (*(it1+1)<*(it2-1)) {it2--;flag=(*it2>*(it2+1));}
                   else {it1++;flag=(*it1>*(it1-1));}
               } 
               else {it2--;flag=(*it2>*(it2+1));}
               
               }
               
        }
      
        return maxA;
    }
};