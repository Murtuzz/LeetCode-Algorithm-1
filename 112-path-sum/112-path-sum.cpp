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
    void traversal (TreeNode* root, int targetSum, int sum, bool &flag) {
        if (root == nullptr || flag) {
            return;
        }
        sum += root->val;
        
        if(root->left == nullptr &&  root->right == nullptr && targetSum == sum) {
            flag = true;
            return;
        }
        traversal (root->left,targetSum, sum, flag);
        traversal (root->right,targetSum, sum, flag);
    }
    
    bool hasPathSum(TreeNode* root, int &targetSum) {
        bool flag = false; 
        traversal (root, targetSum, 0, flag);
        return flag;
    }
};