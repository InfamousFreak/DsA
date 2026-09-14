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
    void serializeDFS(TreeNode* root, string& s){
        if (root == nullptr){
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeDFS(root->left, s);
        serializeDFS(root->right, s);
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeDFS(root, s);
        return s;
    }

    TreeNode* deserializeDFS(stringstream& ss){
        string val;
        getline(ss, val, ',');

        if (val == "#"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));

        root->left = deserializeDFS(ss);
        root->right = deserializeDFS(ss); 

        return root; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        return deserializeDFS(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));