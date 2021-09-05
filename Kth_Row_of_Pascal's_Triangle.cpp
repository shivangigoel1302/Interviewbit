vector<int> Solution::getRow(int A) {

    vector<int>temp;
    temp.push_back(1);
    if(A == 0){
        return temp;
    }
    while(A--){
        vector<int>curr;
        curr.push_back(1);
        for(int i = 0; i < temp.size() -1; i++){
            int a = temp[i] + temp[i+1];
            curr.push_back(a);
        }
        curr.push_back(1);
        temp = curr;
    }
    return temp;
}
