class Solution {
public:
    int calculate(string s) {
        // vector<int> arr;
        stack<int> st;
        // for(int i=0;i<s.size();i++){
        //     arr[i]=s[i]-'0';
        // }
        int sign = 1;
        int result=0;
        int num=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
                
            }
            else if(s[i]=='+'){
                result += num*sign;
                num=0;
                sign = 1;
                
            }else if(s[i]=='-') {
                result += num*sign;
                num=0;
                sign = -1;
            }
            if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result = 0;
                num=0;
                sign = 1;
            }
            else if(s[i]==')'){
                result += num*sign;
                num = 0;
                int stackSign=st.top();
                st.pop();
                int stackResult=st.top();
                st.pop();
                result*=stackSign ;
                result+=stackResult;
            } 
            
        }
        result+=num*sign;
        return result;
    }
};