int Solution::solve(vector<int> &A, int B) {
    int l = 0;
    int r = A.size();
    int mid;
    while(l <= r){
         mid = (l+r)/2;
        if(A[mid] > B){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return min((int)A.size(),mid + (A[mid] <= B));
}
