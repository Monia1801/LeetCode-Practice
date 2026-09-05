class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>s(n);
        s[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            s[i]=min(s[i+1],nums[i]);
        }
        int p=INT_MIN;
        for(int i=0;i<n;i++){
            p=max(p,nums[i]);
            if(p-s[i]<=k) return i;
        }
        return -1;
    }
};