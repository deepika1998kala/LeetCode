class Solution {
public:
    int countBit(int i){
        int count=0;
        while(i>0){
            if(i%2==1){
                count++;
            }
            i=i>>1;
        }
        return count;
    }
    string format(int i, int j){
        
        if (j < 10) {
            return to_string(i) + ":0" + to_string(j);
        }
        return to_string(i) + ":" + to_string(j);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        if(turnedOn >= 9) return ans;
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                if(countBit(i)+countBit(j)==turnedOn){
                    ans.push_back(format(i,j));
                }
            }
        }
        return ans;
    }
};