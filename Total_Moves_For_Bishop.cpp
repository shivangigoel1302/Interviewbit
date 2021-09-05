int Solution::solve(int A, int B) {
    int i = A,j=B;
    int ans = 0;
    ans += min(i-1,8-B);
    ans += min(i-1,B-1);
    ans += min(8-i,B-1);
    ans += min(8-i,8-B);
    return ans;
}
