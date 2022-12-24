#pragma once #include <iostream> #include <sstream>

using std::string; using std::cout;

class Member {
private:
	struct ChildrenNode {

		Member* member; ChildrenNode* next;
	};

	string first_name; string last_name; string patronymic; string born; string died;
	int age; Member* mother; Member* father; Member* spouse;

	ChildrenNode* head_childrens; ChildrenNode* tail_childrens; int count_children;
public: Member();
	  Member(string name);
	  Member(string first_name, string last_name, string patronymic, int age, string born, string died);
	  ~Member();

	  string get_first_name();
	  void set_first_name(string first_name);

	  string get_last_name();
	  void set_last_name(string last_name);

	  string get_patronymic();
	  void set_patronymic(string patronymic);

	  Member* get_mother();
	  void set_mother(Member* mother);

	  Member* get_father();
	  void set_father(Member* father); Member* get_spouse();

	  void set_spouse(Member* spouse); string get_childrens();
	  void add_children(Member* children); string decribe();
	  friend std::istream& operator>> (std::istream& in, Member& member);
};
