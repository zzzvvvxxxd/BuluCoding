# Binary Tree Postorder Traversal
# 后序遍历二叉树

[返回](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/BinaryTree/index.md)

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

##非递归

####思路  

后序遍历递归定义：先左子树，后右子树，再根节点。  
后序遍历的难点在于：需要判断上次访问的节点是位于左子树，还是右子树。  

```C++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> s;
        vector<int> v;
        if(root == NULL)
            return v;
        TreeNode *last = NULL;
        while(root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        while(!s.empty())
        {
            root = s.top();
            s.pop();
            if(root->right == NULL || root->right == last)
            {
                //右子树为空 或 已经访问过右子树
                v.push_back(root->val);
                last = root;
            }
            else
            {
                s.push(root);
                root = root->right;
                while(root)
                {
                    s.push(root);
                    root = root->left;      //进入右子树的左子树
                }
            }
        }
        return v;
    }
};
```