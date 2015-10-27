# Binary Tree Postorder Traversal
# 后序遍历二叉树

##递归

####Python

```Python
class Solution(object):
    def __init__(self):
        self.v = []
    def postorder(self, root):
        if root:
            self.postorder(root.left)
            self.postorder(root.right)
            self.v.append(root.val)  
        else:
            return
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.v = []
        self.postorder(root)
        return self.v
```