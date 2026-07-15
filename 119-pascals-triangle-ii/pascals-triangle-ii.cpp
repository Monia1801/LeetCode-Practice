class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> res;
        if(n==0) return {1};
        if(n==1) return {1,1};

        res.push_back({1});
        res.push_back({1,1});
        vector<int> prev;
        for(int i=2;i<=n;i++){
            prev=res[i-1];
            vector<int> temp(i+1,0);
            temp[0]=1;
            temp[i]=1;
            for(int j=1;j<i;j++) temp[j]=prev[j]+prev[j-1];
            res.push_back(temp);
        }
        return res[res.size()-1];
    }
};