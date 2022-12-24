#pragma once #include <iostream> #include <sstream> #include "Member.h"

using std::string; using std::cin; using std::cout;

class FamilyTree {
private:

public: FamilyTree();

	  ~FamilyTree();

	  virtual void add(Member*) = 0; virtual void print() = 0; virtual void remove(int) = 0;
};

