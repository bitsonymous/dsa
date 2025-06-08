/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        if(root->val >= p->val && root->val <= q->val) return root;

        if(p->val < root->val && q->val < root->val){
            return LCA(root->left, p, q);
        }
        if(p->val > root->val && q->val > root->val){
            return LCA(root->right, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* f, *s;
        if(p->val<q->val){
            f = p;
            s = q;
        }else{
            f = q;
            s = p;
        }
        return LCA(root, f, s);
    }
};