# Balanced Binary Tree
# 平衡二叉树检查

[返回](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/BinaryTree/index.md)


[题目链接](https://leetcode.com/problems/balanced-binary-tree/)

##递归
使用递归的depth函数，检查左右子树的高度差。  
**注意**：根据平衡二叉树定义，不仅要判断根结点，要求所有的结点的子树都满足平衡条件。 

遍历思想：不出错不返回，出错了返回false，到了边界返回true   

####C++
```C++
class Solution {
public:
    int depth(TreeNode* root)
    {
        if(!root) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        return r > l ? (r+1) : (l+1);
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(abs(depth(root->right) - depth(root->left)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
```