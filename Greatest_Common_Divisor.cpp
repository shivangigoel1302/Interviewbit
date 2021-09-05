int Solution::gcd(int A, int B) {
    if(A > B){
        return gcd(B,A);
    }
    if(A == 0  && B == 0){
        return 1;
    }
    else if(A== 0){
        return B;
    }
    return gcd(B%A,A);
}
