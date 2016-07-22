#include "ListNode.h"
#include <iostream>
#include <climits>

using namespace std;

ListNode::ListNode()
{
}

ListNode::ListNode(int value, ListNode* node){
	this->value = value;
	this->next = node;
}

void ListNode::setNext(ListNode* node){
	this->next = node;
}

void ListNode::setValue(int value){
	this->value = value;
}

ListNode* ListNode::getNext(){
	return this->next;
}

int ListNode::getValue(){
	return this->value;
}

int ListNode::getLength(){
	if (this != NULL){//if this is not NULL
		if ((*this).getNext() == 0)
			return 1;
		else{
			ListNode* temp = this;
			int count = 0;
			while (temp != 0){
				count++;
				temp = (*temp).getNext();
			}//end while
			temp = NULL;
			return count;
		}//end else
	}//end if
	return 0;
}

void ListNode::replace(int position, int value){
	ListNode* temp = this;
	if (position > -1 && position < getLength()){
		for (int i = 0; i < position; i++){
			temp = (*temp).getNext();
		}//end for
		(*temp).setValue(value);
	}//end if
	else
		cout << "Desired index is out of bounds by " << getLength() - position + 1 << " units" << endl;
	temp = NULL;
}

void ListNode::remove(int position){
	ListNode* temp = this;
	if (position > -1 && position < getLength()){
		for (int i = 0; i < position - 1; i++){
			temp = (*temp).getNext();
		}//end for
		(*temp).setNext((*(*temp).getNext()).getNext());
	}//end if
	else
		cout << "Desired index is out of bounds by " << getLength() - position + 1 << " units" << endl;
	temp = NULL;
}

void ListNode::addAt(int position, int value){
	ListNode* temp = this;
	ListNode* temp2;
	if (position > -1 && position < getLength() + 1){
		if (position == 0){
			addInfront(value);
		}//end if
		else
		if (position == getLength()){
			addAppend(value);
		}//end else if
		else{
			for (int i = 0; i < position - 1; i++){
				temp = (*temp).getNext();
			}//end for
			temp2 = (*temp).getNext();
			(*temp).setNext(new ListNode(value, temp2));
		}//end else
	}//end if
	else
		cout << "Desired index is out of bounds by " << getLength() - position << " units" << endl;
	temp = NULL;
	temp2 = NULL;
}

void ListNode::addAppend(int value){
	ListNode* temp = this;
	while ((*temp).getNext() != 0){
		temp = (*temp).getNext();
	}
	(*temp).setNext(new ListNode(value, NULL));
	temp = NULL;
}

void ListNode::addInfront(int value){
	ListNode* temp = (*this).getNext();
	int num = (*this).getValue();
	(*this).setValue(value);
	(*this).setNext(new ListNode(num, temp));
	temp = NULL;
}

int ListNode::elementAt(int position){
	if (this == 0 || (*this).getLength() <= position)
		return INT_MIN;
	ListNode* temp = this;
	for (int i = 0; i < position; i++){
		temp = (*temp).getNext();
	}
	int num = (*temp).getValue();
	temp = NULL;
	return num;
}

int ListNode::indexOfElement(int value){
	ListNode* temp = this;
	for (int i = 0; i < (*this).getLength(); i++){
		if ((*temp).getValue() == value)
			return i;
		temp = (*temp).getNext();
	}
	temp = NULL;
	return -1;
}

int ListNode::lastIndexOfElement(int value){
	ListNode* temp = this;
	int count = -1;
	for (int i = 0; i < (*this).getLength(); i++){
		if ((*temp).getValue() == value)
			count = i;
		temp = (*temp).getNext();
	}
	temp = NULL;
	return count;
}

void ListNode::deleteFirstElement(){
	ListNode* temp = this;
	if ((*(*this).getNext()).getNext() == 0){//if there are only two nodes
		temp = (*temp).getNext();
		(*this) = *temp;
		(*this).setNext(0);
		delete temp;
	}
	else{//if there are more than two nodes
		temp = (*temp).getNext();
		(*this) = *temp;
		temp = (*temp).getNext();
		(*this).setNext(temp);
		temp = NULL;
	}
}

void ListNode::deleteLastElement(){
	ListNode* temp = this;
	while ((*(*temp).getNext()).getNext() != 0){
		temp = (*temp).getNext();
	}
	(*temp).setNext(0);
	temp = NULL;
}


void ListNode::printList(){
	ListNode* temp = this;
	while (temp != NULL){
		cout << (*temp).getValue() << " ";
		temp = (*temp).getNext();
	}//end while
	cout << endl;
}

ListNode::~ListNode()
{
}