vector<int> Solution::subUnsort(vector<int> &A) {
    int i = 0;
    int n = A.size();
    while(i < n-1 && A[i] <= A[i+1]){
        i++;
    }
    if(i == n-1){
        return {-1};
    }
    int j = n-1;
    while(j > 0 && A[j] >= A[j-1]){
        j--;
    }
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    for(int k =i ; k <= j; k++){
        minimum = min(minimum,A[k]);
        maximum = max(maximum,A[k]);
    }
    i--;
    while(i >= 0 && minimum < A[i]){
        i--;
    }
    j++;
    while(j < n && maximum > A[j]){
        j++;
    }
    vector<int>v{i+1,j-1};
    return v;
}
