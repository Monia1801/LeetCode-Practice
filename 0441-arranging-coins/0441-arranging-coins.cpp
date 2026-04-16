class Solution {
public:
    int arrangeCoins(int n) {
        int cnt=0;
        int i=1;
        while(n>=i){
            cnt++;
            n-=i;
            i++;
        }
        return cnt;
    }
};