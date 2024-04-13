#include <iostream>
using namespace std;


template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node() : next(nullptr) {}
        Node(int x) : data(x), next(nullptr) {}
        Node(int x, Node *next) : data(x), next(next) {}
        void killself(){delete this;}
    };

    Node* head;

    Node* merge(Node* a, Node* b) {
        Node* dummyHead = new Node();
        Node* current = dummyHead;

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

        Node* sortedHead = dummyHead->next;
        delete dummyHead;
        return sortedHead;
    }

    Node* mergeSort(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* mid = slow->next;
        slow->next = nullptr;

        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);

        return merge(left, right);
    }

public:


    LinkedList() {
        head = nullptr;
    }


    ~LinkedList() {
        while(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    T front() {
        if(head == nullptr) throw runtime_error("List is empty!");
        return head->data;
    }


    T back() {
        if(head == nullptr) throw runtime_error("List is empty!");  
        Node* temp = head;
        while(temp->next != nullptr) temp = temp->next;
        return temp->data;
    }


    void push_front(T data) {
        Node* node = new Node(data);
        if(head == nullptr){
            head = node;
            return;
        }
        
        node->data = data;
        node->next = head;
        head = node;
    }


    void push_back(T data) {
        Node* node = new Node(data);
        if(head == nullptr){
            head = node;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }

    

    T pop_front() {
        if (head == nullptr) {
            throw runtime_error("List is empty!");
        }
        Node* temp = head;
        T val = temp->data;
        head = head->next;
        delete temp;
        return val;
    }


    T pop_back() { 
        if (head == nullptr) {
            throw runtime_error("List is empty!");
        }

        T ret;
        if (head->next == nullptr) {
            ret = head->data;
            delete head;
            head = nullptr;
        }else{
            Node* prev = nullptr;
            Node* cur = head;
            while(cur->next != nullptr) {
                prev = cur;
                cur = cur->next;
            }
            ret = cur->data;
            delete cur;
            prev->next = nullptr;
        }
        return ret;
    }

    
    T& operator[](int index) {
        int c = 0;
        Node* temp = head;

        while(temp != nullptr) {
            if (c == index) {
                return temp->data;
            }
            c++;
            temp = temp->next;
        }

        throw runtime_error("Index out of bounds!");
    }
    
    bool empty() {
        return head == nullptr;
    }

    
    int size() {
        if(head == nullptr) return 0;
        Node* temp = head;
        int count = 0;
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    
    void clear() {
        while(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    
    void printList() {
        if(head == nullptr) throw "List is empty!";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }


    void sort() {
        head = mergeSort(head);
    }


    void reverse() {
        Node* temp = head;
        Node* direccion_siguiente;

        int c = 0;

        while(temp != nullptr) {
            Node* temp2 = temp;
            temp = temp->next;
            if (c == 0) {
                temp2->next = nullptr;
                direccion_siguiente = temp2;
                c++;
                continue;
            }

            temp2->next = direccion_siguiente;
            direccion_siguiente = temp2;
        }   

        head = direccion_siguiente;
    }
};

