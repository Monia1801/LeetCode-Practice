class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string,vector<string>> m;
        // for(auto i:strs){
        //     string org=i;
        //     sort(i.begin(),i.end());
        //     m[i].push_back(org);
        // }

        // vector<vector<string>> ans;
        // for(auto i:m){
        //     ans.push_back(i.second);
        // }
        
        // return ans;

        map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string org=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(org);
        }

        vector<vector<string>> res;
        for(auto j:mp){
            res.push_back(j.second);
        }
        return res;
    }
};