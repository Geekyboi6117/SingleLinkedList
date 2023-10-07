#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void append(int value);
    void display();
    void insertFromArray(int arr[], int size);
    void insertAt(int position, int value);
    void insertBefore(int targetValue, int value);
    void insertAtHead(int value);
    void insertAtTail(int value);
    void displayMenu();
    void userInputOperations();
};

#endif
