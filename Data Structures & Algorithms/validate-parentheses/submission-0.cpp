class Solution {
public:
bool isCorrectClosingBracket(char closing,char opening){
    if(closing==')'){
        return opening=='(';
    }
    if(closing==']'){
        return opening=='[';
    }
    if(closing=='}'){
        return opening=='{';
    }
    return false;
}

bool isClosing(char c){
    return c==')'||c=='}'||c==']';
}
bool isOpening(char c){
    return c=='('||c=='{'||c=='[';
}
    bool isValid(string s) {
        stack<char> stk;
        for(char c:s){
            if(isOpening(c)){
                stk.push(c);
            }else{
                if(!stk.empty()){
                    int o=stk.top();
                    stk.pop();
                    if(!isCorrectClosingBracket(c,o)){
                        return false;
                    }

                }else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
