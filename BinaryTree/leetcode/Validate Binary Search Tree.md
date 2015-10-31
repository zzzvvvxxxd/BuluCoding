# Validate Binary Search Tree
# 验证二叉查找树

[back](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/BinaryTree/index.md)


[题目地址](https://leetcode.com/problems/validate-binary-search-tree/)

##描述  
给出一个二叉树，判断其是否是合法的二叉查找树。  

##方法1：递归
####思路  
递归实现，假设有两个方法noGreater和noLess分别判定左右子树上左右节点的值分别不小于、不大于根节点的值，然后递归判断左右子树是否为二叉查找树。  
* 如果root为空返回true
* 判断左子树结点都小于根结点 和 右子树结点都大于根结点 是否同时成立，如果成立，返回True，否则返回False

####分析

算法时间复杂度：  
> O(N^2)  

空间复杂度
> O(C)  

```C++
class Solution {
public:
    bool noLess(struct TreeNode *root, int val) {
        // 空，返回true
        if (root == NULL)
            return true;
        // 如果根节点的值不大于val，返回false
        if (root->val <= val)
            return false;
        // 递归判定root的左右子树上的所有节点值是否都大于val
        return noLess(root->left, val) && noLess(root->right, val);
    }
    bool noGreater(struct TreeNode *root, int val) {
        // 空，返回true
        if (root == NULL)
            return true;
        // 如果根节点的值不小于val，返回false
        if (root->val >= val)
            return false;
    
        // 递归判定root的左右子树上的所有节点值是否都小于val
        return noGreater(root->left, val) && noGreater(root->right, val);
    }
    bool isValidBST(TreeNode* root) {
        // 空，返回true
        if (root == NULL) return true;
        // 判断：
        // 1.左子树上所有节点的值都小于根节点的值
        // 2.右子树上所有节点的值都大于根节点的值
        if (noGreater(root->left, root->val) && noLess(root->right, root->val))
            // 如果同时成立则，递归判断左右子树是二叉查找树是否同时成立
            return isValidBST(root->left) && isValidBST(root->right);
        else
            // 如果不同时成立，返回false
            return false;
    }
};
```

##方法2：中序遍历判断是否是递增数组
合法的二叉查找树，在中序遍历的情况下，是递增的。因此，中序遍历二叉树，检查数组是否是递增即可。  

```C++
class Solution {
public:
    int last = INT_MIN;		//记录上一个访问的结点的值
    bool isFirst = true;	//last要在第一次访问结点时初始化，所以要判断是否是第一次访问结点
    bool Inorder(TreeNode* root, int& last, bool& isFirst)
    {
        if(root == NULL) return true;
        /*
		 * 遍历左子树
		 */
        if(root->left)
            if(!Inorder(root->left, last, isFirst))
                return false;
        /*
		 * 访问当前结点
		 */
        if(isFirst)
        {
            //遍历的第一个点
            last = root->val;
            isFirst = false;
        }
        else
        {
            if(root->val <= last)
                return false;
            else
                //这里不能返回true，因为还要继续遍历右子树，只有遍历了左右子树之后，才可以return true
                last = root->val;
        }
        /*
		 * 遍历右子树
		 */
        if(root->right)
            if(!Inorder(root->right, last, isFirst))
                return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return Inorder(root, last, isFirst);
    }
};
```  