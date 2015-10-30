#反转链表

[题目地址](http://www.lintcode.com/zh-cn/problem/reverse-linked-list/)  

##描述
> 给出一个链表1->2->3->null，这个翻转后的链表为3->2->1->null  

##C++

```C++
/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        ListNode* pre = NULL;
        ListNode* n;
        while(head != NULL){
            n = head -> next;
            head->next = pre;
            pre = head;
            head = n;
        }
        return pre;
    }
};
```  