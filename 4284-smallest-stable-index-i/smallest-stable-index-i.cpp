class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int minn=*max_element(nums.begin(),nums.begin()+i+1);
            int maxx=*min_element(nums.begin()+i,nums.end());
            int score=minn-maxx;
            if(score<=k) res=min(res,i);
        }
        return res==INT_MAX? -1:res;
    }
};