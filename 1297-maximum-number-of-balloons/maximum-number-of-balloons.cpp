class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0;
        for(auto i:text){
            if(i=='b') b++;
            else if(i=='a') a++;
            else if(i=='l') l++;
            else if(i=='o') o++;
            else if(i=='n') n++;
        }
        // int cnt=0;
        // while(b>0 && a>0 && l>0 && o>0 && n>0){
        //     b-=1;
        //     a-=1;
        //     n-=1;
        //     if(l<2 || o<2) return cnt;
        //     if(l>1) l-=2;
        //     if(o>1) o-=2;
        //     cnt++;
        // }
        // return cnt;

        return min({b,a,l/2,o/2,n});
    }
};