//https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> stack;
        while(1)
        {
            while(root)
            {
                do
                {
                    stack.push_back(root);
                    root = root->left;
                }while(root);
                root = stack.back();
                root = root->right;
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
                while(!stack.empty())
                {
                    TreeNode* parent = stack.back();
                    if(parent->right)
                    {
                        if(parent->right != root) 
                        {
                            root = parent->right;
                            break;
                        }
                    }
                    stack.pop_back();
                    result.push_back(parent->val);
                    root = parent; 
                }
                if(stack.empty())break;
            }
        }
        return result;
    }
};
