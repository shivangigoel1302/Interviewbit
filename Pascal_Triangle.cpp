vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>>triangle;
    if(A== 0){
        return triangle;
    }
    triangle.push_back({1});
    int row = 0;
    A--;
    while(A > 0){
        vector<int>temp;
        temp.push_back(1);
        for(int i = 0; i < triangle[row].size()-1; i++){
            int a = triangle[row][i] + triangle[row][i+1];
            temp.push_back(a);
        }
        temp.push_back(1);
        triangle.push_back(temp);
        row++;
        A--;
    }
    return triangle;
}
