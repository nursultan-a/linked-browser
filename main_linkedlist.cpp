#include <iostream>

#include "LinkedList.hpp"

using namespace std;

int main() {
    LinkedList<int> llist;


    llist.printAllNodes();

    llist.insertAtTheEnd(1);
    llist.insertAtTheEnd(7);
    llist.insertAtTheEnd(4);

    llist.printAllNodes();

    // cout << "--------------" << endl;
    // LinkedList<int> newList(llist);
    // cout << "-------nl after cc-------" << endl;
    // newList.printAllNodes();

    // newList.insertAtTheEnd(9999);
    // cout << "-------nl  after add-------" << endl;
    // newList.printAllNodes();
    // cout << "-------ll  after changing nl-------" << endl;
    // llist.printAllNodes();

    llist.removeNode(llist.findNode(4));
    llist.printAllNodes();

    return 0;
}