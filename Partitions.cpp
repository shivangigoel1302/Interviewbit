int Solution::solve(int A, vector<int> &B) {
    int n = B.size();
    vector<int>left(n,0);
    left[0] = B[0];
    vector<int>right(n,0);
    right[n-1] = B[n-1];
    for(int i = 1; i < n; i++){
        left[i] = left[i-1] + B[i];
    }
    int target = left[n-1]/3;
    int cnt = 0;
    for(int i = n-2; i>=0 ; i--){
        right[i] = right[i+1] + B[i];
        if(right[i] == target){
            cnt++;
        }
    }

    if(right[n-1] == target) cnt++;
    int ans = 0;
    if(left[n-1] % 3 != 0){
        return 0;
    }
    for(int i = 0; i < n-2 ;i++){
        if(right[i] == target){
            cnt--;
        }
        if(left[i] == target){
            ans += cnt;
            if(right[i+1] == target){
                ans--;
            }
        }
    }
    return ans;
}
