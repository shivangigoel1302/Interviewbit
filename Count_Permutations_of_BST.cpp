#define MOD 1000000007
#define ll long long
ll add(ll A,ll B)
{
    return ((A%MOD)+(B%MOD))%(MOD);
}
ll mul(ll A ,ll B)
{
    return ((A%MOD)*(B%MOD))%MOD;
}
void comb(vector<vector<ll>> &A)
{
    int n=A.size();
    A[0][0]=1;
    for(int i=0;i<n;i++)
        A[i][0]=1,A[i][i]=1;
    for(int i=1;i<n;i++)
        for(int j=1;j<=i;j++)
            A[i][j]=add(A[i-1][j-1],A[i-1][j]);
}
int Solution::cntPermBST(int A, int B) {
    vector<vector<ll>> combinations(51,vector<ll> (51));
    comb(combinations); //precalculating nck and saving
    vector<vector<ll>> dp(A+1,vector<ll> (B+1));
    dp[0][0]=1;
    dp[1][0]=1;
    for(int nodes=2;nodes<=A;nodes++)
    {
        for(int height=1;height<=B;height++)
        {
            for(int rootpos=1;rootpos<=nodes;rootpos++)
            {
                int leftnodes=rootpos-1,rightnodes=nodes-rootpos;
                ll sum1=0,sum2=0,currVal=0;
                for(int h=0;h<height-1;h++)
                    sum1=add(sum1,dp[leftnodes][h]),sum2=add(sum2,dp[rightnodes][h]);
                currVal=add(currVal,mul(sum1,dp[rightnodes][height-1]));
                currVal=add(currVal,mul(sum2,dp[leftnodes][height-1]));
                currVal=add(currVal,mul(dp[leftnodes][height-1],dp[rightnodes][height-1]));
                currVal=mul(currVal,combinations[leftnodes+rightnodes][leftnodes]);
                dp[nodes][height]=add(dp[nodes][height],currVal);
            }
        }
    }
    return (dp[A][B]%MOD);
}
