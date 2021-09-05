int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<int>adj[A+1];
    vector<int>indeg(A+1,0);
    queue<int>q;
    for(int i = 0; i < B.size(); i++){
        adj[B[i]].push_back(C[i]);
        indeg[C[i]]++;
    }
    for(int i = 1; i < A+1; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cnt++;
        for(auto nbr: adj[x]){
            indeg[nbr]--;
            if(indeg[nbr] == 0){
                q.push(nbr);
            }
        }
    }
    if(cnt == A){
        return 1;
    }
    return 0;
}
