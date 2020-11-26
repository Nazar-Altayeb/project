/*
My name:Nazar Altayeb Osman Alkhalifa
Class:Second
Department:Computer
 */
#include <iostream>
#include <vector>
#include<cassert>


using namespace std;

const int the_size = 10; //as constant for all of stack ,Queue and Linked list 
class Stack {// class stack
    int top;
    int items[the_size];
public:
    Stack() {//constructor of class stack
        top = -1;
    }
    void push(int element) {//function for adding elements
        if (top >= the_size - 1) {
            cout << "Sorry Stack is full";
        }
        else {
            top++;
            items[top] = element;
        }
    };
    bool stack_isEmpty() {//function to check if stack is empty
        return top < 0;
    }
    void pop() {//function for deleting element from stack
        if (stack_isEmpty())
            cout << "Stack empty Can't delete";
        else {
            top--;
        }
    };

    void the_top(int& topelement) {//to show what is the top
        if (stack_isEmpty())
            cout << "Stack empty ";
        else {
            topelement = items[top];
            cout << topelement;
        }
    };

    void printStack() {//function for print stack elements
        cout << "The Stack elements are: " << endl;
        for (int index = top; index >= 0; index--) {
            cout << items[index] << endl;

        }

    }

};


class Queue {//class Queue
    int tail;
    int head;
    int counter;
    int container[the_size];
public:
    Queue() {//constructor of Queue
        head = 0;
        tail = the_size - 1;
        counter = 0;

    }
    bool embty() {//check if empty
        return counter == 0;
    }
    bool full() {
        return counter == the_size;
    }
    void addElement(int element) {//add element
        if (full()) {
            cout << "Queue is Full...no way to add element";
        }
        else {
            tail = (tail + 1) % the_size;
            container[tail] = element;
            counter++;
        }


    };


    void deleteElement() {//delele element
        if (embty()) {
            cout << "Queue is Empty ...no elements to delete";
        }
        else {
            head = (head + 1) % the_size;
            counter--;
        }

    };
    int headQueue() {//Queue head
        assert(!embty());

        return container[head];
    }
    int tailQueue() {//Queue tail
        assert(!embty());
        return container[tail];
    }
    int QueueSearch(int element) {//Queue search
        int postion = -1;
        if (!embty()) {
            for (int i = head; i != tail; i = (i + 1) % the_size)
                if (container[i] == element) {
                    postion = i;
                    break;
                }
            if (postion == -1) {
                if (container[tail] == element)
                    postion = tail;
            }
        }
    }
    void printQueue() {//print Queue element
        if (!embty()) {
            int index = head - 1;
            while (index != tail) {
                index = (index = index + 1);
                cout << container[index] << " ";
            }
        }
        else
            cout << "Queue is Empty";



    }






};

class LinkedList {//link list class
    struct Node {//node struct
        int item;
        Node* next;
    };
    Node* first;
    Node* last;
    int counter;
public:
    LinkedList() {//constructor of linked list
        first = last = NULL;
        counter = 0;
    }

    bool embty() {//check if embty
        return counter == 0;

    }
    void insertFirstelement(int element) {//insert first element
        Node* newNode = new Node;
        newNode->item = element;
        if (counter == 0) {
            first = last = newNode;
            newNode->next = NULL;

        }
        else {
            newNode->next = first;
            first = newNode;

        }counter++;
    }
    void insertLastelement(int element) {//insert first element
        Node* newNode = new Node;
        newNode->item = element;
        if (counter == 0) {
            first = last = newNode;
            newNode->next = NULL;
        }
        else {
            last->next = newNode;
            newNode->next = NULL;
            last = newNode;
        }
        counter++;
    }
    void insertPoselement(int pos, int element) {
        if (pos<0 || pos>counter)
            cout << "Out Of Range";
        else {
            Node* newNode = new Node;
            newNode->item = element;
            if (pos == 0)
                insertFirstelement(element);
            else if (pos == counter) insertLastelement(element);
            else {
                Node* Cur = first;
                for (size_t i = 1; i < pos; i++) {
                    Cur = Cur->next;
                }

                newNode->next = Cur->next;
                Cur->next = newNode;
                counter++;
            }

        }


    }


    void print() {//print the list elements
        Node* Cur = first;
        while (Cur != NULL) {
            cout << Cur->item << " ";

            Cur = Cur->next;
        }
    }
    void removeFirst() {//remove the first element
        if (counter == 0)
            cout << "The List is Empty" << endl;
        else if (counter == 1) {
            delete first;
            last = first = NULL;
            counter--;
        }
        else {
            Node* current = first;
            first = first->next;
            delete current;
            counter--;

        }


    }
    void removeLast() {//remove the last element
        Node* curr = first->next;
        Node* prev = first;
        while (curr != last) {
            prev = curr;
            curr = curr->next;
        }
        delete curr;
        prev->next = NULL;
        last = prev;
        counter = counter - 1;

    }


};

int main() {

    Stack stack1; //stack object 
    stack1.push(11);//add 
    stack1.push(20);//add 
    stack1.push(45);//add 
    stack1.push(29);//add 
    stack1.pop();//delete element 
    stack1.push(56);//add 
    stack1.pop();//delete element


    Queue queue1; //Queue object 
    queue1.addElement(25);//add
    queue1.addElement(35);//add
    queue1.addElement(55);//add
    queue1.deleteElement();//delete element
    queue1.addElement(65);//add
    queue1.addElement(58);//add
    queue1.deleteElement();//delete element


    LinkedList list1;//object LinkedList
    list1.insertFirstelement(12);//add
    list1.insertLastelement(14);//add
    list1.insertLastelement(70);//add
    list1.insertLastelement(45);//add
    list1.removeFirst();//delete element
    list1.insertFirstelement(55);//add
    list1.removeLast();//delete element



    cout << "************************" << endl;
    cout << "*       Main Menu      *" << endl;
    cout << "************************" << endl;
    cout << "1-Stack" << endl;
    cout << "2-Queue" << endl;
    cout << "3-Linked lists" << endl;
    cout << "Enter Selection....";
    int choice;
    cin >> choice;

    if (choice == 1)
        stack1.printStack();
    else if (choice == 2)
        queue1.printQueue();
    else if (choice == 3)
        list1.print();
    else
        cout << "incorrect Selection...";

    return 0;
}
