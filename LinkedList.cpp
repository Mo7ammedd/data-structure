#include <bits/stdc++.h>
using namespace std;

class LinkedList {
private:
   struct Node {
       int item ;
       Node *next;

   };
   Node *first ;
   Node *last ;
   int length ;
public:
    LinkedList() {
        first = NULL ;
        last = NULL ;
        length = 0 ;
    }
    bool isEmpty() {
        return length == 0 ;
    }
    void addToHead(int element){
        Node *newNode = new Node ;
        newNode->item = element;
        if(length == 0) {
            first = last = newNode;
            newNode->next = NULL;

        }else {

            newNode->next = first ;
            first = newNode;

        }
        length++;
    }
    void insertAtPos(int pos , int item) {
        if(pos < 0 || pos > length) {
            cout <<"Out Of Range\n";
        } else {
            Node *newNode = new Node ;
            newNode->item = item;
            if(pos == 0) {
                addToHead(item);
            }else if(pos == length){
                addToTail(item);
            }else {
                Node *cur = first ;
                for(int i = 1 ; i < pos ; i++) {
                    cur = cur->next;
                }
                newNode->next = cur->next;
                cur->next = newNode;
                length++;

            }
        }
    }
    void addToTail(int element) {
        Node *newNode = new Node ;
        newNode->item = element;
        if(length == 0) {
            first = last = newNode;
            newNode->next = NULL;

        }else {
            last->next = newNode;
            newNode->next = NULL ;
           last =  newNode  ;

        }
        length++;

    }
    int findNode(int element) {
        Node *ptr = first;
        int pos = 0 ;
        while(ptr != NULL) {
             if(ptr->item == element) {
                 return pos;
             }
            ptr = ptr->next;
             pos++;

        }
        return -1;
    }
    int SumOdd() {
        int sum = 0 ;
        Node *newNode = first ;
        for(int i = 0 ; i < length ; i++) {
            if((newNode->item) % 2 != 0) {
                sum += newNode->item;
            }
            newNode = newNode->next ;

        }
        return sum;
    }
    int getMinimum(){
        int mn = INT_MAX;
        Node *newNode = first ;
        for(int i = 0 ; i < length ; i++) {
            mn = min(mn , newNode->item);
            newNode = newNode->next ;

        }
       return mn ;
    }
    int countList() {
        int count = 0;
        Node *counter = first ;
        cout << "Number of Nodes Linked list is: ";
        while(counter != NULL) {
            counter = counter->next ;
            count++;
        }
        return count ;
    }

    int deleteFromHead() {
        Node *curr = new Node ;
        Node *item = curr;

        if(isEmpty()) {
            cout << "Empty List Can't Remove Element\n";
        }else if(length == 1) {
            delete first ;
            first = last = NULL ;
            length--;

        }else {
            curr = first ;
            first = first->next;
            delete curr;
          length--;
        }
        return item->item;

    }
    int deleteFromTail() {
        Node *curr = first->next;
        Node *prev = first;
        if(length == 0) {
            cout << "Empty List can't Remove\n";
        }else if(length == 1) {
            delete first ;
            last = first = NULL ;
            length--;
        }else {

            while(curr != last) {
                prev = curr ;
                curr = curr->next;
            }
            delete curr;
            prev->next = NULL;
            last =prev ;
            length--;
        }
        return prev->item;
    }


    void printList() {
        Node *temp = first ;
        cout << "Created linked list is : ";
        while(temp != NULL) {
            cout << temp->item << " " ;
           temp =  temp->next ;

        }
    }

    LinkedList copylist() {
        Node *ptr = first;
        LinkedList l;
        while(ptr != NULL) {
            l.addToTail(ptr->item);
            ptr = ptr->next ;
        }
     return l ;
    }
    ~LinkedList() {
        Node *current;
        while (first != NULL)
        {
            current = first;
            first = first->next;
            delete current;
        }
        last = NULL;
        length = 0;
    }

 };
int main() {



   

    LinkedList l ;
    l.addToHead(10);
    l.addToTail(3);
    l.insertAtPos(1 , 20);
    cout << l.countList() << "\n";
   cout << l.findNode(10) << "\n";
   cout << l.getMinimum() << "\n";
   cout << l.SumOdd() << "\n";
    l.copylist();

    l.printList();



    return 0;
}

 
