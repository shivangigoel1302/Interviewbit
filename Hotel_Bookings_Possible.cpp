bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int,int>>v;
    for(int i = 0; i < arrive.size(); i++){
        v.push_back({arrive[i],depart[i]});
    }
    sort(v.begin(),v.end(),[](pair<int,int>p1,pair<int,int>p2){
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    });
    priority_queue<int,vector<int>,greater<int>>p;
    int j = 0;
    while(j < arrive.size()){
        while(!p.empty() && p.top() <= v[j].first){
            p.pop();
        }
        if(v[j].first == v[j].second){
            j++;
            continue;
        }
        p.push(v[j].second);
        if(p.size() > K){
            return 0;
        }
        j++;
    }
    return 1;
}
