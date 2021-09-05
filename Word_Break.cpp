string a;
set<string> s;
int dp[6509];
bool f(int i)
{
    if(i==a.size())
        return 1;
    if(dp[i]!=-1)
        return dp[i];
    string temp;
    int j=i;
    while(j<a.size())
    {
        temp+=a[j];
        if(s.find(temp)!=s.end()&&f(j+1))
            return dp[i]=1;
        j++;
    }
    return dp[i]=0;
}
int Solution::wordBreak(string A, vector<string> &B) {
    s.clear();
    memset(dp,-1,sizeof(dp));
    for(auto x:B)
        s.insert(x);
    a=A;
    return f(0);
}
