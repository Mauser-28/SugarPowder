#include <iostream>

class List {
private:
	struct ListItem {
		int info;
		ListItem* next;
	};
	ListItem* first;
public:
	List();
	List(const List&);
	~List();
	void InsertFirst(const int&);
	/*void InsertByAlph();*/
	bool DeleteFirst();
	const int Top() const;
	void ListPrint() const;
	void ForEach(void(int)) const;
	void ForEach(void(int&));
	const List& operator=(const List&);
	void Erase();
	void Clone(const List&);
};









List::List() {
	first = NULL;
}

List::List(const List& l) {
	Clone(l);
}

List::~List() {
	Erase();
}

const List& List::operator=(const List& l) {
	if (&l == this) {
		return *this;
	}
	Erase();
	Clone(l);
	return *this;
}

void List::InsertFirst(const int& aInfo) {
	ListItem* p = new ListItem;
	p->info = aInfo;
	p->next = first;
	first = p;
}

bool List::DeleteFirst() {
	if (first == NULL) {
		return false;
	}
	ListItem* p = first;
	first = first->next;
	delete p;
	return true;
}

const int List::Top() const {
	if (first == NULL) {
		throw std::runtime_error("Список пуст.");
	}
	int x = first->info;
	return x;
}

void List::Clone(const List& List) {
	ListItem* realCur = List.first;
	ListItem* cloneCur = nullptr;
	ListItem* prevClone = nullptr;

	this->first = nullptr;

	while (realCur != nullptr) {
		cloneCur = new ListItem;
		cloneCur->info = realCur->info;
		cloneCur->next = nullptr;

		if (prevClone == nullptr) {
			this->first = cloneCur; // первый элемент
		}
		else {
			prevClone->next = cloneCur; // связываем
		}

		prevClone = cloneCur;
		realCur = realCur->next;
	}
}

void List::Erase() {
	ListItem* p, * q;
	p = first;
	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
	first = NULL;
}

void List::ListPrint() const {
	ListItem* p = first;
	if (p == NULL) {
		std::cout << "Список пуст.\n";
	}
	if (p != NULL) {
		while (p != NULL) {
			std::cout << p->info << " ";
			p = p->next;
		}
	}
	std::cout << std::endl;
}