# Binary Tree Preorder Traversal
# ǰ�����������

* �ǵݹ�ⷨ
* �ݹ�ⷨ

##�ǵݹ�
����ǰ��������ʵ�˳�����ȷ��ʸ���㣬Ȼ���ٷֱ�������Ӻ��Һ��ӡ�  
��������һ��㣬��ɿ����Ǹ���㣬��˿���ֱ�ӷ��ʣ�������֮���������Ӳ�Ϊ�գ�����ͬ���������������������������������ʱ���ٷ���������������  
����䴦��������£�  
������һ���P��  
* ���ʽ��P���������P��ջ;  
* �жϽ��P�������Ƿ�Ϊ�գ���Ϊ�գ���ȡջ����㲢���г�ջ����������ջ�������Һ�����Ϊ��ǰ�Ľ��P��ѭ����1);����Ϊ�գ���P��������Ϊ��ǰ�Ľ��P;  
* ֱ��PΪNULL����ջΪ�գ������������  


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

##�ݹ�

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