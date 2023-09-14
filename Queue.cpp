#include <iostream>
#include <limits>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Enqueued [" << item << "]." << endl;
        printQueue();
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        int item = front->data;
        Node* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        }
        else {
            front = front->next;
        }

        cout << "Dequeued [" << item << "]." << endl;
        delete temp;
        printQueue();
    }

    void printQueue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Current Queue: [";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << ", ";
            }
            current = current->next;
        }
        cout << "]" << endl;
    }
};

int main() {
    Queue myQueue;
    int choice;

    while (true) {
        cout << "-------------------------" << endl;
        cout << "Queue ADT Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid choice (1, 2, or 3)." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            int item;
            cout << "Enter the item to enqueue: ";
            cin >> item;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter an integer for the item." << endl;
            }
            else {
                myQueue.enqueue(item);
            }
            break;

        case 2:
            myQueue.dequeue();
            break;

        case 3:
            cout << "Exiting the program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
