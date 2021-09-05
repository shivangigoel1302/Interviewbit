int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for(int i = 0; i < n; i++){
        if(A[i] <= 0){
            A[i] = n+1;
        }
    }
    for(int i = 0; i < n; i++){
        if(abs(A[i]) <= n && A[abs(A[i]) -1 ] > 0){
            A[abs(A[i]) - 1 ] *= -1;
        }
    }
    int i = 0;
    while(i < n){
        if(A[i] > 0){
            return i+1;
        }
        i++;
    }
    return i+1;
}
