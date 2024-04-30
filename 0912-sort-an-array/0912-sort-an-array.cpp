class Solution {
public:
    void quickSort(vector<int>& nums, int start, int end){
        if (start >= end) return;

        // Choose pivot as the middle element
        int pivot = nums[start + (end - start) / 2];
        
        // Partitioning
        int left = start, right = end;
        while (left <= right) {
            while (nums[left] < pivot) left++;
            while (nums[right] > pivot) right--;
            if (left <= right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        
        // Recursively sort the partitions
        quickSort(nums, start, right);
        quickSort(nums, left, end);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        quickSort(nums, start, end);
        return nums;
    }
};