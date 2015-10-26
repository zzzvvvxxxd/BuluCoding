# Binary Tree Preorder Traversal
# 前序遍历二叉树

* 非递归解法
* 递归解法

##非递归
根据前序遍历访问的顺序，优先访问根结点，然后再分别访问左孩子和右孩子。  
即对于任一结点，其可看做是根结点，因此可以直接访问，访问完之后，若其左孩子不为空，按相同规则访问它的左子树；当访问其左子树时，再访问它的右子树。  
因此其处理过程如下：  
对于任一结点P：  
* 访问结点P，并将结点P入栈;  
* 判断结点P的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作，并将栈顶结点的右孩子置为当前的结点P，循环至1);若不为空，则将P的左孩子置为当前的结点P;  
* 直到P为NULL并且栈为空，则遍历结束。  


#### C++

```C++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* p = root;
        vector<int> v;
        stack<TreeNode*> s;
        while(p != NULL || !s.empty()) {
            while(p != NULL)
            {
                v.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if(!s.empty())
            {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return v;
    }
};
```

##递归

####C++
```C++
class Solution {
public:
    vector<int> v;
    vector<int> preorderTraversal(TreeNode* root) {
        v.clear();
        preorder(root);
        return v;
    }
    
    void preorder(TreeNode* root) {
        if(root == NULL) return;
        v.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};
```