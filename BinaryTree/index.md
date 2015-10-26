# 二叉树

##概念
#### 满二叉树(full binary tree)

> 每一个结点是一个分支结点，并恰好有两个非空子节点；或者是叶子结点。

#### 完全二叉树(complete binary tree)

> 完全二叉树有严格的形状要求：从根结点起每一层从左到右填充。一棵高度为d的完全二叉树除了d-1层以外，每一层都是满的。底层叶子结点集中在左边的若干位置上。

##Index

----

###LeetCode
[Binary Tree Preorder Traversal 前序遍历](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/BinaryTree/leetcode/Binary%20Tree%20Preorder%20Traversal.md)

> 遍历

[Maximum Depth of Binary Tree 二叉树最大深度](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/BinaryTree/leetcode/Maximum%20Depth%20of%20Binary%20Tree.md)

----

##定义
#### C++
```C++
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

#### Python
```python
# Definition for a binary tree node.
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
```

