int Solution::solve(vector<int> &A, int B) {
    long long ans = 0;
    priority_queue<int>pq;
    for(auto it: A){
        pq.push(it);
    }
    while(B--){
        long long int x = pq.top();
        pq.pop();
        ans += x;
        if(x){
            pq.push(x-1);
        }
    }
    return ans;
}
