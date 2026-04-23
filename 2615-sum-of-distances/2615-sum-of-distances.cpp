class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> res(nums.size());
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        for(auto i:mp){
            cout<<i.first<<":";
            for(auto j:i.second) cout<<j<<" ";
            cout<<endl;
        }
        //CORRECT BUT GIVES TLE
        // for(int i=0;i<nums.size();i++){
        //     int sum=0;
        //     for(auto j:mp[nums[i]]) sum+=abs(j-i);
        //     res[i]=sum;
        // }

        for(auto i:mp){
            vector<int>a=i.second;
            int n=a.size();
            long long total=0;
            for(auto k:a) total+=k;

            long long prefix=0;
            for(int j=0;j<n;j++){
                long long left=1LL*j*a[j]-prefix;
                long long right=(total-prefix-a[j])-1LL*(n-j-1)*a[j];  

                res[a[j]]=left+right;
                prefix+=a[j];
            }
        }
        return res;
    }
};