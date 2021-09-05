int Solution::search(const vector<int> &A, int B) {
    int l = 0;
    int r = A.size()-1;
    int n = A.size();
    while(l <= r){
        int mid = (l+r)/2;
        if(A[mid] == B){
            return mid;
        }
        else if(A[mid] < A[r]){
            if(B > A[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        else{
           if(B < A[mid] && B >= A[l]){
               r = mid-1;
           }
           else{
               l = mid+1;
           }
        }
    }
    return -1;
}
