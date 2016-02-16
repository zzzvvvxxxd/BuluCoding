#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int _data) {
        data = _data;
        next = NULL;
    }
};
class LinkList {
private:
    Node* head;
public:
    LinkList() {
        head = NULL;
    }
    void insert(Node *node, int index) {
        if (head == NULL) {
            head = node;
            return;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return;
        }
        Node *current_node = head;
        int count = 0;
        while (current_node->next != NULL && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
        }
    }
    void output(){
        if(head==NULL) {
            return;
        }
        Node* current_node = head;
        while(current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
};
int main() {
    LinkList linklist;
    for (int i = 1; i <= 10; i++) {
        Node *node = new Node(i);
        linklist.insert(node, i - 1);
    }
    linklist.output();
    return 0;
}
