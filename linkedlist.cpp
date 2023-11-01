#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LL {
public:
    int count = 0;
    Node* head;

    LL() {
        head = nullptr;
        int count = 0;
    }

    // Methods for inserting data
    void insertEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        count++;
    }

    void insertFront(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head != nullptr) {
            Node* current = head;
            newNode->next = current;
            head = newNode;
        } else {
            head = newNode;
        }
        count++;
    }

    void insert(int data, int position) {
        if (position == 1)
            insertFront(data);
        else if (position > count) {
            cout << "Linked list has only " << count << " nodes. But your position exceeded the size. (max = " << count + 1 << " )" << endl;
            count--;
        } else {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;

            Node* current = head;
            for (int i = 1; i < position - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = newNode;
            newNode->next = temp;
        }
        count++;
    }

    // Methods for deletion
    void deleteFront() {
        if (head == nullptr) {
            cout << "Cannot delete elements from an empty list. " << endl;
        } else {
            Node* current = head;
            head = current->next;
            delete current;
            count--;
        }
    }

    void deleteEnd() {
        if (head == nullptr) {
            cout << "Cannot delete elements from an empty list. " << endl;
        } else {
            Node* current = head;
            Node* current1 = nullptr;
            while (current->next != nullptr) {
                current1 = current;
                current = current->next;
            }
            current1->next = nullptr;
            delete current;
            count--;
        }
    }

    void deletePos(int position) {
        if (head == nullptr) {
            cout << "Cannot delete elements from an empty list. " << endl;
        } else {
            if (position == 1) {
                deleteFront();
            } else {
                Node* current = head;
                for (int i = 1; i < position - 1; i++) {
                    current = current->next;
                }
                Node* delNode = current->next;
                current->next = delNode->next;
                delete delNode;
                count--;
            }
        }
    }

    int size() {
        return count;
    }

    void reverse() {
        if (head == nullptr) {
            cout << "Can't reverse an empty linked list." << endl;
        } else {
            Node* current = head;
            Node* prev = nullptr;
            Node* next = nullptr;
            while (current != nullptr) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
    }

    void print() {
        if (head == nullptr) {
            cout << "The linked list is empty" << endl;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                cout << current->data << " --> ";
                current = current->next;
            }
            cout << current->data << " --> null" << endl;
        }
    }
};

class Stack {
    int top = -1;
    LL ll;
    int size;

public:
    Stack(int size) {
        this->size = size;
    }

    void push(int a) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            ll.insertEnd(a);
        }
    }

    void pop() {
        if (top == -1)
            cout << "Stack Underflow" << endl;
        else {
            ll.deleteEnd();
            top--;
        }
    }

    void display() {
        cout << "Stack Elements:" << endl;
        ll.print();
    }
};

int main() {
    
    LL newll;

    
    newll.insertEnd(1);
    newll.insertEnd(2);
    newll.insertEnd(3);
    newll.insertFront(5);
    newll.insert(6, 4);

    
    cout << "Linked List:" << endl;
    newll.print();

    
    newll.reverse();
    cout << "\nLinked List after reversal:" << endl;
    newll.print();

    
    Stack newStack(5);

    
    newStack.push(10);
    newStack.push(20);
    newStack.push(30);

    
    cout << "\nStack elements:" << endl;
    newStack.display();

    
    newStack.pop();
    newStack.pop();

    cout << "\nStack elements after popping twice:" << endl;
    newStack.display();

    
    newll.deleteFront();
    cout << "\nLinked List after deleting front element:" << endl;
    newll.print();

    newll.deletePos(2);
    cout << "\nLinked List after deleting element at position 2:" << endl;
    newll.print();

    newll.deleteEnd();
    cout << "\nLinked List after deleting the last element:" << endl;
    newll.print();

    cout << "\nLinked List size: " << newll.size() << endl;

    
    LL ll2;
    cout << "\nLinked List ll2:" << endl;
    ll2.print();

    
    ll2.deleteFront();

    return 0;
}
