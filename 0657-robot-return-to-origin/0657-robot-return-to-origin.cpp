class Solution {
public:
    bool judgeCircle(string moves) {
        int Ucnt=0,Dcnt=0,Lcnt=0,Rcnt=0;
        for(auto i:moves){
            if(i=='U') Ucnt++;
            else if(i=='D') Dcnt++;
            else if(i=='L') Lcnt++;
            else Rcnt++;
        }
        return Ucnt==Dcnt && Lcnt==Rcnt;
    }
};