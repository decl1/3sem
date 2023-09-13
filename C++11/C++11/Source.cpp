#include <iostream>
#include <vector>

class Student {
protected:
	std::string Name;
	std::string LastName;
	int id;
	float mid_mark;
	bool grant;
	bool scholarship;
public:
	Student() : Name("defaultName"), LastName("defaultName"), id(0), grant(false), scholarship(false), mid_mark(0.0) {}
	Student(std::string name, std::string lastname, bool _grant, bool _scholarship, float midm) : 
		Name(name), LastName(lastname), id(0), grant(_grant), scholarship(_scholarship), mid_mark(midm) {}
	Student(const class Student& st) : Name(st.Name), LastName(st.LastName), id(st.id), grant(st.grant), scholarship(st.scholarship), mid_mark(st.mid_mark) {}
	
	int comparemidmark(const class Student& st) {
		if (this->mid_mark < st.mid_mark)
			return -1;
		if (this->mid_mark = st.mid_mark)
			return 0;
		if (this->mid_mark < st.mid_mark)
			return 1;
	}
	bool operator==(const class Student& st) {
		if (LastName == st.LastName)
			return 1;
		return 0;
	}
	bool operator>(const class Student& st) {
		for (int i = 0; i < (LastName.size() <= st.LastName.size()) ? LastName.size() : st.LastName.size(); i++) {
			if (LastName[i] < st.LastName[i])
				return 1;
		}
		return 0;
	}
	bool operator<(const class Student& st) {
		for (int i = 0; i < (LastName.size() <= st.LastName.size()) ? LastName.size() : st.LastName.size(); i++) {
			if (LastName[i] > st.LastName[i])
				return 1;
		}
		return 0;
	}
	Student operator=(int _id) {
		this->id = _id;
	}

	void SetId(int _id) {
		id = _id;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const Student& st) {
		return os << " |" << st.id << " | " << ((st.grant == 1) ? "Y" : "N") << "  | " << ((st.scholarship == 1) ? "Y" : "N") << "  | " << st.mid_mark << " | "
			<< st.Name << " " << st.LastName << std::endl;
	}

	std::string getLastName() {
		return LastName;
	}
	int getId() {
		return id;
	}
	float getMM() {
		return mid_mark;
	}
};


class Archive {
protected:
	std::vector<Student> archive;
public:
	void addStudent(std::string name, std::string lastname, bool _grant, bool _scholarship, float mm) {
		Student student(name, lastname, _grant, _scholarship,mm);
		auto free_id_finder = [size = archive.size()]() {return size + 11111111; };
		student.SetId(free_id_finder());
		archive.push_back(student);
	}

	void rangebasedprint() {
		std::cout << "N | ID      | GR | SH | MM  | FN" << std::endl;
		int i = 1;
		for ( const auto& pr : archive) {
			std::cout << i++ << pr;
		}
	}

	void printsorted() {
		std::cout << "N | ID      | GR | SH | MM  | FN" << std::endl;
		int i = 1;
		float lastmax = 6.0;
		auto maxiter = archive.begin();
		for (int i = 0; i < archive.size();i++) {
			float localmax = 0.0;
			auto iter = archive.begin();
			while(iter!=archive.end()) {
				if(((*iter).getMM() > localmax) && ((*iter).getMM() < lastmax)) {
					localmax = (*iter).getMM();
					maxiter = iter;
				}
				++iter;
			}
			std::cout << i+1 << (*maxiter);
			lastmax = (*maxiter).getMM();
		}
	}

	void foundlastname(std::string search) {
		for (auto& pr : archive) {
			if (pr.getLastName() == search)
				std::cout << std::endl << pr.getId() << " " << pr.getLastName();
		}
		std::cout << std::endl;
	}

	bool del_id(int _id) {
		for (auto iter = archive.begin(); iter < archive.end(); iter++) {
			if ((*iter).getId() == _id) {
				archive.erase(iter);
				return 1;
			}
		}
		return 0;
	}
};


void main() {
	Archive FITHREE;
	FITHREE.addStudent("Vasya", "Pupkin", true, true, 4.9);
	FITHREE.addStudent("Gena", "Codin", false, false, 3.2);
	FITHREE.addStudent("Abobiy", "Tribobiy", true, false,3.9);

	FITHREE.rangebasedprint();
	std::cout << std::endl;
	FITHREE.printsorted();
}