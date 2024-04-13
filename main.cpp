#include <iostream>
#include "LinkedList.h"

using namespace std;

//generado con chatgpt 

int main() {
    // Create a LinkedList of integers
    LinkedList<int> intList;

    // Test empty list
    try {
        cout << "Is the list empty? " << (intList.empty() ? "Yes" : "No") << endl; // Should output: Yes
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    // Test push_front and push_back on empty list
    intList.push_front(1);
    intList.push_back(2);
    cout << "List after push_front and push_back on empty list: ";
    try {
        intList.printList(); // Should output: 1 2
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    // Test size of the list
    cout << "Size of the list: " << intList.size() << endl; // Should output: 2

    // Test front and back on non-empty list
    try {
        cout << "Front element: " << intList.front() << endl; // Should output: 1
        cout << "Back element: " << intList.back() << endl;   // Should output: 2
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    // Test pop_front
// Test pop_front
    try {
        intList.pop_front();
        cout << "List after pop_front: ";
        if (!intList.empty()) {
            intList.printList(); // Should output: 2
        } else {
            cout << "List is empty" << endl;
        }
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }


    // Test pop_back
    try {
        intList.pop_back();
        cout << "List after pop_back: ";
        intList.printList(); // Should output nothing
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    // Test size of the list after popping elements
    cout << "Size of the list after popping elements: " << intList.size() << endl; // Should output: 0

    // Test empty list after popping elements
    try {
        cout << "Is the list empty after popping elements? " << (intList.empty() ? "Yes" : "No") << endl; // Should output: Yes
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    // Test pushing elements back to an empty list
    intList.push_back(3);
    intList.push_back(4);
    intList.push_back(5);
    cout << "List after pushing elements back to an empty list: ";
    try {
        intList.printList(); // Should output: 3 4 5
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    // Test reverse on non-empty list
    try {
        intList.reverse();
        cout << "Reversed List: ";
        intList.printList(); // Should output: 5 4 3
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    return 0;
}
