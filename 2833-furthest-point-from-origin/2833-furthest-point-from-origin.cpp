class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntL=0,cntR=0;
        for(auto i:moves){
            if(i=='L') cntL++;
            else if(i=='R') cntR++;
        }
        int cntU=moves.length()-cntL-cntR;
        return abs(cntL-cntR)+cntU;
        // int pnt=0;
        // if(cntL==cntR){
        //     for(auto i:moves){
        //         if(i=='L') pnt--;
        //         else pnt++;
        //     }
        //     return pnt;
        // }
        // else{
        //     if(cntL>cntR){
        //         for(auto i:moves){
        //             if(i=='R') pnt++;
        //             else pnt--;
        //         }
        //         return abs(pnt);
        //     }
        //     else{
        //         for(auto i:moves){
        //             if(i=='L') pnt--;
        //             else pnt ++;
        //         }
        //         return pnt;
        //     }
        // }
        // return 0;
    }
};