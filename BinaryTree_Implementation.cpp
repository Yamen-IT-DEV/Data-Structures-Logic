#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class TreeBinary {
public:
    Node* root;

    TreeBinary() {
        root = NULL;
    }

    Node* insertF(Node* r, int value) {
        if (r == NULL) {
            return new Node(value);
        } else if (value < r->data) {
            r->left = insertF(r->left, value);
            return r;
        } else {
            r->right = insertF(r->right, value);
            return r;
        }
    }

    void insert(int value) {
        root = insertF(root, value);
    }

    void preOrder(Node* r) { // root, left, right
        if (r == NULL) return;
        cout << r->data << "\t";
        preOrder(r->left);
        preOrder(r->right);
    }

    void inOrder(Node* r) { // left, root, right
        if (r == NULL) return;
        inOrder(r->left);
        cout << r->data << "\t";
        inOrder(r->right);
    }

    void lastOrder(Node* r) { // left, right, root
        if (r == NULL) return;
        lastOrder(r->left);
        lastOrder(r->right);
        cout << r->data << "\t";
    }

    Node* searchT(Node* r, int item) {
        if (r == NULL) {
            cout << "item not found\n";
            return NULL;
        } else if (r->data == item) {
            cout << "item is found\n";
            return r;
        } else if (item < r->data) {
            return searchT(r->left, item);
        } else {
            return searchT(r->right, item);
        }
    }

    Node* findMin(Node* r) {
        if (r == NULL) return NULL;
        else if (r->left != NULL) return findMin(r->left);
        else return r;
    }

    Node* findMax(Node* r) {
        if (r == NULL) return NULL;
        else if (r->right != NULL) return findMax(r->right);
        else return r;
    }

    Node* deletion(Node* r, int item) {
        if (r == NULL) return NULL;
        if (item < r->data)
            r->left = deletion(r->left, item);
        else if (item > r->data)
            r->right = deletion(r->right, item);
        else {
            // Case 1: No children
            if (r->left == NULL && r->right == NULL) {
                delete r;
                return NULL;
            } 
            // Case 2: One child (Left)
            else if (r->left != NULL && r->right == NULL) {
                Node* temp = r->left;
                delete r;
                return temp;
            } 
            // Case 3: One child (Right)
            else if (r->left == NULL && r->right != NULL) {
                Node* temp = r->right;
                delete r;
                return temp;
            } 
            // Case 4: Two children
            else {
                Node* maxNode = findMax(r->left);
                r->data = maxNode->data;
                r->left = deletion(r->left, maxNode->data);
            }
        }
        return r;
    }

    void clear(Node* r) {
        if (r == NULL) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

    ~TreeBinary() {
        clear(root);
        root = NULL;
    }
};

int main() {
    TreeBinary btree;
    btree.insert(45);
    btree.insert(15);
    btree.insert(79);
    btree.insert(90);
    btree.insert(10);
    btree.insert(55);
    btree.insert(12);
    btree.insert(20);
    btree.insert(50);

    cout << "Pre-Order Display:\n";
    btree.preOrder(btree.root);
    cout << "\n___________________________________\n";
    
    cout << "In-Order Display:\n";
    btree.inOrder(btree.root);
    cout << "\n___________________________________\n";
    
    cout << "Post-Order Display:\n";
    btree.lastOrder(btree.root);
    cout << "\n___________________________________\n";

    if(btree.root != NULL)
        cout << "The minimum is: " << btree.findMin(btree.root)->data << endl;

    int element;
    cout << "Enter element to delete: ";
    cin >> element;
    btree.root = btree.deletion(btree.root, element);
    
    cout << "After deletion (In-Order):\n";
    btree.inOrder(btree.root);
    cout << endl;

    return 0;
}
