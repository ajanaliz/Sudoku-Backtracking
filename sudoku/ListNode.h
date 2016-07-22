#pragma once
class ListNode
{
public:
	ListNode();
	ListNode(int, ListNode*);
	void setValue(int);
	void setNext(ListNode*);
	int getValue();
	void deleteFirstElement();
	void deleteLastElement();
	int getLength();
	int indexOfElement(int);
	int lastIndexOfElement(int);
	int elementAt(int);
	void addAppend(int);//adds new node with corresponding value to end of LinkedList
	void addInfront(int);//add new node with corresponding value at the begining of the LinkedList
	void addAt(int, int);//adds new node with specified value to the specified index...other elements are then shifted(index, value)
	void remove(int);//removes first instance of node at specified index
	void replace(int, int);//replaces value at specified index with new value, respectively(index, value);
	void deleteElement(int, int);
	void printList();
	ListNode* getNext();
	~ListNode();
private:
	ListNode* next = 0;
	int value;

};//end class