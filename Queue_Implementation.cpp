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

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    bool isFull() {
        Node* newNode = new Node();
        Node* ret = newNode;
        delete newNode;
        return (ret == NULL);
    }

    void display() {
        if (isEmpty()) {
            cout << "The queue is empty\n";
            return;
        } else {
            Node* temp = front;
            while (temp != NULL) {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
    }

    void enQueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (isEmpty()) {
            front = rear = newNode;
            return;
        } else {
            rear->next = newNode;
            rear = newNode;
            return;
        }
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "The queue is empty\n";
            return 0;
        } else if (front == rear) {
            int ret = front->data;
            delete front;
            front = rear = NULL;
            return ret;
        } else {
            int ret = front->data;
            Node* del = front;
            front = front->next;
            delete del;
            return ret;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "The queue is empty\n";
            return 0;
        } else {
            return front->data;
        }
    }

    int count() {
        int counter = 0;
        Node* temp = front;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    void clear() {
        while (!isEmpty()) {
            deQueue();
        }
        return;
    }

    void search(int item) {
        if (isEmpty()) {
            cout << "The queue is empty\n";
            return;
        } else {
            Node* temp = front;
            while (temp != NULL && temp->data != item) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << " item not found\n";
                return;
            } else {
                cout << " item is found \n";
                return;
            }
        }
    }

    ~Queue() {
        while (!isEmpty()) {
            deQueue();
        }
    }
};

int main() {
    Queue que;
    if (que.isEmpty())
        cout << "The queue is empty\n";
    else
        cout << "There are elements in the queue\n";

    if (que.isFull())
        cout << "The memory is full\n";
    else
        cout << "There are places in the memory\n";

    int element;
    for (int i = 0; i < 6; i++) {
        cout << "Enter element to add to the queue: ";
        cin >> element;
        que.enQueue(element);
    }
    que.display();
    cout << "the element in the top is: " << que.peek() << endl;

    que.deQueue();
    cout << "display after dequeue: \n";
    que.display();

    cout << "count elements of queue: " << que.count() << endl;

    cout << "Enter element to search for: ";
    cin >> element;
    que.search(element);
    cout << "clear elements of queue\n";
    que.clear();
    que.display();

    return 0;
}
