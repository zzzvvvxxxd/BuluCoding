# Add two numbers
# 链表求和

----
题目地址：[Here](http://www.lintcode.com/zh-cn/problem/add-two-numbers/)


[返回](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/Array%26List/index.md)  

###题目描述


> 有两个用链表代表的整数，每个节点包含一位数字，数字存储在原来整数中**相反**的顺序，使得第一个数字位于链表的开头。例如513的链表存储顺序为 3->1->5
写出一个函数，将两个整数相加，用链表形式返回和

实例：
>给出两个链表`3->1->5->null` 和 `5->9->2->null`，返回 `8->0->8->null`
实际就是513 + 295 = 808

注意：  
数字链表的长度不是严格等长的，甚至可能为NULL

###代码

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode *n1 = l1, *n2 = l2;
        
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        ListNode* head = new ListNode((n1->val + n2->val)%10);
        int c = (n1->val + n2->val)/10;
        n1 = n1->next;
        n2 = n2->next;
        ListNode* prev = head;
        while(n1 != NULL && n2 != NULL) {
            int v = n1->val + n2->val + c;
            c = v/10;
            v = v%10;
            prev->next = new ListNode(v);
            prev = prev->next;
            n1 = n1->next;
            n2 = n2->next;
        }
        while(n1 != NULL) {
            int v = n1->val + c;
            c = v/10;
            v = v%10;
            prev->next = new ListNode(v);
            prev = prev->next;
            n1 = n1->next;
        }
        while(n2 != NULL) {
            int v = n2->val + c;
            c = v/10;
            v = v%10;
            prev->next = new ListNode(v);
            prev = prev->next;
            n2 = n2->next;
        }
        if(c > 0) {
            prev->next = new ListNode(c);
        }
        return head;
    }
};
```