/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    set<int> ans;
    void inOrder(TreeNode* root) {
        if(root==NULL) return;

        ans.insert(root->val);
        inOrder(root->left);
        
        inOrder(root->right);
        
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL) return -1;
        inOrder(root);
        if (ans.size() < 2) return -1;
        auto it = ans.begin();
        advance(it, 1);  // Move iterator to the second element
        return *it;
    }
};