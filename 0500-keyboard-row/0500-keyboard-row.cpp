class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<set<char>> rows= {{'q','w','e','r','t','y','u','i','o','p'},
                                {'a','s','d','f','g','h','j','k','l'},
                                {'z','x','c','v','b','n','m'}};
        vector<string> res;

        int idx=0;
        for(auto i:words){
            if(rows[0].find(tolower(i[0])) != rows[0].end()) idx=0;
            else if(rows[1].find(tolower(i[0])) != rows[1].end()) idx=1;
            else idx=2;

            bool ans=true;
            for(int j=1;j<i.size();j++){
                if(rows[idx].find(tolower(i[j])) == rows[idx].end()){ ans=false; break;}
            }
            if(ans==true) res.push_back(i);
        }

        return res;
    }
};