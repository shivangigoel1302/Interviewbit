int get(vector<int>&A,int mid){
   int cnt = 1;
   int pages = 0;
   for(int i = 0; i < A.size(); i++){
       pages += A[i];
       if(pages > mid){
           pages = A[i];
           cnt++;
       }
   }
   return cnt;
}
int Solution::books(vector<int> &A, int B) {
    if(A.size() < B){
        return -1;
    }
    int l = INT_MIN;
    long long r = 0;
    for(int i = 0; i < A.size(); i++){
        l = max(l,A[i]);
        r += A[i];
    }
    long long ans;
    while(l <= r){
        int mid = (l+r)/2;
        int x = get(A,mid);
        if(x > B){
            l = mid+1;
        }
        else{
            ans = mid;
            r = mid-1;
        }
    }
    return ans;
}
