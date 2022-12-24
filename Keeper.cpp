#include "Keeper.h" Keeper::Keeper() {
count_families = 0;
cout << "Constructor Keeper" << "\n";
}

Keeper::~Keeper() {
	cout << "Destructor Keeper" << "\n"; if (!count_families) return;

	for (size_t i = 1; i <= count_families; i++) {
		delete get(i);
	}
}

void Keeper::add(Family* new_family) {
	FamilyNode* temp = new FamilyNode; temp->family = new_family;
	temp->next = NULL;

	if (head == NULL) {
		head = temp; tail = temp; temp = NULL;
	}
	else {
		tail->next = temp; tail = temp;
	}
	count_families++;
}


void Keeper::print() {
	if (!count_families) throw std::runtime_error("the list of families is empty");

	for (size_t i = 1; i <= count_families; i++) {
		cout << i << "\n";
		for (size_t j = 1; j <= get(i)->get_count_members(); j++) {
			cout << "\t" << j << ". " << get(i)->get(j)->decribe() << "\n";
		}
	}
}

void Keeper::remove(int num) {
	if (!count_families) throw std::runtime_error("the list of families is empty");
	if (num > count_families || num < 1) {
		throw std::runtime_error("The number should be in the range from 1 to " + std::to_string(count_families));
	}

	FamilyNode* cur = new FamilyNode; FamilyNode* prev = new FamilyNode; cur = head;
	if (num == 1) head = head->next;

	for (int i = 1; i < num; i++) {
		prev = cur;
		cur = cur->next;
	}
	if (num == count_families) {
		tail = prev;
		prev->next = NULL; tail->next = NULL;
	}
	else {
		prev->next = cur->next;
	}
	count_families--; delete cur->family;
}


void Keeper::upload() {
	std::fstream in;
	string path = "families.txt";

	cout << "Enter path to the file: "; cin >> path; in.open(path, std::ios::out);
	while (!in.is_open()) {
		cout << "failed to open the file" << "\n";
		cout << "Enter path to the file: "; cin >> path; in.open(path, std::ios::in);
	}

	if (in.is_open()) {
		for (size_t i = 1; i <= count_families; i++) {
			for (size_t j = 1; j <= get(i)->get_count_members(); j++) {
				in << get(i)->get(j)->decribe() << "\n";
			}
			in << "\n";
		}
	}
	else {
		std::cout << "failed to open the file";
	}
	in.close();
}

string* Keeper::split(string str, string delimiter, int count) {
	int pos, i = 0;
	string* strings = new string[count];

	while ((pos = str.find(delimiter)) != string::npos) {
		strings[i++] = str.substr(0, pos);
		str.erase(0, pos + delimiter.length());
	}
	strings[i] = str; return strings;
}

int Keeper::get_count_arguments(string str) {
	int str_len = str.length();

	int count = 0;
	if (str_len == 0) return 0;
	for (size_t i = 0; i < str_len - 1; i++) {
		if (str[i] == ' ') count++;
	}
	return count + 1;
}

bool Keeper::is_int(string str) {
	std::stringstream ss(str); float i;
	if ((ss >> i).fail()) return false; else if (int(i) == i) return true; return false;
}

void Keeper::load() {
	string line, type; int number_fam = 0; int args_count; string* s;
	bool is_new_fam = true; bool check = true;

	std::fstream in;
	string path = "families.txt";

	cout << "Enter path to the file: "; cin >> path; in.open(path, std::ios::in);
	while (!in.is_open()) {
		cout << "failed to open the file" << "\n";
		cout << "Enter path to the file: "; cin >> path; in.open(path, std::ios::in);
	}

	while (std::getline(in, line)) {
		args_count = get_count_arguments(line);

		if (args_count == 0 && !is_new_fam) {

			Family* new_fam = new Family(); this->add(new_fam);
			is_new_fam = true;
		}
		if (args_count < 10) continue;

		s = split(line, " ", args_count); if (!is_int(s[5])) continue; else {
			if (check) {
				this->add(new Family()); check = false;
			}
			Member* member = new Member(s[0], s[1], s[2], std::stoi(s[5]), s[3], s[4]);
			member->set_mother(new Member(s[6])); member->set_father(new Member(s[7])); member->set_spouse(new Member(s[8]));
			for (size_t i = 9; i < args_count; i++) {
				member->add_children(new Member(s[i]));
			}

			this->get(count_families)->add(member); is_new_fam = false;
		}
	}
	in.close();
}

Family* Keeper::get(int num) {
	if (!count_families) throw std::runtime_error("the list of families is empty");
	if (num > count_families || num < 1) {
		throw std::runtime_error("The number should be in the range from 1 to " + std::to_string(count_families));
	}
	FamilyNode* cur = new FamilyNode; FamilyNode* prev = new FamilyNode; cur = head;
	if (num == 1) return head->family;


	for (int i = 1; i < num; i++) {
		prev = cur;
		cur = cur->next;
	}
	return cur->family;
}
