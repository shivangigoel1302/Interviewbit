
vector<int> Solution::primesum(int A) {
    vector<bool>prime(A,true);
     prime[0]= prime[1] = 0;
    for(long long i = 2; i < A; i++){
        if(prime[i]){
            for(long long j = i*i; j < A; j+=i){
                prime[j] = false;
            }
        }
    }
    // precompute(prime,A);
    for(long long i = 1; i < A; i++){
        if(prime[i] && prime[A-i]){
            return {i,A-i};
        }
    }
    return {-1};
}
