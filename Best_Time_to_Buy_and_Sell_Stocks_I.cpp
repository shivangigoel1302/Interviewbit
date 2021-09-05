int Solution::maxProfit(const vector<int> &A) {
    if(A.empty()){
        return 0;
    }
    int curr = A[0];
    int profit = 0;
    for(int i = 1; i < A.size(); i++){
        if(A[i] < curr){
            curr = A[i];
        }
        profit = max(profit,A[i] - curr);
    }
    return profit;
}
