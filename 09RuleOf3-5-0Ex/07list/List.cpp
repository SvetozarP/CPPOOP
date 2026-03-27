#include <sstream>

#include "List.h"


List::Node::Node(int value, Node* prev, Node* next) : value(value), prev(prev), next(next) {}

int List::Node::getValue() const { return value; };
void List::Node::setValue(int value) {
	this->value = value;
}

List::Node* List::Node::getNext() const { return next; }
void List::Node::setNext(Node* next) {
	this->next = next;
}

List::Node* List::Node::getPrev() const {
	return prev;
}
void List::Node::setPrev(Node* prev) {
	this->prev = prev;
}

size_t List::getSize() const { return size; }
bool List::isEmpty() const { return getSize() == 0; }

List::List() : size(0), head(nullptr), tail(nullptr) {};

int List::first() const { return head->getValue(); }

std::string List::toString() const {

	std::ostringstream ostr;

	Node* cur = head;
	while (cur != nullptr) {
		ostr << cur->getValue() << ' ';
		cur = cur->getNext();
	}

	return ostr.str();

}

void List::removeAll() {
	Node* curr = head;
	while (curr != nullptr) {
		Node* next = curr->getNext();
		delete curr;
		curr = next;
	}
	size = 0;
	head = tail = nullptr;
}

List::~List() {
	removeAll();
}

List& List::operator<<(const int& value) {

	add(value);

	return *this;
}

void List::removeFirst() {
	if (head != nullptr) {
		// The list has to have 1 element at least
		Node* second = head->getNext();
		delete head;
		size--;
		head = second;
		if (size == 0) {
			// the list has one element
			tail = nullptr;
		}
	}

}

void List::add(int value) {
	//add always at the end of the list
	if (tail == nullptr) {
		head = tail = new Node(value, nullptr, nullptr);
		size = 1;
	}
	else {
		Node* newNode = new Node(value, tail, nullptr);
		tail->setNext(newNode);
		tail = newNode;
		size++;
	}
}

void List::addAll(const List& other) {
	Node* curNode = other.head;
	while (curNode != nullptr) {
		add(curNode->getValue());
		curNode = curNode->getNext();

	}
}


List::List(const List& other) : List() {
	addAll(other);
}

List& List::operator=(const List& other) {
	if (this == &other) {
		return *this;
	}
	else {
		removeAll();
		addAll(other);
	}

	return *this;
}

// static

List List::getReversed(List l) {
	List res;

	Node* curNode = l.tail;
	while (curNode != nullptr) {
		res.add(curNode->getValue());
		curNode = curNode->getPrev();
	}

	return res;
}