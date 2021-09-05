int Solution::solve(string A) {
    stack<int>s;
    int cnt = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == '('){
            s.push(A[i]);
        }
        else{
            if(!s.empty()){
                s.pop();
            }
            else{
                cnt++;
            }
        }
    }
    return s.size() + cnt;
}
