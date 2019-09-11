#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<typename T>
struct node {
	node<T>* next;
	T data;
	node(T x = 1): data(x) {};
};

template<typename T>
class LinkedList {
public:
	LinkedList();

	void add(T);

	void pop();
	void popBack();

	unsigned int getLength() const;
	node<T>* getHead() const;
	node<T>* getTail() const;

	template<typename U>
	friend ostream& operator<< (ostream&, const LinkedList<U>&);

	~LinkedList();
private:
	node<T>* head;
	node<T>* tail;
	unsigned int length;
};

template<typename T>
ostream& operator<< (ostream& out, const LinkedList<T>& list) {
	for (node<T>* p = list.head; p != nullptr; p = p->next) {
		out << p->data << "  ";
	}
	out << endl;
	return out;
}

template<typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}

template<typename T>
void LinkedList<T>::add(T x) {
	node<T>* p = new node<T>(x);
	p->next = nullptr;
	if (head == nullptr) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
	length++;
}

template<typename T>
void LinkedList<T>::pop() {
	if (head == tail) {
		delete(head);
		head = tail = nullptr;
		length = 0;
		return;
	}
	node<T>* p = head;
	p = head->next;
	delete(head);
	head = p;
	length--;
}


template<typename T>
void LinkedList<T>::popBack() {
	if (head == tail) {
		return pop();
	}
	node<T>* p = head;
	while (p->next != tail) {
		p = p->next;
	}
	p->next = nullptr;
	delete(tail);
	tail = p;
	length--;
}

template<typename T>
unsigned int LinkedList<T>::getLength() const {
	return length;
}

template<typename T>
node<T>* LinkedList<T>::getHead() const {
	return head;
}

template<typename T>
node<T>* LinkedList<T>::getTail() const {
	return tail;
}

template<typename T>
LinkedList<T>::~LinkedList() {
	node<T>* p = head;

	while (head != nullptr) {
		p = head->next;
		delete(head);
		head = p;
	}
	tail = nullptr;
	length = 0;
}

#endif