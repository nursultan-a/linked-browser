#include <iostream>

#include "LinkedList.hpp"

using namespace std;

int main() {
    LinkedList<int> llist;

   
    llist.insertAtTheEnd(7);
    llist.insertAtTheEnd(4);
    llist.insertAtTheEnd(444);
    llist.insertAtTheFront(444);
    llist.insertAtTheFront(444);

    Node<int> *dNode = llist.findNode(4);

    llist.printAllNodes();

    llist.removeNode(dNode);
    llist.removeNode(dNode);

    // LinkedList<int> newList = llist;
    

   
    // llist.removeAllNodes();
    // llist.printAllNodes();
    // llist.findNode(3);
    // llist.printAllNodes();

    

    return 0;
}