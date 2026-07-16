class Solution {
public:
    int ways(int n,vector<int>& dp){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        dp[n]=ways(n-1,dp)+ways(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
//         if(n==1) return 1;
//         int a=0,b=1,fib=0;
//         for(int i=2;i<=n+1;i++){
//             fib=a+b;
//             a=b;
//             b=fib;
//         }
// return b;
        vector<int> dp(n+1,-1);
        return ways(n,dp);
    }
};