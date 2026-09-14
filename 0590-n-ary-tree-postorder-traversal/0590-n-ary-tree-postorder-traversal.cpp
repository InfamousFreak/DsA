/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, vector<int>& result){
        if (!node) return;

        for (int i = 0; i < node->children.size(); i++){
            dfs(node->children[i], result);
        }
        result.push_back(node->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> result;

        dfs(root, result);
        return result;
    }
};