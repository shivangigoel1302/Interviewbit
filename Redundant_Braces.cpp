int Solution::braces(string A) {
    stack<char>s;
    for(int i = 0; i < A.size(); i++){
        if(A[i] != ')'){
            s.push(A[i]);
        }
        else{

            bool sign = false;
            while(s.top()!= '('){
                char c = s.top();
                s.pop();
                if(c == '*' || c =='+' || c == '-' || c == '/'){
                    sign = true;
                }
            }
            s.pop();
            if(!sign){
                return 1;
            }
        }
    }

    return 0;
}
