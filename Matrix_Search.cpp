int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int l =0,r=A.size();
    int n = A[0].size();
    while(l < r){
        int mid = (l+r)/2;
        if(A[mid][n-1] >= B){
            if(A[mid][0] <= B){
                r = mid;
                break;
            }
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    int row = r;
    int k = 0;
    int m = n;
    if(row == -1 || row == A.size()){
        return 0;
    }

    while(k <= m){
        int mid = (k+m)/2;
        if(A[row][mid] == B ){
            return 1;
        }
        else if(A[row][mid] < B){
            k = mid+1;
        }
        else{
            m = mid-1;
        }
    }
    return 0;
}
