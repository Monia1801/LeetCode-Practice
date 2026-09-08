class Solution {
public:
    int countCommas(int n) {
        int init=1000;
        int ans=0;
        while(init<=n){
            ans+=(n-init+1);
            init*=1000;
        }
        return ans;
    }
};