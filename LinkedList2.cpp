#include <bits/stdc++.h>
using namespace std;
class linked_list {
private:
    struct Node{
        int item ;
        Node *next;
    };
    Node *first , *last ;
    int length ;
public:
    linked_list() {
        first = NULL ;
        last = NULL ;
        length = 0 ;
    }
    bool isEmpty() {
        return length == 0 ;
    }

    void addToHead(int element){
        Node *newNode = new Node;

        newNode->item = element ;

        if(isEmpty()) {
            first = last = newNode;
            newNode->next = NULL ;
        }else {
            newNode->next = first ;
            first = first->next ;
            first = newNode;
        }
        length++;
    }

    void addToTail(int element) {
        Node *newNode = new Node;

        newNode->item = element ;

        if(isEmpty()) {
            first = last = newNode;
            newNode->next = NULL ;
        }else {
            last->next = newNode;
            newNode->next = NULL ;
            last = newNode ;
        }
        length++;
    }


    void addAtPosition(int pos , int value) {
        Node *prev = new Node ;

        prev->item = value ;

        if(pos < 0 || pos > length) {
            cout << "invalid position\n";
        }else if(pos == 0) {
            addToHead(value);
        }else if(pos == length) {
            addToTail(value);
        }else {
            Node *curr = first ;

           for(int i = 1 ; i < pos ; i++) {
               curr = curr->next;
           }
           prev->next = curr->next ;
           curr->next = prev;
           length++;
        }
    }








    /// functions Assignment 2;


    void DelAt(int position)
    {
        if (position < 0 || position >= length)
            cout << "ERROR: Out of range" << endl;
        else
        {
            Node *current, *trailCurrent;
            if (position == 0) {
                current = first;
                first = first->next;
                delete current;
                length--;
                if (length == 0)
                    last = NULL;
            }else {
                current = first->next;
                trailCurrent = first;
                for (int i = 1; i < position; i++)
                {
                    trailCurrent = current;
                    current = current->next;
                }

                trailCurrent->next = current->next;
                if (last == current) //delete the last item
                    last = trailCurrent;
                delete current;
                length--;
            }
        }
    }
    void update(int position , int value) {
        Node *newNode = new Node ;
        if(position < 0 || position >= length) {
            cout << "invalid position\n";
        }else  {

            newNode = first ;
            for(int i = 0 ; i < position ; i++) {

                newNode = newNode->next;
            }
          newNode->item = value ;
        }
    }
    void DelAfter(int value) {
        if (isEmpty()) {
            cout << "Error! Empty List \n";
        } else {
            Node *newNode = new Node;
            newNode->item = value;

            Node *node = first;
            int pos = 0;

            for (int i = 0; i < length; i++) {
                if (node->item == value) {
                    pos = i;
                }
                node = node->next;
            }

            DelAt(pos+1);
            length--;
        }
    }
    void addBefore(int value , int data) {

        Node *newNode = new Node;
        newNode->item = data;

        Node *node = first;
        int pos = 0;

        for (int i = 0; i < length; i++) {
            if (node->item == value) {
                pos = i;
            }
            node = node->next;
        }

        addAtPosition(pos  , data);
        length++;
    }
    void print() {
        Node *newNode = new Node ;
        newNode = first ;
        while(newNode != NULL){
            cout << newNode->item << " " ;
            newNode = newNode->next ;

        }
        cout << "\n";
    }




};


int main() {

   linked_list l ;
   l.addToHead(10);
   l.addToHead(20);
   l.addToHead(30);
   l.addToHead(40);

    l.update(0 , 5);
    l.DelAt(1);
    l.DelAfter(20);
    l.addBefore(20 , 3) ;

   l.print();
return 0;
}
