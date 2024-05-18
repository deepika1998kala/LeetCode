class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(nums.size()<4) return ans;
        for(size_t i=0;i<nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(size_t j=i+1;j<nums.size()-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                size_t low = j + 1;
                size_t high = nums.size() - 1;
                while(low<high){
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[low] + nums[high];
                    
                    if(sum<target){
                        low++;
                    }
                    else if(sum > target){
                        high--;
                    }else{
                        ans.push_back({nums[i],nums[j], nums[low], nums[high]});
                        while(low<high && nums[low] == nums[low + 1]){
                            low++;
                        }
                        while(low<high && nums[high] == nums[high - 1]){
                            high--;
                        }
                        low++;
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};