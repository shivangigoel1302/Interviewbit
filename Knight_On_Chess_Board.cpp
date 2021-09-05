int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int moves = 0;
    queue<int>q;
    int xdir[8] = {2,1,-1,-2,-2,-1,1,2};
    int ydir[8] = {1,2,2,1,-1,-2,-2,-1};
    unordered_map<int,bool>visited;
    q.push((C-1)*B+(D-1));
    visited[{(C-1)*B+(D-1)}] = true;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int cor = q.front();
            q.pop();
            // visited[cor] = true;
            for(int i = 0; i < 8; i++){
                int nr = xdir[i] + cor/B;
                int nc = xdir[i] + cor%B;
                if(nr >=0 && nc >=0 && nr < A && nc < B && !visited[nr*B+nc]){
                    if(nr == E-1 && nc == F-1){
                        return moves+1;
                    }
                    q.push({nr*B+nc});
                    visited[nr*B+nc] = true;
                }
            }
        }
        moves++;
    }
    return -1;
}
