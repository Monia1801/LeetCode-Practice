class Solution {
public:
    vector<vector<int>> res;
    void per(vector<int>& temp,vector<int>& nums,vector<bool> visited){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            visited[i]=true;
            temp.push_back(nums[i]);
            per(temp,nums,visited);
            visited[i]=false;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<vector<int>> v;
        // sort(nums.begin(),nums.end());
        // do{
        //    v.push_back(nums); 
        // }
        // while(next_permutation(nums.begin(),nums.end()));
        // return v;

        vector<int> temp;
        vector<bool> visited(nums.size(),false);
        per(temp,nums,visited);
        return res;
    }
};