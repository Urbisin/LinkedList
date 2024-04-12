#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

Node<T>* merge(Node<T>* a, Node<T>* b) {
    Node<T>* dummyHead = new Node<T>();
    Node<T>* current = dummyHead;

    while (a != nullptr && b != nullptr) {
        if (a->data < b->data) {
            current->next = a;
            a = a->next;
        } else {
            current->next = b;
            b = b->next;
        }
        current = current->next;
    }

    if (a != nullptr) {
        current->next = a;
    } else {
        current->next = b;
    }

    Node<T>* sortedHead = dummyHead->next;
    delete dummyHead;
    return sortedHead;
}

Node<T>* mergeSort(Node<T>* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node<T>* slow = head;
    Node<T>* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node<T>* mid = slow->next;
    slow->next = nullptr;

    Node<T>* left = mergeSort(head);
    Node<T>* right = mergeSort(mid);

    return merge(left, right);
}

public:

    LinkedList();
    ~LinkedList();

    T front();
    T back();

    void push_front(T data);
    void push_back(T data);

    void pop_front();
    void pop_back();

    T& operator[](int index);

    bool empty();
    int size();

    void clear();

    void printList();

    void sort();
    void reverse();
};

