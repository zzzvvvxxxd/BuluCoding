# Maximum Depth of Binary Tree
# ��������������
��Ŀ���ӣ�[Here](https://leetcode.com/problems/maximum-depth-of-binary-tree/)  
����LeetCode�Ķ��������ο���[Here](https://leetcode.com/faq/#binary-tree)  

* �ݹ����
* �ǵݹ����

----

##�ݹ����

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

##�ǵݹ����
#### C++
```C++
```

####Python
```Python
```