bool reachable(int src,int dest,vector<bool>&visited,vector<int>v[]){
    if(src == dest){
        return true;
    }
    visited[src] = true;
    for(auto nbr: v[src]){
        if(!visited[nbr]){
            if(reachable(nbr,dest,visited,v)){
                return true;
            }
        }
    }
    visited[src] = false;
    return false;
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size();
    int val = INT_MIN;
    for(int i = 0; i < n; i++){
        val = max(val,A[i]);
    }
    vector<int>v[val+1];
    for(int i = 0; i < C.size(); i++){
        v[A[C[i][0]-1]].push_back(A[C[i][1]-1]);
        v[A[C[i][1] -1]].push_back(A[C[i][0]-1]);
    }
    for(int i = 0; i < n; i++){
        vector<bool>visited(n,false);
        if(A[i] != B[i]){
            if(!reachable(A[i],B[i],visited,v)){
                return 0;
            }
        }
    }
    return 1;
}
