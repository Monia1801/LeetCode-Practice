class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0, res=0;
        for(auto i:gain){
             res+=i;
            ans=max(ans,res);
        }
        return ans;
    }
};