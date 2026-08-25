class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<=n;i++) if(find(nums.begin(),nums.end(),k*i)==nums.end()) return k*i;
        return k*(n+1);
    }
};