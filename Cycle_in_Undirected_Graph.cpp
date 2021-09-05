bool has_cycle(map<int,vector<int>>&m,vector<bool>&vis,int curr,int parent)
{
    vis[curr]=true;
    for(auto it:m[curr])
    {
        if(vis[it] && it!=parent)
        {
            return true;
        }
        if(!vis[it] && has_cycle(m,vis,it,curr))
        {
            return true;
        }
    }
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B)
{
    map<int,vector<int>>m;
    for(int i=0;i<B.size();i++)
    {
        m[B[i][0]].push_back(B[i][1]);
        m[B[i][1]].push_back(B[i][0]);
    }
    for(auto it:m)
    {
        vector<bool>vis(A+1,false);
        if(has_cycle(m,vis,it.first,-1))
        {
            return true;
        }
    }
    return false;
}
