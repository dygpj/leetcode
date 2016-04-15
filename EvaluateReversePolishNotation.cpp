class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for (int i=0;i<tokens.size();i++){
            if (!(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/") ) {
                stringstream ss;
                ss << tokens[i];
                int n;
                ss >> n;
                num.push(n);
            }
            else{
                    int a=num.top();num.pop();
                    int b=num.top();num.pop();
                switch(tokens[i][0]){
                    case '+': num.push(a+b);break;
                    case '-': num.push(b-a);break;
                    case '*': num.push(b*a);break;
                    case '/': num.push(b/a);break;
                }
            }
        }
        return num.top();
    }
};
