class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minn=INT_MAX;
        bool odd=false;
        for(auto i:nums1){
            if(i%2!=0){
                odd=true;
                minn=min(minn,i);
            }
        }
        if(!odd) return true;

        bool possible=true;
        for(auto i:nums1){
            if(i%2==0 && i<=minn) return false;
        }

        return true;
    }
};