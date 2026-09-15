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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }


        queue<TreeNode*> q;
        q.push(root);

        int currentdepth = 1;

        while (!q.empty()) {
            int size = q.size();

            if (currentdepth == depth - 1){

                while (size--){

                    TreeNode* node = q.front();
                    q.pop();

                    TreeNode* oldleft = node->left;
                    TreeNode* oldright = node->right;

                    TreeNode* newleft = new TreeNode(val);
                    TreeNode* newright = new TreeNode(val);

                    newleft->left = oldleft;
                    newright->right = oldright;

                    node->left = newleft;
                    node->right = newright;
                }

                break;    
            }


            while (size--){
                TreeNode* node = q.front();
                q.pop();

                if (node->left){
                    q.push(node->left);
                }

                if (node->right){
                    q.push(node->right);
                }
            }

            currentdepth++;
            
        }

        return root;
    }
};



//we are given root, val, depth, we have to use bfs, 

//go level by level, first initialize queue, then push root, then while q is not empty, currentdepth counter ups when one level is processed, when currentdepth = depth - 1; we stop, 