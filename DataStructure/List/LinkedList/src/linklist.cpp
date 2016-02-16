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
    LinkList l1;
    Node *n1 = new Node(5);
    Node *n2 = new Node(1);
    Node *n3 = new Node(3);
    l1.insert(n1, 0);
    l1.insert(n2, 0);
    l1.insert(n3, 0);
    l1.output();
    return 0;
}
