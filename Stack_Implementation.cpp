#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
};

class Stack {
    Node* top;
public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    bool isFull() {
        Node* newNode = new Node();
        bool ret = (newNode == NULL);
        delete newNode;
        return ret;
    }

    void display() {
        if (isEmpty()) {
            cout << "The stack is empty\n";
            return;
        } else {
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << "    ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (isEmpty()) {
            top = newNode;
            return;
        } else {
            newNode->next = top;
            top = newNode;
            return;
        }
    }

    void search(int item) {
        if (isEmpty()) {
            cout << "The stack is empty\n";
            return;
        } else {
            Node* temp = top;
            while (temp != NULL && temp->data != item) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "This item not found\n";
                return;
            } else {
                cout << "item is found\n";
                return;
            }
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "The stack is empty\n";
            return 0;
        } else {
            Node* del = top;
            int ret = top->data;
            top = top->next;
            delete del;
            return ret;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "The stack is empty\n";
            return 0;
        } else {
            return (top->data);
        }
    }

    int count() {
        int counter = 0;
        Node* temp = top;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return (counter);
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack st;
    if (st.isEmpty())
        cout << "The stack is empty\n";
    else
        cout << "There are elements in the stack\n";

    if (st.isFull())
        cout << "The memory is full\n";
    else
        cout << "There are places in the memory\n";

    int value;
    for (int i = 0; i < 5; i++) {
        cout << "Enter value to push: ";
        cin >> value;
        st.push(value);
    }
    st.display();

    cout << "Enter item to search for: ";
    cin >> value;
    st.search(value);

    cout << "Number items in the stack: " << st.count() << endl;
    cout << "The element in top of stack: " << st.peek() << endl;

    cout << "success deletion for element: " << st.pop() << endl;
    st.display();

    return 0;
}
