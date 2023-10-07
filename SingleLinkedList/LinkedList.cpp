#include "LinkedList.h"
#include <iostream>
using namespace std;

Node::Node(int value) : data(value), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::display() {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << endl;
    cout << "nullptr" << std::endl;
    cout << "\n" << std::endl;
}

void LinkedList::insertFromArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        append(arr[i]);
    }
}

void LinkedList::insertAt(int position, int value) {
    Node* newNode = new Node(value);
    if (position <= 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        int currentPosition = 0;
        while (current && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }
        if (current) {
            newNode->next = current->next;
            current->next = newNode;
        }
        else {
            cout << "Invalid position. Insertion failed." << std::endl;
        }
    }
}

void LinkedList::insertBefore(int targetValue, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    if (head->data == targetValue) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next && current->next->data != targetValue) {
        current = current->next;
    }
    if (current->next) {
        newNode->next = current->next;
        current->next = newNode;
    }
    else {
        cout << "Target value not found. Insertion failed." << std::endl;
    }
}

void LinkedList::insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtTail(int value) {
    append(value);
}

void LinkedList::displayMenu() { // will be displayed until user gives input
    cout << "------------------"<<" Single LinkList by ANT6117 "<<"--------";
    cout << "\n\n\n------------------" << "  Thanks to  CHATGPT  " << "----------------" << endl;
    cout << "\n I learned this from it" << endl;
    cout << "\n\n\n";
   
    cout << "Linked List Menu:" << std::endl;
    cout << "1. Insert a value at the head" << std::endl;
    cout << "2. Insert a value at the tail" << std::endl;
    cout << "3. Insert a value at a specific position" << std::endl;
    cout << "4. Insert a value before a specific value" << std::endl;
    cout << "5. Display the linked list" << std::endl;
    cout << "6. Exit" << std::endl;

   
}

void LinkedList::userInputOperations() { // simple just make a menu 
    int choice;
    while (true) {
        displayMenu();
       
       
        cout << "\n\nEnter your choice: "<<endl;
        std::cin >> choice;
        

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter a value to insert at the head: ";
            std::cin >> value;
            insertAtHead(value);
            break;
        }
        case 2: {
            int value;
            cout << "Enter a value to insert at the tail: ";
            std::cin >> value;
            insertAtTail(value);
            break;
        }
        case 3: {
            int value, position;
            cout << "Enter a value to insert: ";
            std::cin >> value;
            cout << "Enter the position to insert at: ";
            std::cin >> position;
            insertAt(position, value);
            break;
        }
        case 4: {
            int value, targetValue;
            cout << "Enter a value to insert: ";
            std::cin >> value;
            cout << "Enter the target value before which to insert: ";
            std::cin >> targetValue;
            insertBefore(targetValue, value);
            break;
        }
        case 5:
            cout << "Linked List: ";
            display();
            break;
        case 6:
            return;
        default:
            cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
