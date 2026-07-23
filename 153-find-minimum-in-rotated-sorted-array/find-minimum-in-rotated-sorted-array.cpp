class Solution {
public:
    int findMin(vector<int>& nums) {
        // int low=0,high=nums.size()-1;
        // while(low!=high){
        //     int mid=low+(high-low)/2;
        //     if(nums[mid]>nums[high]) low=mid+1;
        //     else high=mid;
        // }
        // return nums[low];

        // int low = 0, high = nums.size() - 1;
        // int ans = INT_MAX;
        // while (low <= high) {
        //     int mid = low + (high - low) / 2;
        //     if (nums[low] <= nums[mid]) {
        //         ans = min(ans, nums[low]);
        //         low = mid + 1;
        //     }
        //     else{//4 5 1 2 3
        //         ans=min(ans,nums[mid]);
        //         high=mid-1;
        //     } 
        // }
        // return ans;


        int low=0,high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            ans=min(ans,nums[mid]);
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid-1; 
        }
        return ans;
    }
};