#include <iostream>

using namespace std;

template <typename T>
struct Node  {
    T data;
    Node* next;
};



template <typename T>
Node<T>* arrayToList(const T arr[], size_t size){
    Node<T> *tmp = NULL;

    for (int i = 0; i < size; i++) {
        Node<T> *temp = new Node<T>;
        Node<T> *ptr;
        temp->data = arr[i];
        temp->next = NULL;

        if (tmp == NULL)
            tmp = temp;
        else {
            ptr = tmp;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }
    return tmp;
}

template <typename T, typename Pred>
void removeBad(Node<T>*& head, Pred p){
    Node<T>* curr = head;
    Node<T>* prev = nullptr;
    while (curr != nullptr) {
        if (p(curr->data)) {
            std::cout << "DEL " << curr->data << "; ";
            if (prev == nullptr) {
                head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            Node<T>* temp = curr;
            curr = curr->next;
            delete temp;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    std::cout << std::endl;
}


template <typename T>
void showList(const Node<T>* head){
    if (head == nullptr) std::cout << "Empty list";
    while (head != nullptr) {
        std::cout << head->data;
        if (head->next != nullptr) {
            std::cout << " ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

template <typename T>
void deleteList(Node<T>*& head){
    while (head != nullptr) {
        std::cout << "deleting " << head->data << "; ";
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    std::cout << std::endl;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    size_t size = std::size(arr);
    Node<int>* head = arrayToList(arr,size);
    showList(head);
    removeBad(head, [](int n) {return n%2 != 0;});
    showList(head);
    removeBad(head, [](int n) {return n < 5;});
    showList(head);
    removeBad(head, [](int n) {return n > 9;});
    showList(head);
    deleteList(head);
    showList(head);
}