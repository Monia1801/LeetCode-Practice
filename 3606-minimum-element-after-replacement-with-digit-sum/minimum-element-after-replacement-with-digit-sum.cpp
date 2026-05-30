class Solution {
public:
    int minElement(vector<int>& nums) {
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            string n=to_string(nums[i]);
            int size=n.length();
            while(size--) sum+=(n[size]-'0');
            res=min(sum,res);
        }
        return res;
    }
};