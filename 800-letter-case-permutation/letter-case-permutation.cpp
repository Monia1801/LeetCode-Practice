class Solution {
public:
    vector<string> res;
    void per(string& temp, int idx, string s){
        if(idx==s.length()){
            res.push_back(temp);
            return;
        }
        if(isalpha(s[idx])){
            temp+=tolower(s[idx]);
            per(temp,idx+1,s);
            temp.pop_back();

            temp+=toupper(s[idx]);
            per(temp,idx+1,s);
            temp.pop_back();
        }
        else{
            temp+=s[idx];
            per(temp,idx+1,s);
            temp.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        string temp="";
        per(temp,0,s);
        return res;
    }
};