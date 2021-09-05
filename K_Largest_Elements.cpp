vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int,vector<int>,greater<int>>pq;
    int i = 0;
    while(i < A.size()){
        pq.push(A[i]);
        if(pq.size() > B){
            pq.pop();
        }
        i++;
    }
    vector<int>ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
