#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
};
class List {
public:
    Node *current, *head;
    List() {
        current = NULL;
        head = NULL;
    }

    void insert(int value) {
        Node *newnode = new Node();
        newnode->data = value;
        newnode->next = current;
        current = newnode;
    }

void add(Node *l1, Node *l2) {
        int sum = 0, carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = (l1 != NULL) ? l1->data : 0;
            int val2 = (l2 != NULL) ? l2->data : 0;
            sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            Node *l3 = new Node();
            l3->data = sum;
            l3->next = NULL;
            if (current != NULL) {
                current->next = l3;
                current = l3;
            } else {
                head = l3;
                current = l3;
            }
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;

            cout << l3->data << " -> ";
        }
        cout << "NULL" << endl;
    }

    void display() {
        Node *temp = current;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List l1, l2, l3;
    l1.insert(7);  l1.insert(5);
    l2.insert(6);  l2.insert(1); l2.insert(3) ; 
    l1.display();  l2.display();  
    l3.add(l1.current, l2.current); 
    return 0;
}

