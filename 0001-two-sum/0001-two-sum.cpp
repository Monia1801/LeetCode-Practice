class Solution {
public:
    vector<int> twoSum(vector<int>& vec, int target) {
    // unordered_map<int,int> cnt;
    // int j=0;
    // for(auto i:vec){
    //     cnt[i]=j;
    //     j++;
    // }
    // vector<int> ans;
    // for(int i=0;i<vec.size();i++){
    //     if(cnt.find(target-vec[i])!=cnt.end() && i != cnt[target-vec[i]]){
    //         ans.push_back(i);
    //         ans.push_back(cnt[target-vec[i]]);
    //         break;
    //     }
    // }
    // return ans;

    vector<pair<int,int>> p;

    for(int i=0;i<vec.size();i++){
        p.push_back({vec[i],i});
    }

    sort(p.begin(),p.end());

    vector<int> ans;
    int left=0,right=vec.size()-1;

    while(left!=right){
        int curr=p[left].first+ p[right].first;
        if(curr==target){
            ans.push_back(p[left].second);
            ans.push_back(p[right].second);
            break;
        }
        else if(curr<target) left++;
        else right--;
    }
    return ans;
    }
};