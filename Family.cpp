#include "Family.h"

Family::Family() {
	count_members = 0;
	cout << "Constructor Family\n";
}
Family::~Family() {
	free();
	cout << "Destructor Family\n";
};

void Family::add(Member* new_member) {
	MemberNode* temp = new MemberNode; temp->member = new_member;
	temp->next = NULL;

	if (head == NULL) {
		head = temp; tail = temp; temp = NULL;
	}
	else {
		tail->next = temp; tail = temp;
	}
	count_members++;
}

void Family::print() {
	if (!count_members) throw std::runtime_error("the list of members is empty");
	MemberNode* temp = new MemberNode; temp = head;
	int counter = 1; while (temp != NULL) {
		std::cout << counter++ << ". " << temp->member->decribe() << "\n"; temp = temp->next;
	}
}

void Family::free() {
	MemberNode* curr = head; MemberNode* next = NULL;

	while (curr != NULL) {
		next = curr->next; delete curr->member; delete curr;
		curr = next;
	}
	head = NULL; tail = NULL;
	count_members = 0;
}

void Family::remove(int num) {
	if (!count_members) throw std::runtime_error("the list of members is empty");
	if (num > count_members || num < 1) {
		throw std::runtime_error("The number should be in the range from 1 to " + std::to_string(count_members));
	}

	MemberNode* cur = new MemberNode; MemberNode* prev = new MemberNode; cur = head;
	if (num == 1) head = head->next;

	for (int i = 1; i < num; i++) {
		prev = cur;
		cur = cur->next;
	}
	if (num == count_members) {
		tail = prev;
		prev->next = NULL; tail->next = NULL;
	}
	else {
		prev->next = cur->next;
	}
	count_members--;

	delete cur->member;
}

Member* Family::get(int num) {
	if (!count_members) throw std::runtime_error("the list of members is empty");
	if (num > count_members || num < 1) {
		throw std::runtime_error("The number should be in the range from 1 to " + std::to_string(count_members));
	}
	MemberNode* cur = new MemberNode; MemberNode* prev = new MemberNode; cur = head;

	if (num == 1) return head->member; for (int i = 1; i < num; i++) {
		prev = cur;
		cur = cur->next;
	}
	return cur->member;
}

int Family::get_count_members() {
	return this->count_members;
}
