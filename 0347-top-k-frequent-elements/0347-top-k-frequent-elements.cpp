class Solution {
public:
/*
    static bool compare(const pair<int,int> &a, const pair<int,int> &b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<pair<int, int>> v(mpp.begin(), mpp.end());
        sort(v.begin(), v.end(), compare);
        vector<int> ans;

        for(auto it: v){
            if(k==0) break;
            k--;
            ans.push_back(it.first);
        }
        return ans;
    }*/

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it: mpp){
            pq.push({it.second, it.first});
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};