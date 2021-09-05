int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i = 0; i < A.size();){
        int j = i+1;
        while(j < A.size() && A[j] == A[i]){
            j++;
        }
        if(A.size() - j == A[i]){
            return 1;
        }
        i = j;
    }
    return -1;
}
