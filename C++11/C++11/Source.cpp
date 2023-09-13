#include <iostream>
#include <vector>

class Student {
protected:
	std::string Name;
	std::string LastName;
	int id;
	
public:
	Student(std::string name, std::string lastname) : Name(name), LastName(lastname), id(0) {}
	void SetId(int _id) {
		id = _id;
	}
	friend std::ostream& operator<<(std::ostream& os, const Student& st) {
		return os << "Name: " << st.Name << " " << st.LastName << "     Id: " << st.id << std::endl;
	}
};


class Archive {
protected:
	std::vector<Student> archive;
public:
	void addStudent(std::string name, std::string lastname) {
		Student student(name, lastname);
		auto free_id_finder = [size = archive.size()]() {return size + 11111111; };
		student.SetId(free_id_finder());
		archive.push_back(student);
	}
	void printarchive() {
		for (auto iter{ archive.begin() }; iter != archive.end(); iter++) {
			std::cout << *iter;
		}
	}
	void rangebasedprint() {
		for ( const auto& pr : archive) {
			std::cout << pr;
		}
	}
};


void main() {
	Archive FITHREE;
	FITHREE.addStudent("Vasya", "Pupkin");
	FITHREE.addStudent("Gena", "Codin");
	FITHREE.addStudent("Abobiy", "Tribobiy");

	FITHREE.printarchive();
	std::cout << std::endl;
	FITHREE.rangebasedprint();
}