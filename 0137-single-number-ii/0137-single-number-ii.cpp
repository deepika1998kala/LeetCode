class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int newNum=0;
        for(int i=0;i<32;i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                if((nums[j]>>i)&1){
                    count++;
                }
            }
            if(count%3!=0){
                newNum=newNum | (1<<i);
            }
        }
        return newNum;
    }
};