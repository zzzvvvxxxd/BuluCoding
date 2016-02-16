#Remove Linked List Elements
#删除链表中指定值val的所有元素

题目地址：[Here](http://www.lintcode.com/zh-cn/problem/remove-linked-list-elements/)

样例：给出链表`1->2->3->3->4->5`，和`val=3`，需要返回删除所有值为3的元素之后的链表：`1->2->4->5` 

##代码

###C++
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
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* current_node = head, *previous_node;
        while(current_node != NULL) {
            if(current_node->val == val) {
                if(current_node == head) {
                    head = current_node->next;
                    delete current_node;
                    current_node = head;
                }
                else {
                    previous_node->next = current_node->next;
                    delete current_node;
                    current_node = previous_node->next;
                }
            }
            else {
                previous_node = current_node;
                current_node = current_node->next;
            }
        }
        return head;
    }
};
```