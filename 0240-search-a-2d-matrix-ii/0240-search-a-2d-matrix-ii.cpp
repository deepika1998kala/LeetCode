class Solution {
public:
/*
    //Using the Better approach than the Brute Force approach 
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
*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*int m = matrix.size();
        for(int i=0;i<m;i++){
            if(binarySearch(matrix[i], target)==true){
                return true;
            }           
        }
        return false;*/

        //Optimal Approach 
        //Here we can use any corner 
        // i) Top - Right 
        // ii) Bottom - Left 
        //But You can not use the other 2 corners
        //Here I am Using the i)
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n-1;
        while(row<m && col>=0){
            if(matrix[row][col]<target){
                row++;
            }
            else if(matrix[row][col]>target){
                col--;
            }else{
                return true;
            }
        }
        return false;
    }
};