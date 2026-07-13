class Solution {
public:
    vector<vector<int>> res;
    void subset(vector<int>& temp,int idx,vector<int> nums){
        if(idx>nums.size()-1){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subset(temp,idx+1,nums);

        temp.pop_back();
        subset(temp,idx+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        subset(temp,0,nums);
        return res;
    }
};