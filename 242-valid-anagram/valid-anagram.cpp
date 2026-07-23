class Solution {
public:
    bool isAnagram(string s, string t) {
        // unordered_map<char,int> ch;
        // for(auto i:s) ch[i]++;
        // for(auto i:t) ch[i]--;
        // for(auto i:ch){
        //     if(i.second!=0) return false;
        // }
        // return true;

        unordered_map<int,int> mp;
        for(auto i:s) mp[i]++;
        for(auto i:t) mp[i]--;
        for(auto i:mp) if(i.second!=0) return false;
        return true;
    }
};