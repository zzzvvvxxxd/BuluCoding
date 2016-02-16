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
* **链表为空**

```C++
if(head == NULL){
}
```

* **操作的是链表的第一个元素**

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

* **插入/删除指定的index大于链表长度**
参考"移动"


###移动
在insert和delete_node操作时，需要移动到index指定的位置，然后进行插入和删除操作，移动操作套路如下：  

1. 插入：
```C++
while(current_node->next != NULL && count < index - 1) {
    current_node = current_node->next;
    count++;
}
if(count == index - 1) {
    node->next = current_node->next;
    current_node->next = node;
}
```

2. 删除：
```C++
while(current_node->next != NULL && count < index - 1) {
    current_node = current_node->next;
    count ++;
}
if(count == index - 1 && current_node->next != NULL) {
    // 当index指向的是最后一个元素的下一个位置
    // current_node指向最后一个元素
    // delete下一个节点的操作是非法的，所以需要第二个判断条件
    Node* delete_node = current_node->next;
    current_node->next = delete_node->next;
    delete delete_node;
}
```

insert和delete_node的移动代码主体是一致的，一个while，一个if  
while用来移动到index指定位置前一个位置，或者因为index过大使得current_node停留在最后一个节点处

> if就是用来判断当前位置是否在index-1，如果不在则说明index过大（这就解决了边界条件中的第三点：index大于链表长度）  
> 另外，insert允许插入在最后一个节点的下一个位置，但是delete_node不能  

```C++
while(current_node->next != NULL && count < index - 1)
if(
count == index - 1
[&& current_node->next != NULL]
)
```

----