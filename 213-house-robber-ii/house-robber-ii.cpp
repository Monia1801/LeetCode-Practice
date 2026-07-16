class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(n==3) return max(max(nums[0],nums[1]),nums[2]);
        vector<int> preDp(n),sufDp(n);
        preDp[0]=nums[0];
        preDp[1]=max(preDp[0],nums[1]);

        sufDp[n-1]=nums[n-1];
        sufDp[n-2]=max(sufDp[n-1],nums[n-2]);

        for(int i=2;i<n-1;i++) preDp[i]=max(preDp[i-1],preDp[i-2]+nums[i]);
        for(int i=n-3;i>0;i--) sufDp[i]=max(sufDp[i+1],sufDp[i+2]+nums[i]);

        return max(preDp[n-2],sufDp[1]);

    }
};