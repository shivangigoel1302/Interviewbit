string Solution::countAndSay(int A) {
    string s = "";
    string temp = "1";
    A--;
    while(A > 0){
        for(int i = 0; i < temp.size();){
            char c= temp[i];
            int cnt = 0;
            int j = i;
            while(j < temp.size() && temp[j] == c){
                j++;
                cnt++;
            }
            s += to_string(cnt);
            s += c;
            i = j;
        }
        temp = s;
        s="";
        A--;
    }
    return temp;
}
