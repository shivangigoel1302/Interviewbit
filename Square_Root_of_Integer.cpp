int Solution::sqrt(int A) {
    long long int l = 0;
    long long int r = A;
    while(l <= r){
        long long int mid = (l+r)/2;
        if(mid*mid == A){
            return mid;
        }
        else if(mid*mid < A){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return r;
}
