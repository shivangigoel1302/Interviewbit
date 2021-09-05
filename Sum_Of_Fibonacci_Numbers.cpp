int Solution::fibsum(int A) {
    vector<int>fib;
    fib.push_back(1);
    fib.push_back(1);
    int n = fib.size();
    while(fib[n-1] <= A){
        fib.push_back(fib[n-1] + fib[n-2]);
        n = n+1;
    }
    int cnt = 0;
    int i = n-1;
    while(A > 0){
        if(fib[i] <= A){

            while(fib[i] <= A){
                cnt++;
                A-=fib[i];
            }
        }
        i--;
    }
    return cnt;
}
