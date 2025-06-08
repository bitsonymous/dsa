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
    // void invert(TreeNode* root, TreeNode* &ans){
    //     if(root == NULL){
    //         return;
    //     }
    //     ans = new TreeNode(root->val);
    //     invert(root->left, ans->right);
    //     invert(root->right, ans->left);
    // }
    TreeNode* invertTree(TreeNode* root) {
        // TreeNode* ans = nullptr;
        // invert(root, ans);
        // return ans;
        if(root == NULL) return root;
        swap(root->left , root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};