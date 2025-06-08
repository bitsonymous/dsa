/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){ 
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL) s.append("#,");
            else s.append(to_string(front->val) + ",");
            if(front!=NULL){
                q.push(front->left);
                q.push(front->right);
            }
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            TreeNode* front = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                front->left = NULL;
            }else{
                front->left = new TreeNode(stoi(str));
                q.push(front->left);
            }

            getline(s, str, ',');
            if(str == "#"){
                front->right = NULL;
            }else{
                front->right = new TreeNode(stoi(str));
                q.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));