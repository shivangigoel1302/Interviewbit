int Solution::isPalindrome(int A) {
    int n = 0;
    int a = A;
    while(A > 0){
        n = n*10 + A%10;
        A/=10;
    }
    if(n == a){
        return 1;
    }
    return 0;
}
