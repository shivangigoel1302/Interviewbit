int Solution::findMedian(vector<vector<int> > &A) {
    int min = INT_MAX,max = INT_MIN;
    int r = A.size();
    int n = A[0].size();
    for(int i = 0; i < r; i++){
        if(A[i][0] < min){
            min = A[i][0];
        }
        if(A[i][n-1] > max){
            max =A[i][n-1];
        }
    }
    int desired = (r*n+1)/2;
    while(min < max){
        int mid = (min+max)/2;
        int cnt = 0;
        for(int i = 0; i < r; i++){
            cnt += upper_bound(A[i].begin(),A[i].end(),mid) - A[i].begin();
        }
        if(cnt < desired){
            min = mid+1;
        }
        else{
            max = mid;
        }
    }
    return min;
}
