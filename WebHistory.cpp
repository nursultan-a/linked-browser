#include "WebHistory.hpp"

WebHistory::WebHistory()
{
    // Does nothing.
}

WebHistory::WebHistory(std::string historyText)
{
	// history = url timestamp | url timestamp | url timestamp...
    // urls are string and timestamps are non-negative integers.
    std::string delimiter = " | ";

	std::string tabInfo;
    std::string url;
    std::string timestamp;
    size_t pos = 0;

    while (true)
	{
        pos = historyText.find(delimiter);

        bool breakTheLoop = (pos == std::string::npos);

        tabInfo = historyText.substr(0, pos);
        historyText.erase(0, pos + delimiter.length());

        pos = tabInfo.find(" ");
        
        url = tabInfo.substr(0, pos);
        timestamp = tabInfo.substr(pos + 1, tabInfo.length() - pos);

		Node<Tab> *newPage = new Node<Tab>(Tab(url, std::atoi(timestamp.c_str())), NULL, NULL);
        insertInOrder(newPage);

        if (breakTheLoop)
		{
			break;
		}
    }
}

void WebHistory::printHistory()
{
	std::cout << "Your web history:" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << std::endl;
	if (history.getHead()->next == history.getTail())
	{
		std::cout << "History is empty." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		Node<Tab> *node = history.getFirstNode();
		
		while (node != history.getTail())
		{
		    std::cout << "Page: " << node->element.getUrl() << std::endl;
			std::cout << "Last Visited: " << node->element.getTimestamp() << std::endl;
			std::cout << std::endl;
		    node = node->next;
		}
	}
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

WebHistory::WebHistory(std::string url, int timestamp)
{
	// TODO
	Tab newTab(url, timestamp);
	history.insertAtTheEnd(newTab);
	
}

WebHistory::~WebHistory()
{
	// TODO
	history.~LinkedList<Tab>();
}

void WebHistory::insertInOrder(Node<Tab> *newPage)
{
	// TODO
	Node<Tab> *head = history.getHead();
	Node<Tab> *tail = history.getTail();
	int controller = 0;

	Node<Tab> *current = head->next;

	if(history.isEmpty()){
		head->next = newPage;
		newPage->prev = head;

		tail->prev = newPage;
		newPage->next = tail;
		controller = 99;
	}else{
		while(current != tail){
			if(newPage->element.getTimestamp() > current->element.getTimestamp()){
				newPage->next = current;
				newPage->prev = current->prev;

				current->prev->next = newPage;
				current->prev = newPage;

				controller = 99;

				break;
			}
			current = current->next;
		}

	}

	if(controller != 99){
		newPage->next = tail;
		newPage->prev = tail->prev;

		tail->prev->next = newPage;
		tail->prev = newPage;

	}

	
}

void WebHistory::goToPage(std::string url, int timestamp)
{
	// TODO
	Tab newTab(url, timestamp);
	Node<Tab> *newPage = new Node<Tab>(newTab, NULL, NULL);
	insertInOrder(newPage);
}

void WebHistory::clearHistory()
{
	// TODO
	history.removeAllNodes();
}

void WebHistory::clearHistory(int timestamp)
{
	// TODO
	Node<Tab> *head = history.getHead();
	Node<Tab> *tail = history.getTail();
	Node<Tab> *current = head->next;

	while(current != tail){
		if(current->element.getTimestamp() == timestamp){
			current->next->prev = current->prev;
			current->prev->next = current->next;

			delete current;
			break;
		}
		current = current->next;
	}
}

WebHistory WebHistory::operator+(const WebHistory &rhs) const
{
	// TODO
	Node<Tab> *rhsHead = rhs.history.getHead();
	Node<Tab> *rhsTail = rhs.history.getTail();

	Node<Tab> *lhsHead = history.getHead();
	Node<Tab> *lhsTail = history.getTail();

	WebHistory newWebHistory;

	if(rhsHead->next != rhsTail){
		Node<Tab> *current = rhsHead->next;

		while(current != rhsTail){
			Node<Tab> *newPage = new Node<Tab>(current->element, NULL, NULL);
			newWebHistory.insertInOrder(newPage);
			current = current->next;
		}
	}

	if(lhsHead->next != lhsTail){
		Node<Tab> *current = lhsHead->next;

		while(current != lhsTail){
			Node<Tab> *newPage = new Node<Tab>(current->element, NULL, NULL);
			newWebHistory.insertInOrder(newPage);
			current = current->next;
		}
	}

	return newWebHistory;
}

int WebHistory::timesVisited(std::string pageName)
{
	// BONUS
	int counter = 0;
	Node<Tab> *head = history.getHead();
	Node<Tab> *tail = history.getTail();

	Node<Tab> *current = head->next;

	while(current != tail){
		if(current->element.getWebSite() == pageName){
			counter++;
		}
		current = current->next;
	}

	return counter;
}

std::string WebHistory::mostVisited()
{
	// BONUS
	Node<Tab> *head = history.getHead();
	Node<Tab> *tail = history.getTail();

	Node<Tab> *current = head->next;


	int currentWebsiteVisitNumber = 0;
	int max=0;
	std::string websiteName;


	while(current != tail){
		currentWebsiteVisitNumber = timesVisited(current->element.getWebSite());
		if (max < currentWebsiteVisitNumber){
			max = currentWebsiteVisitNumber;
			websiteName = current->element.getWebSite();
		}
		current = current->next;
	}

	return websiteName;
}