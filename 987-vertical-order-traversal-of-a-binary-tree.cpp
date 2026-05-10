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
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> nodes; // basically, a map that tracks the column and another map which then tracks rows and a multiset which stores multiple elements that can be present in that column
        queue<tuple<TreeNode *, int, int>> q;

        q.push({root, 0, 0});

        while (!q.empty())
        {
            auto [node, x, y] = q.front(); // here x is column track and y is
            q.pop();

            nodes[x][y].insert(node->val);

            if (node->left)
                q.push({node->left, x - 1, y + 1});
            if (node->right)
                q.push({node->right, x + 1, y + 1});
        }

        vector<vector<int>> result;
        for (auto &[x, yMap] : nodes)
        {
            vector<int> columns;
            for (auto &[y, vals] : yMap)
            {
                columns.insert(columns.end(), vals.begin(), vals.end());
            }
            result.push_back(columns);
        }
        return result;
    }
};