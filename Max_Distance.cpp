int Solution::maximumGap(const vector<int> &A) {
    vector<int>suffix(A.size());
    int n = A.size();
    suffix[n-1] = A[n-1];
    for(int i = n-2; i >= 0; i--){
        suffix[i] = max(suffix[i+1],A[i]);
    }
    int j = 0,i=0,diff=0;
    while(j < n && i < n){
        if(A[i] <= suffix[j]){
            diff = max(diff,j-i);
            j++;
        }
        else{
            i++;
        }
    }
    return diff;
}
