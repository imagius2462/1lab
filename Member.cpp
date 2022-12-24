#include "Member.h" Member::Member() {
mother = NULL; father = NULL; spouse = NULL;
}

Member::Member(string name) {
	this->first_name = name;
}

Member::Member(string first_name, string last_name, string patronymic, int age, string born, string died = "") {
	this->first_name = first_name; this->last_name = last_name; this->patronymic = patronymic; this->age = age;
	this->born = born; this->died = died;

	mother = NULL; father = NULL; spouse = NULL;
	head_childrens = NULL;

	cout << "Constructor Member with params\n";
}

Member::~Member() {
	cout << "Destructor Member\n";
};

string Member::get_first_name() { return this->first_name; }
void Member::set_first_name(string first_name) { this->first_name = first_name; }


string Member::get_last_name() { return this->last_name; }
void Member::set_last_name(string last_name) { this->last_name = last_name; }

string Member::get_patronymic() { return this->patronymic; }
void Member::set_patronymic(string patronymic) { this->patronymic = patronymic; }

Member* Member::get_mother() { return this->mother; }
void Member::set_mother(Member* mother) { this->mother = mother; }

Member* Member::get_father() { return this->father; }
void Member::set_father(Member* father) { this->father = father; }

Member* Member::get_spouse() { return this->spouse; }
void Member::set_spouse(Member* spouse) { this->spouse = spouse; }

string Member::get_childrens() {
	if (!count_children) return "none";

	std::stringstream ss;
	ChildrenNode* temp = new ChildrenNode; temp = head_childrens;

	while (temp != NULL) {
		ss << temp->member->get_first_name() << " "; temp = temp->next;
	}
	return ss.str();
}

void Member::add_children(Member* children) {
	ChildrenNode* temp = new ChildrenNode; temp->member = children;
	temp->next = NULL;

	if (head_childrens == NULL) {
		head_childrens = temp; tail_childrens = temp;

		temp = NULL;
	}
	else {
		tail_childrens->next = temp; tail_childrens = temp;
	}
	count_children++;
}

string Member::decribe() {
	std::stringstream ss;
	ss << first_name << " " << last_name << " " << patronymic << " " << born << " " << (died != "" ? died : "none") << " " << age << " " << (mother ? mother->get_first_name() : "none") << " " <<
		(father ? father->get_first_name() : "none") << " " << (spouse ? spouse->get_first_name() : "none") << " " << get_childrens();
	return ss.str();
}

std::istream& operator>> (std::istream& in, Member& member) {
	cout << "first_name: "; in >> member.first_name;
	cout << "last_name: "; in >> member.last_name; cout << "patronymic: "; in >> member.patronymic; cout << "age: "; in >> member.age;
	cout << "born: "; in >> member.born; cout << "died: "; in >> member.died; return in;
}
