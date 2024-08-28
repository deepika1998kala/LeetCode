class Solution {
public:

    bool binarySearch(vector<int>& matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(matrix[mid]<target){
                left = mid + 1;
            }
            else if(matrix[mid]>target){
                right = mid - 1;
            }else{
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        for(int i=0;i<m;i++){
            if(binarySearch(matrix[i], target)==true){
                return true;
            }           
        }
        return false;
    }
};