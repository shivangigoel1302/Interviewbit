vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<vector<int>>pq;
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());

    int n = A.size();
    for(int i = 0; i < B.size(); i++){
        pq.push({A[0] + B[i],0,i});
    }
    vector<int>ans;
    while(ans.size() < n){
        auto x = pq.top();
        pq.pop();
        int sum = x[0];
        int i = x[2];
        int j = x[1];
        ans.push_back(sum);
        pq.push({A[j+1]+B[i],j+1,i});
    }
    return ans;

//     vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
// 	priority_queue<pair<int, pair<int, int> > > hp;
// 	set<pair<int, int> > S;
// 	int n = A.size();
// 	sort(A.begin(), A.end());
// 	sort(B.begin(), B.end());

// 	hp.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
// 	S.insert(make_pair(n-1, n-1));

// 	vector<int> ans;
// 	int k=n;
// 	while(k--){
// 		pair<int, pair<int, int> > top = hp.top();
// 		hp.pop();
// 		ans.push_back(top.first);
// 		int L = top.second.first;
// 		int R = top.second.second;

// 		if( R>0 && L>=0  && S.find(make_pair(L,R-1)) == S.end() ){
// 			hp.push(make_pair(A[L]+B[R-1], make_pair(L,R-1)));
// 			S.insert(make_pair(L,R-1));
// 		}
// 		if( R>=0  && L>0 && S.find(make_pair(L-1, R))==S.end()){
// 			hp.push(make_pair(A[L-1]+B[R], make_pair(L-1,R)));
// 			S.insert(make_pair(L-1, R));
// 		}
// 	}
// 	return ans;
// }
}
