#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
        while(head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

template <typename T>
T LinkedList<T>::front() {
    return this->head->data;
}

template <typename T>
T LinkedList<T>::back() {
    Node<T>* temp = head;
    T result;

    while(temp->next != nullptr) {
        temp = temp->next;
    }

    result = temp->data;

    return result;
}

template <typename T>
void LinkedList<T>::push_front(T data) {
    Node<T>* temp = new Node<T>;
    temp->data = data;
    if (head == nullptr) {
        head = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

template <typename T>
void LinkedList<T>::push_back(T data) {
        Node<T>* temp = new Node<T>;
        temp->data = data;
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
        } 
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = temp;
        }
    }

template<typename T>
void LinkedList<T>::pop_front() {
    if (head == nullptr) {
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

template<typename T>
void LinkedList<T>::pop_back() {
    
    if (head == nullptr) {
        return;
    }

    Node<T>* temp = head;
    Node<T>* aux;
    
    while(temp->next != nullptr) {
        if (temp->next->next == nullptr) {
            aux = temp->next;
            temp->next = nullptr;
            break;
        }
        temp = temp->next;
    }

    delete aux;

}

template<typename T>
bool LinkedList<T>::empty() {
    return head == nullptr;
}

template<typename T>
T& LinkedList<T>::operator[](int index) {
    int c = 0;
    Node<T>* temp = head;

    while(temp != nullptr) {
        if (c == index) {
            return temp->data;
        }
        c++;
        temp = temp->next;
    }

    throw "Index out of bounds";
}

template<typename T>
int LinkedList<T>::size() {
    Node<T>* temp = head;
    int count = 0;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

template<typename T>
void LinkedList<T>::clear() {
    while(head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void LinkedList<T>::sort() {
    head = mergeSort(head);
}

template<typename T>
void LinkedList<T>::reverse() {
    Node<T>* temp = head;
    Node<T>* direccion_siguiente;

    int c = 0;

    while(temp != nullptr) {
        Node<T>* temp2 = temp;
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

template <typename T>
void LinkedList<T>::printList() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// 3, 2, 5, 9, 10
//       s  m       f nullptr
// mid = s->next
//
// left 3 2 5 right 9 10
// 3 2 5
//   s m f
// 9 10
// s m/f

// 2 3 5 // 9 10 
// 2 3 5 9 10 