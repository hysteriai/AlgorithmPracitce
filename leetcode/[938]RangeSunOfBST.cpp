/*
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

 

Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23
 

Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.
*/
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int num = 0;
        if (NULL == root)
        {
            return num;
        }

        if (root->val >= L && root->val <= R)
        {
            num += root->val;
        }

        if (NULL != root->left)
        {
            num += rangeSumBST(root->left, L, R);
        }
        
        if (NULL != root->right)
        {
            num += rangeSumBST(root->right, L, R);
        }

        return num;
    }
};

/*
如下是网上的一种解决方案，因为是二叉查找树（binary search tree，左子树的值都小于根，右子树的值都大于根），
所以有些情况可以只遍历一半的子树，速度会更快。
当时不清楚binary search tree 和 Binary Sort Tree一样，所以没考虑到。
*/
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
      
      if(!root) return 0;
      
      if(root->val >= L && root->val <= R){
        return root->val + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
      }else if(root->val < L){
        return rangeSumBST(root->right,L,R);
      }else {
        return rangeSumBST(root->left,L,R);
      }
    }
  
  
};
