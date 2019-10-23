#include <iostream>

#include "LinkedList.hpp"

using namespace std;

int main() {
    LinkedList<int> llist;

    llist.insertAtTheEnd(1);
    llist.insertAtTheEnd(7);
    llist.insertAtTheEnd(4);
    llist.insertAtTheEnd(444);
    llist.insertAtTheFront(444);
    llist.insertAtTheFront(444);

    llist.printAllNodes();


    // LinkedList<int> newList = llist;
    

    // llist.removeNode(llist.findNode(7));
    // llist.removeAllNodes();
    // llist.findNode(3);
    // llist.printAllNodes();

    

    return 0;
}