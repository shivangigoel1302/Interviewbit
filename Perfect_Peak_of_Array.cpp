int Solution::perfectPeak(vector<int> &A) {
    int n = A.size();
    vector<int>left(n,INT_MIN);
    vector<int>right(n,INT_MAX);
    for(int i = 1; i < n; i++){
        left[i] = max(left[i-1],A[i-1]);
    }
    for(int i = n-2; i >= 0;i--){
        right[i] = min(right[i+1],A[i+1]);
    }
    for(int i = 1; i < n-1; i++){
        if(A[i] > left[i] && A[i] < right[i]){
            return 1;
        }
    }
    return 0;
}
