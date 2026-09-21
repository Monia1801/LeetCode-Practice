class Solution {
public:
    int reverseDegree(string s) {
        int res=0;
        for(int i=1;i<=s.length();i++){
            int ascii='z'-s[i-1]+1;
            res+=(i*ascii);
            // cout<<i<<" "<<ascii<<" ";
        }
        return res;
    }
};