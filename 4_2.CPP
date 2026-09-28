#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Linkedlist {
public:
    Node* head;
    Node* tail;

    Linkedlist() {
        head = NULL;
        tail = NULL;
    }

    // Insert at front
    void insert_at_front(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert at end
    void insert_at_end(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert in middle
    void insert_at_middle(int pos, int x) {

        if (pos < 0) {
            cout << "Invalid";
            return;
        }

        if (pos == 0) {
            insert_at_front(x);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(x);

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    // Delete by value
    void delete_by_value(int x) {

        if (head == NULL) {
            cout << "It is empty";
            return;
        }

        // If value is in first node
        if (head->data == x) {
            delete_front();
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != x) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Value not found";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;

        if (del == tail) {
            tail = temp;
        }
        delete del;
    }

    void delete_front() {

        if (head == NULL) {
            cout << "It is empty";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

        if (head == NULL) {
            tail = NULL;
        }
    }

    void print_ll() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse_print(Node* temp) {

        if (temp == NULL) {
            return;
        }
        reverse_print(temp->next);
        cout << temp->data << " ";
    }

    void print_reverse() {
         reverse_print(head);
         cout << endl;
    }
};

int main() {
    Linkedlist q;

    // Insert
    q.insert_at_front(20);
    q.insert_at_end(40);
    q.insert_at_end(50);
    q.insert_at_front(10);
    q.insert_at_middle(2, 30);

    cout << "Forward: ";
    q.print_ll();

   
    cout << "Reverse: ";
    q.print_reverse();

    q.delete_by_value(30);
    q.print_ll();

    cout<<"After deleting 30:";
    q.print_ll();

    cout << "Reverse: ";
    q.print_reverse();

    return 0;
}