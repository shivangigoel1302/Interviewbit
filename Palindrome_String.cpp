int Solution::isPalindrome(string A) {
    int l = 0,r = A.size()-1;
    while(l < r){
        while(l < r && (A[l] == ' ' || !isalnum(A[l]) )){
            l++;
        }
        while(r > l && (A[r] == ' ' || !isalnum(A[r]))){
            r--;
        }
        if(A[l] == A[r] || abs(A[l] - A[r]) == 32){
            l++;
            r--;
            continue;
        }
        return 0;
    }
    return 1;
}
