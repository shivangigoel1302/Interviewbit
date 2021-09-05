void assign(int &x,int &y,vector<string>C,int l){
    int r = l/(C[0].size());
    int c = l%(C[0].size());
    if(C[r][c] == 'R'){
        x = r;
        y = c+1;
        return;
    }
    if(C[r][c] == 'L'){
        x = r;
        y = c-1;
        return;
    }
    if(C[r][c] == 'U'){
        x = r-1;
        y = c;
        return;
    }
    if(C[r][c] == 'D'){
        x = r+1;
        y = c;
        return;
    }
    return;
}
int Solution::solve(int A, int B, vector<string> &C) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<vector<int>>dist(C.size(),vector<int>(C[0].size(),INT_MAX));
    unordered_map<int,bool>visited;
    dist[0][0] = 0;
    pq.push({0,0});
    int xdir[4] = {1,0,-1,0};
    int ydir[4] = {0,1,0,-1};
    while(!pq.empty() && !visited[(A-1)*B + (B-1)]){
       auto x = pq.top();
       pq.pop();
       if(visited[x.second]){
           continue;
       }
       visited[x.second] = true;
       int dx,dy;
       assign(dx,dy,C,x.second);

       for(int i = 0; i < 4; i++){
           int nr = x.second/B + xdir[i];
           int nc = x.second%B + ydir[i];
           if(nr >=0 && nc >=0 && nr < A && nc < B && !visited[nr*B+nc]){
               if(nr == dx && nc == dy && dist[nr][nc] > dist[x.second/B][x.second%B]){
                   dist[nr][nc] = dist[x.second/B][x.second%B];
                   pq.push({0,nr*B+nc});
               }
               else if(dist[nr][nc] > dist[x.second/B][x.second%B]+1){
                   dist[nr][nc] = dist[x.second/B][x.second%B]+1;
                   pq.push({dist[nr][nc],nr*B+nc});
               }
           }
       }
    }
    return dist[A-1][B-1];
}
