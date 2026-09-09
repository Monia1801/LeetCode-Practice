class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long init=1000;
        while(init<=n){
            ans+=(n-init+1);
            init*=1000;
        }
        return ans;
    }
};