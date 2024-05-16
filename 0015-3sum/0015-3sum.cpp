#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    
    void twoSum(vector<int>& nums, int target, int start, vector<int>& arr) {
        int i = start;
        int j = nums.size() - 1;
        
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                res.push_back({arr[0], nums[i], nums[j]});
                int left = nums[i];
                while (i < j && nums[i] == left) i++;
                int right = nums[j];
                while (i < j && nums[j] == right) j--;
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates
            
            int target = -nums[i];
            vector<int>temp;
            temp.push_back(nums[i]);

            twoSum(nums, target, i + 1, temp);
        }
        
        return res;
    }
};
