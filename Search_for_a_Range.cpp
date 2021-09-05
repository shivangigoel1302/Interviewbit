vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int l = 0;
    int r = A.size()-1;
    int idx = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(A[mid] == B){
            idx = mid;
            r= mid-1;
        }
        else if(A[mid] < B){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    vector<int>ans;
    ans.push_back(idx);
    l = 0;
    r = A.size()-1;
    idx = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(A[mid] == B){
            idx = mid;
            l = mid+1;
        }
        else if(A[mid] < B){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    ans.push_back(idx);
    return ans;
}
