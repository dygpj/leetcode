#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {//divide input into left and right by ops
            string left;
            string right;
            vector<int> l_res;
            vector<int> r_res;
            vector<int> res;

            int idx;
            idx=0;
            for(int i=0;i<input.size();i++){
                if (input[i]=='+'||input[i]=='-'||input[i]=='*') {
                    idx++;
                left=input.substr(0,i);
                right=input.substr(i+1,input.size()-i-1);
                l_res=diffWaysToCompute(left);
                r_res=diffWaysToCompute(right);
                for (int j=0;j<l_res.size();j++){
                    for (int k=0;k<r_res.size();k++){
                    switch(input[i]){
                        case '+':res.push_back(l_res[j]+r_res[k]);break;
                        case '-':res.push_back(l_res[j]-r_res[k]);break;
                        case '*':res.push_back(l_res[j]*r_res[k]);break;
                        default:break;
                    }
                    }
                }
                }
            }
            if (idx==0){
                int num=0;
                for(int i=0;i<input.size();i++){
                    num=num*10+input[i]-'0';
                }
                res.push_back(num);
            }
        return res;
    }
};


int main() {

        string input;
        cin >> input;
        Solution s;
        vector<int> r = s.diffWaysToCompute(input);
        for(vector<int>::iterator iter = r.begin(); iter != r.end(); ++iter) {
                cout << *iter << endl;
        }
        return 0;
}
