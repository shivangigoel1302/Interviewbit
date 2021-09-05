vector<string> Solution::fullJustify(vector<string> &A, int B) {
    int n = A.size();
    vector<int>length(n);
    for(int i = 0; i < n; i++){
        length[i] = A[i].length();
    }
    vector<string>ans;
    for(int i = 0; i < n;){
        int j = i;
        int cnt = 0;
        int sum = 0;
        while(j < n && sum + length[j] <= B){
            sum += length[j] + 1;
            j++;
            cnt++;
        }

        if(j == n){
            string temp ="";
            for(int k = 0; k < cnt-1; k++){
                temp += A[i+k];
                temp += " ";
            }
            temp += A[i + cnt -1];
            while(temp.size() != B){
                temp += " ";
            }
            ans.push_back(temp);
            i = j;
            continue;
        }
        int leftspaces = B;
        for(int k = 0; k < cnt; k++){
            leftspaces -= length[i+k];
        }

        if(cnt > 1){

            vector<int>spaces(cnt-1,0);
            int s = 0;
            while(leftspaces != 0){
                spaces[s] ++;
                leftspaces--;
                s++;
                if(s == cnt-1){
                    s = 0;
                }
            }
            string temp = "";
            for(int k = 0; k < cnt-1; k++){
                temp += A[i+k];
                for(int a = 0; a < spaces[k]; a++){
                    temp += " ";
                }
            }
            temp += A[i+cnt-1];
            ans.push_back(temp);
        }
        else{
            string temp = "";
            temp += A[i];
            while(temp.size() != B){
                temp += " ";
            }
            ans.push_back(temp);
        }
        i = j;
    }
    return ans;

}
