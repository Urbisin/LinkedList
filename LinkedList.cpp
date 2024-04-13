// #include "LinkedList.h"

// template <typename T>
// LinkedList<T>::LinkedList() {
//     this->head = nullptr;
// }

// template <typename T>
// LinkedList<T>::~LinkedList() {
//     while(this->head != nullptr) {
//         Node* temp = this->head;
//         this->head = this->head->next;
//         delete temp;
//     }
// }

// template <typename T>
// T LinkedList<T>::front() {
//     if(this->head == nullptr) throw "List is empty!";
//     return this->head->data;
// }

// template <typename T>
// T LinkedList<T>::back() {
//     if(this->head == nullptr) throw "List is empty!";   
//     Node* temp = this->head;
//     while(temp->next != nullptr) temp = temp->next;
//     return temp->data;
// }

// template <typename T>
// void LinkedList<T>::push_front(T data) {
//     Node* node = new Node(data);
//     node->data = data;
//     node->next = this->head;
//     this->head = node;
// }

// template <typename T>
// void LinkedList<T>::push_back(T data) {
//     Node* node = new Node(data);
//     Node* temp = this->head;
//     while (temp->next != nullptr) {
//         temp = temp->next;
//     }
//     temp->next = node;
// }

// template<typename T>
// T LinkedList<T>::pop_front() {
//     if (this->head == nullptr) {
//         throw "List is empty!";
//     }
//     Node* temp = this->head;
//     T val = temp->data;
//     this->head = this->head->next;
//     delete temp;
//     return val;
// }

// template<typename T>
// T LinkedList<T>::pop_back() { 
//     if (this->head == nullptr) {
//         delete this->head;
//         this->head = nullptr;
//         throw "List is empty!";
//     }

//     Node* aux = this->head;
//     while(aux->next->next != nullptr){
//         aux = aux->next;
//     }
//     T val = aux->next->data;
//     delete aux->next;
//     aux->next = nullptr;
//     return val; 
// }

// template<typename T>
// bool LinkedList<T>::empty() {
//     return this->head == nullptr;
// }

// template<typename T>
// T& LinkedList<T>::operator[](int index) {
//     int c = 0;
//     Node* temp = this->head;

//     while(temp != nullptr) {
//         if (c == index) {
//             return temp->data;
//         }
//         c++;
//         temp = temp->next;
//     }

//     throw "Index out of bounds";
// }

// template<typename T>
// int LinkedList<T>::size() {
//     if(this->head == nullptr) return 0;
//     Node* temp = this->head;
//     int count = 0;
//     while(temp != nullptr) {
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }

// template<typename T>
// void LinkedList<T>::clear() {
//     while(this->head != nullptr) {
//         Node* temp = this->head;
//         this->head = this->head->next;
//         delete temp;
//     }
// }

// template<typename T>
// void LinkedList<T>::sort() {
//     this->head = mergeSort(this->head);
// }

// template<typename T>
// void LinkedList<T>::reverse() {
//     // Node* temp = this->head;
//     // Node* direccion_siguiente;

//     // int c = 0;

//     // while(temp != nullptr) {
//     //     Node* temp2 = temp;
//     //     temp = temp->next;
//     //     if (c == 0) {
//     //         temp2->next = nullptr;
//     //         direccion_siguiente = temp2;
//     //         c++;
//     //         continue;
//     //     }

//     //     temp2->next = direccion_siguiente;
//     //     direccion_siguiente = temp2;
//     // }   

//     // this->head = direccion_siguiente;

//     Node* cur = this->head;
//     Node* nxt = new Node();
//     Node* prev = new Node();
//     while(cur != nullptr){
//         nxt = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = nxt;
//     }
//     this->head = prev;
// }

// template <typename T>
// void LinkedList<T>::printList() {
//     if(this->head == nullptr) throw "List is empty!";
//     Node* current = this->head;
//     while (current != nullptr) {
//         cout << current->data << " ";
//         current = current->next;
//     }
//     cout << endl;
// }

// // 3, 2, 5, 9, 10
// //       s  m       f nullptr
// // mid = s->next
// //
// // left 3 2 5 right 9 10
// // 3 2 5
// //   s m f
// // 9 10
// // s m/f

// // 2 3 5 // 9 10 
// // 2 3 5 9 10 