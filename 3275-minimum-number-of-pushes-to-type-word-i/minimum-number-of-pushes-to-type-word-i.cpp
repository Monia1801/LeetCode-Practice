class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        if(n<=8) return n;
        
        int sets=n/8;
        int m=(sets*(sets+1))/2;
        int extra=n%8;

        return (m*8)+(extra*(sets+1));
    }
};