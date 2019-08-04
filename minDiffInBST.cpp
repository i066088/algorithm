//https://leetcode.com/problems/minimum-distance-between-bst-nodes/submissions/
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
    int minDiffInBST(TreeNode* root) {
      vector<int> result;
        vector<TreeNode*> stack;
        while(1)
        {
            while(root)
            {
                stack.push_back(root);
                root = root->left;
            }

            if(stack.empty())
            {
                break;
            }
            else
            {
                root = stack.back();
                stack.pop_back();
                result.push_back(root->val);
                root = root->right;
            }
        }
        
        int min = result[1] -  result[0];
        for(size_t i = 2; i < result.size(); ++i)
        {
            int temp = result[i] -  result[i-1];
            min = min > temp? temp : min;
        }
        return min;
    }
};
