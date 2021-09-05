 bool isAnagram(string a, string b){

        // Your code here
        vector<int>freq(26,0);
        for(int i = 0; i < a.size(); i++){
            freq[a[i]-'a']++;
        }
        for(int i = 0; i < b.size(); i++){
            freq[b[i]-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
