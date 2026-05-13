class Solution {
public:
    bool checkIncreasing(vector<int>& nums){
        for(int i=0;i<nums.size()-1;i++) if(nums[i]>nums[i+1]) return false;
        return true;
    }

    bool checkDecreasing(vector<int>& nums){
        for(int i=0;i<nums.size()-1;i++) if(nums[i]<nums[i+1]) return false;
        return true;
    }

    bool isMonotonic(vector<int>& nums) {

        if(nums.size()<=2) return true;

        if(nums[0]>nums[1]) return checkDecreasing(nums);
        else if(nums[0]<nums[1]) return checkIncreasing(nums);
        else{
            int i=0;
            while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;

            if(i==nums.size()-1) return true;

            if(nums[i]<nums[i+1]) return checkIncreasing(nums);
            else return checkDecreasing(nums);
        }
        return true;
    }
};