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
    void traversal (TreeNode* root, int val, int depth){
        if(!root){ 
            return;
        }
        
        if (depth == 1) {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
            return;
        }
        traversal(root->left,val, depth - 1);
        traversal(root->right,val, depth - 1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if (depth == 1) {
            TreeNode* new_root = new TreeNode(val, root, nullptr);
            return new_root;
        }
        
        traversal(root, val, depth - 1);
        
        return root;
    }
};