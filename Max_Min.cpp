pair<int,int> helper(vector<int>&A,int i,int j){
    if(i == j){
        return {A[i],A[i]};
    }
    if(i == j-1){
        return {min(A[i],A[j]),max(A[i],A[j])};
    }
    int mid = (i+j)/2;
    pair<int,int>l = helper(A,i,mid);
    pair<int,int>r = helper(A,mid+1,j);
    return {min(l.first,r.first),max(l.second,r.second)};
}
int Solution::solve(vector<int> &A) {
    pair<int,int>ans = helper(A,0,A.size()-1);
   return ans.first + ans.second;
}
