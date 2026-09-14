class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int clen=min(rec1[2],rec2[2])-max(rec1[0],rec2[0]);
        int cbre=min(rec1[3],rec2[3])-max(rec2[1],rec1[1]);

        return clen>0 && cbre>0;
    }
};