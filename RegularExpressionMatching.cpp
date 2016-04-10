#include <iostream>
#include <string>

using namespace std;
//这里的a*表示a可以重复0次或者多次，不是a和*分开的。
/*class Solution {
public:
    bool isMatch(string s, string p) {
        int ls=s.size();
        int lp=p.size();
        if (lp==0) return ls==0;
        if (ls==0) {
            for (int i=0;i<lp;i++) {
                if(p[i]!='*') return false;
            }
            return true;
        }
        if (p[0]=='.') {return isMatch(s.substr(1),p.substr(1));}
        else if (p[0]=='*') {
            for (int i=0;i<=ls;i++) {
                if (isMatch(s.substr(i),p.substr(1))==true) return true;
            }
            return false;}
        else return (p[0]==s[0]) && isMatch(s.substr(1),p.substr(1));
    }
};
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int ls=s.size();
        int lp=p.size();
        if (lp==0) return ls==0;
        if (lp==1) return (ls==1 && (p[0]=='.' || p[0]==s[0]));
        if (p[1]=='*') {
            for (int i=0;i<ls;i++){
                if (isMatch(s.substr(i,1),p.substr(0,1))) {
                    if (isMatch(s.substr(i),p.substr(2))) return true;
                }
                else return isMatch(s.substr(i),p.substr(2));
            }
            return isMatch(s.substr(ls),p.substr(2));
        }
        else {
            return isMatch(s.substr(0,1),p.substr(0,1)) && isMatch(s.substr(1),p.substr(1));
        }
    }
};
int main()
{   Solution SS;
    string s,p;
    s="aa";
    p="a*";
    cout<<SS.isMatch(s,p);
    return 0;
}

