#include <iostream>
using namespace std;

struct Node {
    int Data;
    Node* next;
};

class LinkedList {
    Node* head;
    Node* tail;
    int count;

public:
    LinkedList() : head(NULL), tail(NULL), count(0) {}

    void add(int data) {
        Node* newNode = new Node;
        newNode->Data = data;


        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->Data << " -> ";
            current = current->next;
        }
        //cout << "TEST" << endl;
    }

     //1. indsert node after given node
        void InsertAfter(int data, int afterData){
        Node * current = head;
        Node * newNode = new Node;
        newNode->Data = data;

        while(current != NULL && current->Data != afterData ){
            current = current->next;
        }

         newNode->next = current->next;
         current->next = newNode;

         if(current == tail)
            tail = newNode;

        count++;
        }




        void InsertBefore(int data, int beforeData)
{
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL && current->Data != beforeData)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    Node* newNode = new Node;
    newNode->Data = data;

    // Insert before head
    if (prev == NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        newNode->next = current;
        prev->next = newNode;
    }

    count++;
}


    int GetCount()
    {
    return count;
    }

    int GetDataByIndex(int index)
        {
            if (index < 0 || index >= count)
            return -1;

        Node* current = head;

        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->Data;
        }

};

int main() {
    cout << "Hello world!" << endl;
    LinkedList n1;
    n1.add(10);
    n1.add(20);
    n1.display();
    n1.InsertAfter(1,10);
    n1.display();
    n1.InsertBefore(2,10);
    n1.display();
    cout << "==============";
    cout << n1.GetCount()<<endl;
    cout << n1.GetDataByIndex(3);
    return 0;
}
