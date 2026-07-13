class Solution {
public:
    set<vector<int>> res;
    void subsets(vector<int>& temp,int idx,vector<int>& nums){
        if(idx>nums.size()-1){
            vector<int> t(temp.begin(),temp.end());
            sort(t.begin(),t.end());
            res.insert(t);
            return;
        }
        temp.push_back(nums[idx]);
        subsets(temp,idx+1,nums);
        temp.pop_back();
        subsets(temp,idx+1,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        subsets(temp,0,nums);
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;
    }
};