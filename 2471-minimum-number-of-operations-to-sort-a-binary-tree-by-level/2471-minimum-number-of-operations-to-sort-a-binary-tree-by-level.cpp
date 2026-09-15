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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;

        while (!q.empty()){
            int size = q.size();

            vector<int> level;

            for(int i = 0; i < size; i++){

                TreeNode* node = q.front();

                q.pop();

                level.push_back(node->val);

                if (node->left){
                    q.push(node->left);
                }

                if (node->right){
                    q.push(node->right);
                }
            }


            int n = level.size();

            vector<pair<int, int>> sorted;

            for (int i = 0; i < n; i++){
                sorted.push_back({level[i], i});
            }

            sort(sorted.begin(), sorted.end());

            vector<bool> visited(n, false);


            for (int i = 0; i < n; i++){

                if (visited[i] || sorted[i].second == i){
                    continue;
                }

                int cyclesize = 0;
                int j = i;

                while (!visited[j]){
                    visited[j] = true;

                    j = sorted[j].second;

                    cyclesize++;
                }

                ans += cyclesize - 1;
            }
        }

        return ans;
    }
};


//a bfs and cyclic sort question as minimum number of swaps to sort an array means cyclic sort, and L leength cycle takes L - 1 swaps, and if 7 goes from 0 to 2, 8 goes from 2 to 3, 5 goes from 3 to 0, means 0 - 2 - 3 - 0, means a cycle. L length cycle takes l - 1 swaps

//ofc a length l = 2 will sort in max 1 and min 0 swaps 