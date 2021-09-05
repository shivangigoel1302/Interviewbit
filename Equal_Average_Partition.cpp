bool ispossible(int i,int target,int element,vector<int>&A,vector<int>&temp,vector<vector<vector<bool>>>&dp){
    if(element == 0){
        return target == 0;
    }
    if(i >= A.size()){
        return false;
    }
    if(dp[i][target][element] != true){
        return dp[i][target][element];
    }
    if(A[i] <= target){
        temp.push_back(i);
        if(ispossible(i+1,target-A[i],element-1,A,temp,dp)){
            return dp[i][target][element] = true;
        }
        temp.pop_back();
    }
    if(ispossible(i+1,target,element,A,temp,dp)){
        return dp[i][target][element] = true;
    }
    return dp[i][target][element] = false;
}
vector<vector<int> > Solution::avgset(vector<int> &A) {
    int sum = 0;
    int n = A.size();
    for(int i = 0; i < n; i++){
        sum += A[i];
    }
    sort(A.begin(),A.end());
    vector<int>ans;
    vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(sum+1,vector<bool>(n,true)));
    for(int i = 1; i < n; i++){
        if((sum*i)%n == 0){
            int target = (sum*i)/n;

            vector<int>temp;
            vector<int>first;
            vector<int>second;
            if(ispossible(0,target,i,A,temp,dp)){
                unordered_set<int>s;
                for(auto it: temp){
                    s.insert(it);

                }
                for(int j = 0; j < n; j++){
                        if(s.find(j) != s.end()){
                            second.push_back(A[j]);
                        }
                        else{
                            first.push_back(A[j]);
                        }
                    }
                    if(first.size() < second.size()){
                        return {first,second};
                    }
                    return {second, first};
            }
        }
    }
    return {};
}
