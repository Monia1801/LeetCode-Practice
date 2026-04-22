#include<algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());

        int n=nums.size();
        int left=n-2;
        while(left>=0 && nums[left]>=nums[left+1]) left--;
        
        if(left>=0){
        int idx=n-1;    
        while(nums[idx]<=nums[left]) idx--;
        swap(nums[left],nums[idx]);
        }
        
        reverse(nums.begin()+left+1,nums.end());
    }
};