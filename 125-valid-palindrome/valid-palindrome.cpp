    class Solution {
    public:
        bool isPalindrome(string s) {
            // int p=0,q=s.length()-1;
            // while(p<=q){
            //     if(!isalnum(s[p])){
            //         p++;
            //         continue;
            //     }
            //     if(!isalnum(s[q])){
            //         q--;
            //         continue;
            //     }
            //     if(tolower(s[p])!=tolower(s[q])) return false;
            //     p++;
            //     q--;
            // }
            // return true;

            int i=0, j=s.length()-1;
            while(i<j){
                if(!isalnum(s[i]) || s[i]==' ') {i++;continue;}
                if(!isalnum(s[j]) || s[j]==' ') {j--;continue;}
                if(tolower(s[i])!=tolower(s[j])) return false;
                i++;
                j--;
            }
            return true;
        }
    };