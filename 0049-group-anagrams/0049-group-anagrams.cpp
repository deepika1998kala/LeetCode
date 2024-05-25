class Solution {
public:
    static bool compare(const pair<string, vector<string>> &a, const pair<string, vector<string>> &b){
        return a.second.size() < b.second.size();
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for(int i=0;i<strs.size();i++){
            string str_sort=strs[i];
            sort(str_sort.begin(), str_sort.end());
            mpp[str_sort].push_back(strs[i]);
        }
        vector<pair<string, vector<string>>> v(mpp.begin(), mpp.end());
        sort(v.begin(), v.end(), compare); 
        vector<vector<string>> vec;
        for(auto it: v){
            vec.push_back(it.second);
        }
        return vec;
    }
};