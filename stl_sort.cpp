#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};

int main(void) {
	Student students[] = {
		Student("김상현", 90),
		Student("장수현", 93),
		Student("박성국", 97),
		Student("김한울", 87),
		Student("이태일", 92) 
	};
	sort(students, students + 5);
	for(int i=0; i<5; ++i)
		cout << students[i].name << ' ';
		
	return 0;
}
