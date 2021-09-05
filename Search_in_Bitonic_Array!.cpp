int Solution::solve(vector<int> &A, int B) {
    int l = 0;
    int r = A.size();
    int pivot;
    while(l <= r){
        int mid = (l+r)/2;
        if(A[mid] > A[mid-1] && A[mid] > A[mid+1]){
            pivot = mid;
            break;
        }
        else if(A[mid] < A[mid+1]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    if(A[pivot] == B){
        return pivot;
    }
    else if(B > A[pivot]){
        return -1;
    }
    l = 0;
    r = pivot;
    while(l <= r){
        int mid =(l+r)/2;
        if(A[mid] == B){
            return mid;
        }
        if( B > A[mid]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    l = pivot+1;
    r = A.size();
    while(l <= r){
        int mid= (l+r)/2;
        if(A[mid] == B){
            return mid;
        }
        else if(A[mid] > B){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}
