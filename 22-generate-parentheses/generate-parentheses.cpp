class Solution {
public:
    void generate(string s,int open,int close,vector<string>& res){
        if(open==0 && close==0){
            res.push_back(s);
            return;
        }
        if(open>0) generate(s+"(",open-1,close,res);
        if(open<close) generate(s+")",open,close-1,res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("",n,n,res);
        return res;
    }
};