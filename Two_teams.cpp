bool dfs(vector<int>&teams,vector<long long int>adj[],long long int src,long long int parent){
    for(auto nbr : adj[src]){
        if(nbr == parent){
            continue;
        }
        if(teams[nbr] == -1){
            teams[nbr] = teams[parent]^1;
            if(!dfs(teams,adj,nbr,src)){
                return false;
            }
        }
        else if(teams[nbr] == teams[src]){
            return false;
        }
    }
    return true;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int>teams(A+1,-1);
    vector<long long int>adj[A+1];
    for(int i = 0; i < B.size(); i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    teams[0] = 0;
    return dfs(teams,adj,1,0);
}
