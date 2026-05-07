#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    bool isEmpty() {
        return (head == NULL);
    }

    void insertFirst(int newValue) {
        Node* newNode = new Node(newValue);
        newNode->next = head;
        head = newNode;
        return;
    }

    void insertLast(int newValue) {
        if (isEmpty()) {
            insertFirst(newValue);
            return;
        } else {
            Node* newNode = new Node(newValue);
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            return;
        }
    }

    void insertBefore(int before, int newValue) {
        if (isEmpty()) {
            cout << "The list is empty\n";
            return;
        } else if (head->data == before) {
            insertFirst(newValue);
            return;
        } else {
            Node* temp = head;
            while (temp->next != NULL && (temp->next->data) != before) {
                temp = temp->next;
            }
            if (temp->next == NULL) {
                cout << "This item does not exist to insert before it\n";
                return;
            } else {
                Node* newNode = new Node(newValue);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << "\n";
    }

    // This function returns the node BEFORE the target item
    Node* searchFor(int item) {
        if (isEmpty()) {
            cout << "The list is Empty \n";
            return NULL;
        } else {
            Node* temp = head;
            while (temp->next != NULL && (temp->next->data) != item) {
                temp = temp->next;
            }
            if (temp->next == NULL) {
                cout << "This item not found\n";
                return NULL;
            } else {
                cout << "item is found\n";
                return temp;
            }
        }
    }

    void deletion(int value) {
        if (isEmpty()) {
            cout << "The list is Empty \n";
            return;
        }
        Node* temp = searchFor(value);
        Node* del = temp->next;
        if (temp->next == NULL) {
            cout << "Item not found";
            return;
        } else if (head->data == value) {
            del = head;
            head = head->next;
            delete del;
            cout << "Success deletion\n";
            return;
        } else {
            temp->next = (temp->next->next);
            delete del;
            cout << "success deletion\n";
            return;
        }
    }
};

int main() {
    LinkedList list;
    if (list.isEmpty())
        cout << "The list is Empty \n";
    else
        cout << "The list contains element\n";

    int item;
    for (int i = 0; i < 4; i++) {
        cout << "Enter value to insert at the beginning:\n";
        cin >> item;
        list.insertFirst(item);
    }
    list.display();
    list.insertLast(10);
    list.display();
    list.insertBefore(10, 9);
    list.display();
    list.searchFor(9);
    list.deletion(9);
    list.display();

    return 0;
}
