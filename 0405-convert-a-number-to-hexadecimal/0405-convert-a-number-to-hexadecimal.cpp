class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hex_digits = "0123456789abcdef";
        string result = "";
        unsigned int unsigned_num = num; 
        
        while (unsigned_num != 0) {
            int rem=unsigned_num%16;
            result=result + hex_digits[rem];
            unsigned_num=unsigned_num/16;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};