int Solution::majorityElement(const vector<int> &A) {
    int cnt = 0;
    int ele = INT_MIN;
    for(int i = 0; i < A.size(); i++){
        if(ele == INT_MIN || A[i] == ele){
            ele = A[i];
            cnt++;
        }
        else{
            cnt--;
            if(cnt == 0){
                ele = A[i];
                cnt = 1;
            }
        }
    }
    int freq = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == ele){
            freq++;
        }
    }
    int n = A.size();
    if(freq >= (n)/2){
        return ele;
    }
    return -1;
}
