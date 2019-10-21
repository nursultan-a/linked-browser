#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"

using namespace std;

template <class T>
class LinkedList
{
    public: // DO NOT CHANGE THIS PART.
        LinkedList();
        LinkedList(const LinkedList &obj);

        ~LinkedList();

        Node<T> *getFirstNode() const; //
        Node<T> *getHead() const;
        Node<T> *getTail() const;
        int getNumberOfNodes();
        bool isEmpty(); //

        void insertAtTheFront(const T &data); //
        void insertAtTheEnd(const T &data); //
        void insertAfterGivenNode(const T &data, Node<T> *prev); //

        void removeNode(Node<T> *node);
        void removeAllNodes();

        Node<T> *findNode(const T &data); //

        void printAllNodes();
        void printReversed();

        LinkedList &operator=(const LinkedList &rhs);

    private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

    private: // DO NOT CHANGE THIS PART.
        Node<T> *head;
        Node<T> *tail;
};

template<class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
    /* constructor for without any argument*/
    head->next = tail;
    tail->prev = head;

}

// copy constructor
template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj)
{
    /* TODO */
    LinkedList<T>  *givenCurrent;
    LinkedList<T>  *newCurrent;

    givenCurrent = obj->head;

    if(givenCurrent != NULL){
        
        this->head = obj->head;
        this->tail = obj->tail;


        givenCurrent = givenCurrent->next;

        while(givenCurrent != this->tail){
            Node<T> newNode = new Node<T>;
            newNode 


            

        }
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
}

template<class T>
Node<T> * LinkedList<T>::getFirstNode() const
{
    /* TODO */
    return this.head->next;
}

template<class T>
Node<T> * LinkedList<T>::getHead() const
{
    /* TODO */
    return this.head;
}

template<class T>
Node<T> * LinkedList<T>::getTail() const
{
    /* TODO */
    return this.tail;
}

template<class T>
int LinkedList<T>::getNumberOfNodes() 
{
    /* TODO */
    int counter = 0;
    Node<T> *current = this.head;
    while(current != NULL){
        counter++;
        current = current->next;
    }
    return counter;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    /* TODO */
    return this.head->next == this.tail;
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data)
{
    /* TODO */
    data->next = this.head->next;
    this.head->next->prev = data;

    this.head->next = data;
    data.prev = this.head;
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data)
{
    /* TODO */
    data->next = tail;
    tail->prev = data;
    
    data->prev = tail->prev;
    tail->prev->next = data;
}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev)
{   
    /* TODO */
    Node<T> *tmp = prev;

    prev->next = data;

    data->prev = prev;
    data->next = tmp->next;
    tmp->next->prev = data;

}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
}

template<class T>
Node<T> * LinkedList<T>::findNode(const T &data)
{
    /* TODO */
}

template<class T>
void LinkedList<T>::printAllNodes()
{
    /* TODO */
    Node<T> *current = head->next;
    while(current != tail){
        cout << current->element << endl;
        current = current->next;
    }

}

template<class T>
void LinkedList<T>::printReversed()
{
    /* TODO */
    Node<T> *current = tail->prev;
    while(current != head){
        cout << current->element << endl;
        current = current->prev;
    }
}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs)
{
    /* TODO */
}

#endif //LINKED_LIST_HPP
