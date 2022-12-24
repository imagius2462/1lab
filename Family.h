#pragma once
#include "FamilyTree.h" #include "Member.h"

class Family : public FamilyTree {
private:
	struct MemberNode {
		Member* member; MemberNode* next;
	};

	MemberNode* head; MemberNode* tail;

int count_members; public:
	Family();
	~Family();
	void add(Member* new_member); void print();
	void free();
	void remove(int num); Member* get(int num); int get_count_members();
};

