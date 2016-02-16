#链表
> Linked List

----

###基本数据结构
**Node**  
```C++
class Node {
public:
    int data;
    Node* next;
    Node(int _data) {
        data = _data;
        next = NULL;
    }
};
```

**LinkList**  
```C++
class LinkList {
private:
    Node* head;
public:
    LinkList() {
        head = NULL;
    }
}
```

###边界条件  
* 链表为空

```C++
if(head == NULL){
}
```

* 操作的是链表的第一个元素

```C++
if(index == 0){
}
```
例如，删除链表第一个元素：  

```C++
Node* current_node = head;
if(index == 0) {
    head = head->next;   // head指向第二个元素
    delete current_node; // 释放原本的head
    return;
}
```

* 插入\删除指定的index大于链表长度