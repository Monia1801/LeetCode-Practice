class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long asc=0,desc=0;
        int i=0;
        for(i=0;i<nums.size();i++){
            asc+=nums[i];
            if(nums[i+1]<nums[i]) break;
        }

        for(int j=i;j<nums.size();j++) desc+=nums[j]; 

        if(asc>desc) return 0;
        else if(asc<desc) return 1;
        return -1;
    }
};