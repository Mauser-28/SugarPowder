#ifndef LIST_H
#define LIST_H
#include<iostream>

class List {
private:
	struct Node {
		int32_t data;
		Node* prev;
		Node* next;

		Node() : data(int32_t()), prev(nullptr), next(nullptr) {}
		Node(const int32_t& v) : data(v), prev(nullptr), next(nullptr) {}

	};
	Node* sntl;
	size_t sz;


	void _init() {
		this->sntl = new Node(int32_t());
		this->sntl->next = this->sntl;
		this->sntl->prev = this->sntl;
		this->sz = 0;
	}


	void _dstr() {
		Node* curr = this->sntl->next;
		while (curr != this->sntl) {
			Node* nextNode = curr->next;
			delete curr;
			curr = nextNode;
		}
	}


	Node* _idx_node(const size_t idx) { // size 5 // indx 5 // cur = 4 // i = 4
		Node* cur = nullptr;

		if (idx < sz / 2) {
			cur = this->sntl->next;
			for (std::size_t i = 0; i < idx; ++i) {
				cur = cur->next;
			}
		}
		else {
			cur = this->sntl->prev;
			for (std::size_t i = sz - 1; i > idx; --i) {
				cur = cur->prev;
			}
		}

		return cur;
	}
public:
	List() {
		this->_init();
	}


	List(const List& origList) {
		this->_init();
		Node* current = origList.sntl->next;
		while (current != origList.sntl) {
			pushBack(current->data);
		}
	}


	void pushBack(const int32_t& value) {
		this->insert(this->sz, value);
	}


	void pushFront(const int32_t& value) {
		this->insert(0, value);
	}


	void pop_back() {
		this->erase(this->sz-1);
	}


	void pop_front() {
		this->erase(0);
	}


	void swap(List& other) {
		std::swap(this->sntl, other.sntl);
		std::swap(this->sz, other.sz);
	}


	bool empty() const {
		return this->sz == 0;
	}


	std::size_t size() const {
		return this->sz;
	}


	int32_t& front() { /////
		return this->sntl->next->data;
	}


    const int32_t& front() const {
		return this->sntl->next->data;/// return this->front();
    }


    int32_t& back() { /////
		return this->sntl->prev->data;
    }


    const int32_t& back() const {
		return this->sntl->prev->data;/// return this->back();
    }


	int32_t& operator[](std::size_t idx) {

	}
    
	
	const int32_t& operator[](std::size_t idx) const {
        
    }


    // ===== Modifiers =====

    void insert(std::size_t pos, const int32_t& val) {
		if (pos > this->sz) {
			std::cout << "error";
			return;
		}
		
		Node* freshNode = new Node(val);
		Node* posNode = (pos == this->sz) ? this->sntl : this->_idx_node(pos);

		freshNode->next = posNode;
		freshNode->prev = posNode->prev;

		posNode->prev->next = freshNode;
		posNode->prev = freshNode;
		
		++(this->sz);
	}


    void erase(std::size_t pos) {
		if (pos >= this->sz) {
			std::cout << "error";
			return;
		}

		Node* eraseNode = this->_idx_node(pos);

		eraseNode->next->prev = eraseNode->prev;
		eraseNode->prev->next = eraseNode->next;

		delete eraseNode;

		--(this->sz);
    }

    
    void clear() {
		this->_dstr();
		this->_init();
    }


	~List() {
		Node* unNode = this->sntl->next;
		while (unNode != sntl) {
			Node* nextNode = unNode->next;
			delete unNode;
			unNode = nextNode;
		}
		delete this->sntl;
		this->sz = 0;

	}
};
#endif