#include <bits/stdc++.h>
using namespace std;

template<class t>

class Queue {

private:
    int rear ;
    int front ;
    int length ;
    t *arr ;
    int max_size ;

public:

    Queue(int size) {

        if(size <= 0) {
            max_size = 100 ;
        }else {
            max_size = size ;
        }

        length = 0 ;

        front = 0 ;

        rear = 0 ;

        arr = new t[max_size];


    }
    bool isEmpty() {
        return length == 0 ;
    }

    bool isFull() {
        return length == max_size ;
    }

    void Enqueue(int element) {
        if(isFull()) {
            cout << "Full Queue !\n";
        }else {
            rear = (rear + 1) % max_size ;
            arr[rear] = element;
            length++;
        }
    }

    void Dequeue(int element) {
        if(isEmpty()) {
            cout << "Empty Queue !\n";
        }else {
            front = (front + 1) % max_size ;
            length--;
        }
    }

    int search(t element) {
        int pos = -1 ;
        if(!isEmpty()) {
            for(int i = front ; i != rear ; i = (i + 1 ) % max_size) {
                if(arr[i] == element) {
                    pos = i ;
                    break;
                }
            }

            if(pos == -1) {
                if(arr[rear] == element) {

                    pos = rear ;
                }
            }
        }else {
            cout << "Empty Queue\n";
        }
        return pos ;
    }

    void print() {
        if (isEmpty()) {
            cout << "Empty Queue\n";
        } else {
            for (int i = front; i != rear; i = (i + 1) % max_size) {

                cout << arr[i] << " ";
            }
            cout << arr[rear];
        }
    }

};
int main() {
      Queue<int> q1(100) ;
    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);
    q1.Enqueue(40);
    q1.Dequeue(10);
    q1.Enqueue(50);
    q1.Enqueue(120);
    cout << q1.search(120) << "\n";

    q1.print();


  
    return 0;
}

