# Maximum Depth of Binary Tree
# 二叉树的最大深度
题目链接：[Here](https://leetcode.com/problems/maximum-depth-of-binary-tree/)  
关于LeetCode的二叉树，参考：[Here](https://leetcode.com/faq/#binary-tree)  

* 递归求解
* 非递归求解

----

##递归求解

#### C++
```C++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(root) {
            int l = maxDepth(root->left);
            int r = maxDepth(root->right);
            depth = l > r ? (l + 1) : (r + 1);
        }
        return depth;
    }
};
```

####Python
```Python
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        depth = 0
        if root is not None:
            left = self.maxDepth(root.left)
            right = self.maxDepth(root.right)
            depth = left > right and left+1 or right+1
        return depth
```

##非递归求解
#### C++
```C++
```

####Python
```Python
```