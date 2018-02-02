#include <iostream>
#include <string>
#include <vector>

using namespace std;

class student {
	string name;
	size_t noOfSub;
	vector<float> marks;
	float total;
public:
	student() : name(), noOfSub(0), marks(0), total(0) {}
	void setMarks(vector<float> m) {
		for (auto i = 0; i < m.size(); ++i)
			this->marks[i] = m[i];
	}
	float avg() const {
		return this->total / this->noOfSub;
	}
	friend ostream& operator<<(ostream &, const student &);
	friend istream& operator>>(istream &, student &);
};

ostream& operator<<(ostream &out, const student &s) {
	out << s.name << "  " << s.avg();
	return out;
}

istream& operator>>(istream &in, student &s) {
	cout << "Enter name: ";
	getline(in, s.name);
	cout << "Enter number of subjects: ";
	in >> s.noOfSub;
	for (auto i = 0; i < s.noOfSub; ++i) {
		float x;
		cout << "Enter marks in subject " << i + 1 << ": ";
		in >> x;
		s.marks.push_back(x);
		s.total += x;
	}
	return in;
}

int main() {
	student s;
	cin >> s;
	cout << s << endl;
	return 0;
}
