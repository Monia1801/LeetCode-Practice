class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntL=0,cntR=0;
        for(auto i:moves){
            if(i=='L') cntL++;
            else if(i=='R') cntR++;
        }
        int pnt=0;
        int cntU=moves.length()-cntL-cntR;
        if(cntL==cntR){
            for(auto i:moves){
                if(i=='L') pnt--;
                else pnt++;
            }
            return pnt;
        }
        else{
            if(cntL>cntR){
                for(auto i:moves){
                    if(i=='R') pnt++;
                    else pnt--;
                }
                return abs(pnt);
            }
            else{
                for(auto i:moves){
                    if(i=='L') pnt--;
                    else pnt ++;
                }
                return pnt;
            }
        }
        return 0;
    }
};