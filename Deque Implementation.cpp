#include <iostream>
using namespace std;
class Deque {
    int* arr;
    int front = -1;
    int rear = -1;
    int size = 0;
    int added = 0;
public:
    Deque(int s) {
        arr = new int[s];
        size = s;
        /*for (int i = 0; i < size; i++)
            arr[i] = '#';*/
    }

    bool empty() {
        return front == -1;
    }

    bool full() {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    void push_front() {
        cout << "Enter a number: \n";
        int num;
        cin >> num;
        if (full()) {
            cout << "Eile pilna" << endl; // deq is full
            return;
        }
        if (empty()) {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
            front = size - 1;
        else
            front--;

        arr[front] = num;
        added++;
    }

    void push_back() {
        cout << "Enter a number: \n";
        int num;
        cin >> num;
        if (full()) {
            cout << "Row is full" << endl; // deq is full
            return;
        }
        if (empty()) {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1)
            rear = 0;
        else
            rear++;

        arr[rear] = num;
        added++;
    }

    void pop_front() {
        if (empty()) {
            cout << "Row is empty" << endl;// deq is empty
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else
            if (front == size - 1)
                front = 0;
            else
                front++;

        added--;
    }

    void pop_back() {
        if (empty()) {
            cout << "Row is empty" << endl;// deq is empty
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else
            rear--;
        added--;
    }
    int getFront() {
        return arr[front];
    }
    int getRear() {
        return arr[rear];
    }
    int getSize() {
        return added;
    }
    void print() {
        Deque deque(size);
        deque = *this;
        cout << "Row: " << endl;
        while (!deque.empty()) {
            cout << deque.getFront() << " ";
            deque.pop_front();
        }

        cout << "\n";
    }
    void printReversed() {
        Deque deque(size);
        deque = *this;

        while (!deque.empty()) {
            cout << deque.getRear() << " ";
            deque.pop_back();
        }

        cout << "\n";
    }

    void menu() {
        int pasirinkimas;
        cout << " (1) Check if it's empty; \n (2) Check if row is full; \n (3) Check row size;\n (4) Add element to front;\n (5) Add element to rear;\n (6) Remove element from front:\n (7) Remove element from rear:\n (8) Read queue;\n (9) Reverse queue \n (10) End" << endl;
        int n;
        cout << "\n Choose an option: ";
        cin >> n;
        switch (n) {
        case 1:
            if (front == -1)
                cout << "Queue is empty" << endl;
            else
                cout << "Queue is not empty" << endl;

            menu();
            break;
        case 2:
            if (((front == 0 && rear == size - 1) || front == rear + 1)) {
                cout << "Queue if full" << endl;
                print();
            }
            else
                cout << "Queue if not full" << endl;
            menu();
            break;
        case 3:
            cout << "Queue size: " << getSize() << endl;
            print();
            menu();
            break;
        case 4:
            push_front();
            print();
            menu();
            break;
        case 5:
            push_back();
            print();
            menu();
            break;
        case 6:
            pop_front();
            print();
            menu();
            break;
        case 7:
            pop_back();
            print();
            menu();
            break;
        case 8:
            print();
            menu();
            break;
        case 9:
            printReversed();
            menu();
            break;
        case 10:
            break;
        default:
            break;
        }
    }
};

int main() {
    Deque deq(5);
    deq.menu();

    return 0;
}