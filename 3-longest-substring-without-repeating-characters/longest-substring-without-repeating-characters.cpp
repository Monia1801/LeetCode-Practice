class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // vector<int> hash(255,-1);
        // int n=s.length(),l=0,r=0;
        // int ans=0;
        // while(r<n){
        //     if(hash[s[r]]!=-1){
        //         if(hash[s[r]]>=l) l=hash[s[r]]+1;
        //     }
        //     ans=max(ans,r-l+1);
        //     hash[s[r]]=r;
        //     r++;
        // }
        // return ans;

        // if(s.length()==1) return 1;
        int i=0,j=0,ans=0;
        unordered_map<char,int> mp;
        while(j<s.length()){
            if(mp.find(s[j])!=mp.end()) i=max(i,mp[s[j]]+1);
            mp[s[j]]=j;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};