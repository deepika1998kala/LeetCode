class Solution {
public:
    bool isPalindrome(const string &s) {
        int low = 0;
        int high = s.size() - 1;
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> mpp;

        // Step 1: Store the reverse of each word with its index
        for (int i = 0; i < words.size(); i++) {
            string revWord = words[i];
            reverse(revWord.begin(), revWord.end());
            mpp[revWord] = i;
        }

        // Step 2: Check each word and its possible partitions
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            for (int j = 0; j <= word.size(); j++) {
                string left = word.substr(0, j);
                string right = word.substr(j);

                // If left part is a palindrome, check if there's a reversed right part in the map
                if (isPalindrome(left) && mpp.find(right) != mpp.end() && mpp[right] != i) {
                    ans.push_back({mpp[right], i});
                }

                // If right part is a palindrome and left is not empty, check if there's a reversed left part in the map
                if (!left.empty() && isPalindrome(right) && mpp.find(left) != mpp.end() && mpp[left] != i) {
                    ans.push_back({i, mpp[left]});
                }
            }
        }

        // Special case for empty string
        if (mpp.find("") != mpp.end()) {
            int blankIndex = mpp[""];
            for (int i = 0; i < words.size(); i++) {
                if (i != blankIndex && isPalindrome(words[i])) {
                    ans.push_back({i, blankIndex});
                    ans.push_back({blankIndex, i});
                }
            }
        }

        // Remove duplicates if any (though the logic aims to avoid them)
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;

        //Brute Force Approach
        // for(int i=0;i<words.size();i++){
        //     for(int j=0;j<words.size();j++){
        //         string concatenated=words[i]+words[j];
        //         string reversed=concatenated;
        //         reverse(reversed.begin(), reversed.end());
        //         if( i!=j && concatenated == reversed){
        //             ans.push_back({i,j});
        //         }
        //     }
        // }
        
    }
};