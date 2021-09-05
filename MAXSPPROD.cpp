int Solution::maxSpecialProduct(vector<int> &A) {
    stack<long long>s;
    vector<long long>left(A.size());
    vector<long long>right(A.size());
    long long mod = 1e9+7;
    for(long long int i = 0; i < A.size(); i++){
        while(!s.empty() && A[s.top()] <= A[i]){
            s.pop();
        }
        if(!s.empty()){
            left[i] = s.top();
        }
        else{
            left[i] = -1;
        }
        s.push(i);
    }
    while(!s.empty()){
        s.pop();
    }
    for(long long int i = A.size()-1; i >= 0; i--){
        while(!s.empty() && A[s.top()] <= A[i]){
            s.pop();
        }
        if(!s.empty()){
           right[i] = s.top();
        }
        else{
            right[i] = A.size();
        }
        s.push(i);
    }
    long long maximum = 0;
    for(long long int i = 0; i < A.size(); i++){
        if(left[i] == -1 || right[i] == A.size()){
            continue;
        }
        maximum = max(maximum,(long long)((left[i]*right[i])));
    }
    return maximum%mod;

}
