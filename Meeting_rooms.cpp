int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    vector<int>start(n),finish(n);
    for(int i=0;i<n;i++)
    {
        start[i]=A[i][0];
        finish[i]=A[i][1];
    }
    sort(start.begin(),start.end());
    sort(finish.begin(),finish.end());
    int rooms = 1;
    int ans = 0;
    int i = 1;
    int j = 0;
    while(i < n && j < n){
        if(start[i] < finish[j]){
            rooms++;
            i++;
        }
        else if(start[i] >= finish[j]){
            rooms--;
            j++;
        }
        ans = max(ans,rooms);
    }
    return ans;
}
