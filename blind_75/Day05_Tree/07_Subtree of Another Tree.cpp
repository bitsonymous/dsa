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
    bool isMatching(TreeNode* root, TreeNode* subRoot){
        if(root==NULL and subRoot == NULL) return true;
        if(root==NULL or subRoot == NULL) return false;

        if(root->val != subRoot->val) return false;
        return isMatching(root->left , subRoot->left) && isMatching(root->right , subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        bool ans = false;
        if(root->val == subRoot->val){
            ans = isMatching(root, subRoot);
        }
        return ans || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};