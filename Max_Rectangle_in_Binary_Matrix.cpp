int helper(vector<int>v){
    stack<int>s;
    vector<int>left(v.size(),-1);
    for(int i = 0; i < v.size(); i++){
        while(!s.empty() && v[s.top()] >= v[i]){
            s.pop();
        }
        if(!s.empty()){
            left[i] = s.top();
        }

        s.push(i);
    }
    vector<int>right(v.size(),(int)v.size());
    while(!s.empty()){
        s.pop();
    }
    for(int i = v.size()-1; i>=0; i--){
        while(!s.empty() && v[s.top()] >= v[i]){
            s.pop();
        }
        if(!s.empty()){
            right[i] = s.top();
        }

        s.push(i);
    }
    int ans = INT_MIN;
    for(int i = 0; i < v.size(); i++){
        ans = max(ans,(right[i] - left[i] - 1)*v[i]);
    }
    return ans;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int>histogram(n);
    histogram = A[0];
    int ans = INT_MIN;
    ans = max(ans,helper(histogram));
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] == 0){
                histogram[j] = 0;
            }
            else{
                histogram[j] += 1;
            }
        }
        ans = max(ans,helper(histogram));
    }
    return ans;
}
