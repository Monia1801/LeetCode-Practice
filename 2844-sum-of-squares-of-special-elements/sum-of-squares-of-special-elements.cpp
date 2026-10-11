class Solution {
public:
    int squares(int n){
        return n*n;
    }
    int sumOfSquares(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        cout<<n<<endl;
        for(int i=1;i<=n;i++) if(n%i==0) res+=squares(nums[i-1]);
        return res;
    }
};