#pragma once
template<typename T>
class List
{
public:
	List();
	~List();

	int GetSize() { return size; };
	void push_back(T data);
	void pop_front();
	void pop_back();
	void removeAt(int index);


	T& operator [] (const int index);

private:
	int size;
	template<typename T>
	class Node {
	public:
		Node *pNext;
		Node *pPrev;
		T data;

		Node(T data, Node *pNext = nullptr, Node *pPrev = nullptr) {
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};

	Node<T> *head;
	Node<T> *tail;
};

template<typename T>
inline List<T>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline List<T>::~List()
{
}


template<typename T>
inline void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
		tail = head;
	}
	else {
		Node<T> *buf = this->tail;
		tail = new Node<T>(data);
		buf->pNext = tail;
		tail->pPrev = buf;

	}
	size++;
}

template<typename T>
inline void List<T>::pop_front()
{
	if (size == 1) {
		Node<T> *toDelete = head;
		head = nullptr;
		delete[] toDelete;
		size--;
	}
	else {

		Node<T> *toDelete = head;
		head = head->pNext;
		head->pPrev = nullptr;
		delete[] toDelete;
		size--;
	}
}

template<typename T>
inline void List<T>::pop_back()
{
	Node<T> *toDelete = tail;
	tail = tail->pPrev;
	tail->pNext = nullptr;
	delete[] toDelete;
	size--;
}

template<typename T>
inline void List<T>::removeAt(int index)
{
	if (index == 0) {
		pop_front();
	}
	else if (index == size - 1) {
		pop_back();
	}
	else {
		Node<T> *toDelete = this->head;
		for (int i = 0; i < index; i++) {
			toDelete = toDelete->pNext;
		}
		toDelete->pPrev->pNext = toDelete->pNext;
		toDelete->pNext->pPrev = toDelete->pPrev;
		delete[] toDelete;
		size--;
	}

}


template<typename T>
inline T & List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> * current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


#pragma once
template<typename T>
class List
{
public:
	List();
	~List();

	void clear();
	void pop_front();
	void push_back(T data);
	int GetSize() { return Size; }
	void push_front(T data);
	void insert(T value, int index);
	void removeAt(int index);
	void pop_back();

	T& operator [] (const int index);

private:



	template<typename T>
	class Node {
	public:
		Node *pNext;
		T data;

		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T> *head;

};

template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::clear()
{
	while (Size) {
		pop_front();
	}
}



template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete[] temp;
	Size--;
}


template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T> *current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T value, int index)
{

	if (index == 0) {
		push_front(value);
	}
	else {

		Node<T> *previous = this->head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node<T> *newNode = new Node<T>(value, previous->pNext);
		previous->pNext = newNode;

		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node<T> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}