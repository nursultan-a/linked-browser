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
    head = new Node<T>;
    tail = new Node<T>;

    head->next = tail;
    tail->prev = head;

}

// copy constructor
template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj)
{
    /* TODO */
    head = new Node<T>;
    tail = new Node<T>;

    Node<T>  *givenCurrent;
    Node<T>  *newCurrent;

    givenCurrent = obj.head;

    if(givenCurrent != NULL){

        givenCurrent = givenCurrent->next;

        head->next = new Node<T>(givenCurrent->element, head, NULL);
        newCurrent = head->next;


        while(givenCurrent != obj.tail){
            givenCurrent = givenCurrent->next;
            newCurrent->next = new Node<T>(givenCurrent->element, newCurrent, NULL);

            newCurrent = newCurrent->next;
        }
        tail = new Node<T>;
        tail->prev = newCurrent;
        newCurrent->next = tail;
    }
    else{
        head->next = tail;
        tail->prev = head;
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
    Node<T> *current = head->next;
    Node<T> *tmp = NULL;
    delete head;
    if(current != tail){
        while(current != tail){
            tmp = current;
            current = current->next;

            delete tmp;
        }        
    }
    delete tail;
}

template<class T>
Node<T> * LinkedList<T>::getFirstNode() const
{
    /* TODO */
    if(head->next != tail){
        return this->head->next;
    }else{
        return NULL;
    }
}

template<class T>
Node<T> * LinkedList<T>::getHead() const
{
    /* TODO */
    return this->head;
}

template<class T>
Node<T> * LinkedList<T>::getTail() const
{
    /* TODO */
    return this->tail;
}

template<class T>
int LinkedList<T>::getNumberOfNodes() 
{
    /* TODO */
    int counter = 0;
    Node<T> *current = head->next;
    if(current == tail){
        return 0;
    }else{
        while(current != tail){
            counter++;
            current = current->next;
        }
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
    Node<T> *newNode = new Node<T>(data, head, NULL);
    Node<T> *next = head->next;
    head->next = newNode;

    if(next == tail){
        tail->prev = newNode;
        newNode->next = tail;
    }else{
        newNode->next = next;
        next->prev = newNode;        
    }


}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data)
{
    /* TODO */
    Node<T> *tmp = tail->prev;
    tmp->next = new Node<T>(data, tmp, tail);
    tail->prev = tmp->next;
}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev)
{   
    /* TODO */
    Node<T> *next = prev->next;
    Node<T> *newNode = new Node<T>(data, prev, next);
    next->prev = newNode;
    prev->next = newNode;

}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
    if(node != NULL){
        Node<T> *prev = node->prev;
        Node<T> *next = node->next;

        prev->next = next;
        next->prev = prev;

        delete node;//CHECK: is it right way?
    }
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    Node<T> *current = head->next;
    
    while(current != tail){
        Node<T> *deletable = current;
        current = current->next;

        delete deletable;

    }
    tail->prev = head;
    head->next = tail;
}

template<class T>
Node<T> * LinkedList<T>::findNode(const T &data)
{
    /* TODO */

    Node<T> *current = head->next;
    while(current != tail){
        if(current->element == data){
            return current;
        }
        current = current->next;
    }
    return NULL;
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
