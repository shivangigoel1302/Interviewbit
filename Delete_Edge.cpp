long long int dfs(int src,unordered_map<int,int>m,vector<int>adj[],int par,vector<int> &A){
    long long int curr = 0;
    for(auto nbr: adj[src]){
        if(nbr != par){
            curr += dfs(nbr,m,adj,src,A);
        }
    }
    curr += A[src-1];
    m[src] = curr;
    return curr;
}
long long int getmax(int src,unordered_map<int,int>&m,vector<int>adj[],int total,int par){
    long long int curr = INT_MIN;
    for(auto nbr:adj[src]){
        if(nbr == par){
            continue;
        }
        curr = max(curr,getmax(nbr,m,adj,total,src));
        curr = max(curr,(long long )(total - m[nbr])*m[nbr]);
    }
    return curr;
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    unordered_map<int,int>m;
    vector<int>adj[A.size()+1];
    for(int i = 0; i < B.size(); i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    long long int total = dfs(1,m,adj,-1,A);
    long long int ans = getmax(1,m,adj,total,-1);
    return ans;
}
