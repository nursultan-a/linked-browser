#include <iostream>

#include "LinkedList.hpp"

using namespace std;

int main() {
    LinkedList<int> llist;

    // Default constructor
    cout << "--- Default constructor start---" << endl;
    llist.printAllNodes();
    cout << "--- Default constructor start---" << endl;
    cout << "##########" << endl;
    cout << "--- Print all nodes start ---" << endl;
    llist.printAllNodes();
    cout << "---Print all nodes end ---" << endl;

    
    cout << "##########" << endl;
    cout << "--- Insert at the end accordingly [1, 7, 4, 444] start ---" << endl;
    llist.insertAtTheEnd(1);
    llist.insertAtTheEnd(7);
    llist.insertAtTheEnd(4);
    llist.insertAtTheEnd(444);
    cout << "--- Insert at the end accordingly [1, 7, 4, 444] end ---" << endl;

    cout << "##########" << endl;
    cout << "--- Print all nodes start ---" << endl;
    llist.printAllNodes();
    cout << "---Print all nodes end ---" << endl;

    cout << "##########" << endl;
    cout << "--- Get number of nodes start ---" << endl;
    cout << llist.getNumberOfNodes()<< endl;
    cout << "--- Get number of nodes end ---" << endl;


    cout << "##########" << endl;
    cout << "--- print Reversed start ---" << endl;
    llist.printReversed();
    cout << "--- print Reversed end ---" << endl;


    cout << "##########" << endl;
    cout << "--- copy constructor start ---" << endl;
    LinkedList<int> newList(llist);
    cout << "---- created newList deep copying llist start ----" << endl;
    newList.printAllNodes();
    cout << "---- created newList deep copying llist endl ----" << endl;
    cout << "---- Print all nodes of llist start ----" << endl;
    llist.printAllNodes();
    cout << "---Print all nodes of llist end ---" << endl;
    cout << "---- changing llist and newList each ---" << endl;
    llist.insertAtTheFront(6554);
    newList.insertAtTheEnd(6677);
    cout << "---- changed newList start ----" << endl;
    newList.printAllNodes();
    cout << "---- created newList endl ----" << endl;
    cout << "---- llist start ----" << endl;
    llist.printAllNodes();
    cout << "---- llist end ---" << endl;
    cout << "--- copy constructor end ---" << endl;

    cout << "##########" << endl;
    cout << "--- Remove node with data 4 from llist start ---" << endl;
    llist.removeNode(llist.findNode(4));
    llist.printAllNodes();
    cout << "--- Remove node with data 4 from llist end ---" << endl;
    

    cout << "##########" << endl;
    cout << "------remove all nodes of llist start --------" << endl;
    llist.removeAllNodes();
    cout << llist.getNumberOfNodes()<< endl;
    cout << "------remove all nodes of llist end --------" << endl;

    cout << "##########" << endl;
    cout << "--- insert after given node start ---" << endl;
    cout << "--- before insertion 9000 after 4 ---" << endl;
    newList.printAllNodes();
    newList.insertAfterGivenNode(9000, newList.findNode(4));
    cout << "--- after insertion 9000 after 4 ---" << endl;
    newList.printAllNodes();


    return 0;
}