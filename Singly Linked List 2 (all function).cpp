#include<iostream>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& data, Node<T>* next = NULL) {
        this->data = data;
        this->next = next;
    }
};

template<class T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() {
        head = NULL;
        size = 0;
    }

    ~LinkedList() {
        Node<T>* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtStart(T const element) {
        Node<T>* newNode = new Node<T>(element, head);
        head = newNode;
        size++;
    }

    void insertAtEnd(T const element) {
        Node<T>* newNode = new Node<T>(element);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node<T>* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void print() const {
        if (head == NULL) {
            cout << "The list is empty." << std::endl;
            return;
        }
        Node<T>* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    bool search(T const& element) const {
        Node<T>* curr = head;
        while (curr != NULL) {
            if (curr->data == element) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    bool isEmpty() const {
        return head == NULL;
    }

    bool insertBefore(T const v1, T const v2) {
        if (head == NULL) {
            return false;
        }
        if (head->data == v2) {
            Node<T>* newNode = new Node<T>(v1, head);
            head = newNode;
            size++;
            return true;
        }
        Node<T>* prev = head;
        Node<T>* curr = head->next;
        while (curr != NULL) {
            if (curr->data == v2) {
                Node<T>* newNode = new Node<T>(v1, curr);
                prev->next = newNode;
                size++;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    void deleteAll(T const value) {
        Node<T>* prev = NULL;
        Node<T>* curr = head;
        while (curr != NULL) {
            if (curr->data == value) {
                if (prev == NULL) {
                    head = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
                Node<T>* temp = curr;
                curr = curr->next;
                delete temp;
                size--;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void deleteAtStart() {
        if (head == NULL) {
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    void reverse() {
        Node<T>* prev = NULL;
        Node<T>* curr = head;
        Node<T>* next;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
      
        head = prev;
    }

};




int main() {
    LinkedList<int> list;

    list.insertAtStart(2);
    list.insertAtStart(6);
    list.insertAtStart(7);
    list.insertAtEnd(9);
    list.insertAtStart(9);
    list.insertAtStart(8);
    list.insertAtStart(7);
    list.deleteAll(7);

     cout << "Linked list: ";
    list.print();

    cout << "2 is " << (list.search(2) ? "" : "not ") << "found." <<endl;
    cout << "9 is " << (list.search(9) ? "" : "not ") << "found." << endl;
    list.deleteAtStart();
    list.reverse();
     list.print();
     
 }
