class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int ans=0;
        // int minn=INT_MAX;
        // for(int i=0;i<prices.size();i++){
        //     minn=min(minn,prices[i]);
        //     ans=max(prices[i]-minn,ans);
        // }
        // return ans;

        // int ans=0;
        // for(int i=0;i<prices.size();i++){
        //     int maxx=*max_element(prices.begin()+i,prices.end());
        //     ans=max(ans,maxx-prices[i]);
        // }
        // return ans;


        int minn=INT_MAX;
        int maxx=INT_MIN;
        for(int i=0;i<prices.size();i++){
            minn=min(minn,prices[i]);
            maxx=max(prices[i]-minn,maxx);
        }
        return maxx;
    }
};