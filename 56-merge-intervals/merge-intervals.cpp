class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back({intervals[0][0],intervals[0][1]});

        for(int i=1;i<intervals.size();i++){
            auto prev=res.back();

            if(intervals[i][0]<=prev[1]) {
                res.pop_back();
                res.push_back({prev[0],max(prev[1],intervals[i][1])});
            }
            else res.push_back({intervals[i][0],intervals[i][1]});

        }
        return res;
    }
};