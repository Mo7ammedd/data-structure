#include <bits/stdc++.h>
using namespace std;

const int max_size = 100 ;
template<class t>
class Stack {

private :
    int top ;
    t arr[max_size];

public:
    Stack() {
        top = -1;

    }

    bool isEmpty()  {
        return (top == -1);

    }

    int getTop() {
        return arr[top];
    }

    void push(t element) {
          if(top >= max_size - 1) {
              cout << "Stack Full Cannot Push\n";
          }else {
              top++;
              arr[top] = element;
          }
    }

    void pop() {
        if(isEmpty()) {
            cout << "Stack Empty Cannot Push\n";

        }else {
            top--;

        }
    }
    void print() {
        for(int i = top ; i >= 0 ; i--) {
            cout << arr[i] << " ";
        }
    }

    int searchStack(t element) {
        int pos = 0 ;
        bool found = true ;
        for(int i = top ; i >= 0 ; i++) {
            if(arr[i] == element) {
                pos = i ;
                found = false ;
            }
        }
        if(!found) return pos ;
        else return -1;

    }


    bool isPalindrome(string str) {
        Stack <char> c ;

        string res ;
        for(int i = 0 ; i < str.size() ; i++) {
            c.push(str[i]);
        }

        while(!c.isEmpty()) {
            res.push_back(c.getTop());
            c.pop();

        }

        return (res == str);

    }

    void Binary_Num(int num) {
        Stack <int> s ;
        int n = num ;
        while(n > 0) {
            s.push(n % 2);
            n /= 2 ;


        }
       while(!s.isEmpty()) {
           cout << s.getTop() ;
           s.pop();
       }
    }




};

int main() {
   

    Stack <int> s1;

 //   s1.push(7);
   cout << s1.isPalindrome("ACC") << "\n";
  s1.Binary_Num(7);

//    s1.print();

  
    return 0;
}

