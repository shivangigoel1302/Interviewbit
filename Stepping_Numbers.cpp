vector<int> Solution::stepnum(int A, int B) {
    queue<int>q;
    for(int i = 1; i <=9; i++){
        q.push(i);
    }
    vector<int>ans;
    if(A == 0){
        ans.push_back(0);
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x >= A && x <= B){
            ans.push_back(x);
        }
        else if(x > B){
            continue;
        }
        string s = to_string(x);
        int a = s[s.size()-1]-'0';
        if(a != 9){
            a++;
            string temp = s+ to_string(a);
            q.push(stoi(temp));
            a--;
        }
        if(a != 0){
            a--;
            string temp = s+ to_string(a);
            q.push(stoi(temp));
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
