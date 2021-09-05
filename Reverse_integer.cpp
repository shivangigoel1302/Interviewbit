int Solution::reverse(int A) {
    bool isneg = false;
    if( A < 0){
        isneg  = true;
        A = abs(A);
    }
    long long int n =0;
    while( A > 0){
        n = n*10 + A%10;
        A/=10;
        if(n > INT_MAX){
            return 0;
        }
    }
    if(isneg){
        n = -1*n;
    }
    if(n < INT_MIN){
        return 0;
    }
    return n;
}
