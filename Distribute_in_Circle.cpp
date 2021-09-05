int Solution::solve(int A, int B, int C) {
    C--;
     A%=B;
     int ans = (C + A - 1)%B;
     return ans + 1;
}
