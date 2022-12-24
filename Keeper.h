#pragma once #include <fstream> #include <string> #include <limits>
#include "FamilyTree.h" #include "Family.h" #include "Member.h"

class Keeper {
private:
	struct FamilyNode {
		Family* family; FamilyNode* next;
	};

	FamilyNode* head; FamilyNode* tail; int count_families;
public: Keeper();
	  ~Keeper();
	  void add(Family* new_family); void print();
	  void remove(int num); void upload();
	  string* split(string str, string delimiter, int count); int get_count_arguments(string str);
	  bool is_int(string str); void load();
	  Family* get(int num);

};
