class Solution {
public:
    // long long factorial(int n){
    //     long long result = 1;
    //     for (int i = 2; i <= n; i++) {
    //         result *= i;
    //     }
    //     return result;
    // }

    int numTrees(int n) {

        //Cn = (n+1)!/(n!(2n)!)
        long long catalan = 1;
        for (int i = 0; i < n; ++i) {
            catalan = catalan * 2 * (2 * i + 1) / (i + 2);
        }
        return static_cast<int>(catalan);
    }
};
