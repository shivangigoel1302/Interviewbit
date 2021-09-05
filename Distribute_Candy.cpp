int Solution::candy(vector<int> &A) {
    int n = A.size();
    vector<int>ans(n,1);
    for(int i = 1; i < n; i++){
        if(A[i] > A[i-1] && ans[i] <= ans[i-1]){
            ans[i] = 1 + ans[i-1];
        }
    }
    for(int i = n-2; i>=0 ;i--){
        if(A[i] > A[i+1] && ans[i] <= ans[i+1]){
            ans[i] = ans[i+1] + 1;
        }
    }
    int cnt = 0int Solution::candy(vector<int> &A) {
    int n = A.size();
    vector<int>ans(n,1);
    for(int i = 1; i < n; i++){
        if(A[i] > A[i-1] && ans[i] <= ans[i-1]){
            ans[i] = 1 + ans[i-1];
        }
    }
    for(int i = n-2; i>=0 ;i--){
        if(A[i] > A[i+1] && ans[i] <= ans[i+1]){
            ans[i] = ans[i+1] + 1;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += ans[i];
    }
    return cnt;

    // int prev = 0;
    // long long int ans = 0;

    // for(int i = 0; i < A.size(); i++){

    //     int j = i;
    //     while(j+1 < A.size() && A[j+1] < A[j]){
    //         j++;
    //     }

    //   int num = (j-i)+1;
    //     ans = ans + (num*(num+1))/2;
    //     if(i != 0 && A[i-1] < A[i] && prev >= num)
    //         ans += (prev - num) + 1;

    //     if(j == i && i != 0 && A[i-1] < A[i])
    //         prev = max(prev + 1, num);
    //     else
    //         prev = 1;

    //     i = j;
    // }

    // return ans;
}

    for(int i = 0; i < n; i++){
        cnt += ans[i];
    }
    return cnt;
}

