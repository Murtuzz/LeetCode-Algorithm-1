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
    void traversal(TreeNode* root1, TreeNode* root2) {
        if (!root1->left && !root1->right && !root2->left && !root2->right) {
            return;
        } 
        
        if (root1->left && root2->left) {
            root1->left->val += root2->left->val;
        } else if (root2->left) {
            root1->left = new TreeNode(root2->left->val); 
        }
        
        if (root1->right && root2->right) {
            root1->right->val += root2->right->val;
        } else if (root2->right) {
            root1->right = new TreeNode(root2->right->val); 
        }
        if (root2->left) { 
            traversal(root1->left,root2->left);
        }
        if (root2->right) {
            traversal(root1->right,root2->right);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        } else if (!root2) {
            return root1;
        }
        
        root1->val += root2->val;
        traversal(root1, root2);
        return root1;
    }
};