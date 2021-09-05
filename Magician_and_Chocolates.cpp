int Solution::nchoc(int A, vector<int> &B) {
    long long int ans = 0;
    int mod = 1e9+7;
    priority_queue<int>pq;
    for(auto i: B){
        pq.push(i);
    }
    while(A--){
        long long int x = pq.top();
        pq.pop();
        ans += x;
        pq.push(x/2);
    }
    return ans%mod;
}
