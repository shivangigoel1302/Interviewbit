int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int curr=0;
    int idx = 0;
    int fuelreq = 0;
    for(int i = 0; i < A.size(); i++){
        curr += A[i];
        if(curr >= B[i]){
            curr -= B[i];
            continue;
        }
        else{
            fuelreq += B[i] - curr;
            idx = i+1;
            curr = 0;
        }
    }
    if(curr >= fuelreq){
        return idx;
    }
    return -1;
}
