int xdir[8] = {1,1,0,-1,-1,-1,0,1};
int ydir[8] = {0,1,1,1,0,-1,-1,-1};
bool incircle(int x,int y, int n,int r,vector<int>&xc,vector<int>&yc){
    for(int i = 0; i < n; i++){
        if((xc[i]-x)*(xc[i]-x) + (yc[i]-y)*(yc[i]-y) <= r*r){
            return true;
        }
    }
    return false;
}
bool helper(int x,int y,int &A, int &B, int &N, int &r, vector<int> &xc, vector<int> &yc, map<pair<int,int>,bool>&m){

    if(x == A-1 && y == B-1){
        return true;
    }

    if(x < 0 || y < 0 || x >= A || y >= B || m[{x,y}] == true|| incircle(x,y,N,r,xc,yc) ){
        return false;
    }

    m[{x,y}] = true;
    for(int i = 0; i < 8; i++){
        int nr = x + xdir[i];
        int nc = y + ydir[i];
        if(helper(nr,nc,A,B,N,r,xc,yc,m)){
            return true;
        }
    }
    m[{x,y}] = false;
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    map<pair<int,int>,bool>m;
    if(helper(0,0,A,B,C,D,E,F,m)){
        return "YES";
    }
    return "NO";
}
