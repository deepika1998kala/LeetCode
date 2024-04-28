class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) {
        // Using Bit manipulation
        int bucket1=0;
        int bucket2=0;
        long long XOR=0;
        for(int i=0;i<arr.size();i++){
            XOR^=arr[i];
        }
        int bit=0;
        long long rightMostBitOne=(XOR & (XOR-1)) ^ XOR;
        for(int i=0;i<arr.size();i++){
            if((arr[i] & rightMostBitOne)){
                bucket1^=arr[i];
            }else{
                bucket2^=arr[i];
            }
        }
        
        return {bucket1, bucket2};
        
        
        // return {unique1, unique2};

        //Using Extra Space  // TC=O(nlogm + m), SC=O(m)
        // unordered_map<int,int> mpp;
        // vector<int> ans;
        // for(int i=0;i<nums.size();i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto it: mpp){
        //     if(it.second!=2){
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;
    }
};