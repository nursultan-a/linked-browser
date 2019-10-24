#include <iostream>

#include "WebHistory.hpp"

int main() {

    WebHistory wh1("www.google.com", 99);
    Tab nTab("akyptan.com", 5);

    Node<Tab> *page = new Node<Tab>(nTab, NULL, NULL);
    wh1.insertInOrder(page);

    WebHistory wh2("www.metu.edu.tr", 100);

    WebHistory wh3 = wh2+wh1;
    wh3.printHistory();

    WebHistory wh4("www.metu.edu.tr", 1);
    WebHistory wh5("www.metu.edu.tr", 2);
    WebHistory wh6("www.metu.edu.tr", 3);
    WebHistory wh7("www.metu.edu.tr", 11);
    
    wh3 = wh3+wh4;
    wh3 = wh3+wh5;
    wh3 = wh3+wh6;
    wh3 = wh3+wh7;


    wh3.printHistory();

    cout << "most visited page: " << wh3.mostVisited() << endl;





    // Default given inputs
    //WebHistory p1("www.youtube.com 4 | www.ceng.metu.edu.tr 8 | www.youtube.com/watch?v=4lYDblvvxE4 5 | https://www.youtube.com/watch?v=0lR1tt24mo4 9 | www.ntv.com.tr 10 | https://www.instagram.com/megadeth 1");
    
    // WebHistory p2("www.instagram.com 1 | www.facebook.com 7 | https://www.youtube.com/watch?v=s9pZxnJAwQI 4 | https://www.youtube.com/watch?v=-gDinVAmtA0 8 | www.ntv.com.tr 9 | https://www.instagram.com/pinkfloyd/ 99");

    //p1.printHistory();
    //std::cout << std::endl;
    // p2.printHistory();
	
	// p1.goToPage("https://www.youtube.com/watch?v=7v8zxoEoA_Q", 91);
	// p2.goToPage("https://www.youtube.com/watch?v=dhpwBPuWyKg", 6);
	
	// p1.printHistory();
    // std::cout << std::endl;
    // p2.printHistory();

    // p1.clearHistory();
	// p2.clearHistory();

	// p1.printHistory();
    // std::cout << std::endl;
    // p2.printHistory();
	
    return 0;
}
