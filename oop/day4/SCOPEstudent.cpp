#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <limits.h>

using namespace std;

class student {
    string name;
    size_t noOfSub;
    vector<float> marks;
    float total;
    unsigned int id;
    static unsigned int idInc;
public:
    student();
    unsigned int getId() const;
    float avg() const;
    void setMarks(vector<float>);
    friend ostream& operator<<(ostream &, const student &);
    friend istream& operator>>(istream &, student &);
};
unsigned int student::idInc = 1;

unsigned int student::getId() const {
    return id;
}

student::student() : name(), noOfSub(0),
                     marks(0), total(0), id(idInc) {
    ++idInc;
}

void student::setMarks(vector<float> m) {
    for (auto i = 0; i < m.size(); ++i)
        this->marks[i] = m[i];
}
float student::avg() const {
    return this->total / this->noOfSub;
}

ostream& operator<<(ostream &out, const student &s) {
    out << s.id << "   " << s.name << "   " << s.avg();
    return out;
}

template <typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
    for (auto &i : v)
        cout << i << endl;
                     return out;
}

istream& operator>>(istream &in, student &s) {
    cout << "Enter name: ";
    //std::cin.ignore(INT_MAX);
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

vector<string> split(string str, string sep) {
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current != NULL){
        arr.push_back(current);
        current=strtok(NULL, sep.c_str());
    }
    return arr;
}

int main() {
    cout << "Enter help to see the help" << endl;
    vector<student> all;
    vector<string> inputArgs;
    do {
        cout << ">> ";
        cout.flush();
        string input;
        getline(cin, input);
        inputArgs = move(split(input, " "));
        if (inputArgs[0] == "help") {
            cout << "add - add student details" << endl
                 << "remove <id> - remove student details" << endl
                 << "list - show all student details" << endl
                 << "quit - quit the program" << endl;
        } else if (inputArgs[0] == "add") {
            student s;
            cin >> s;
            cout << s << endl;
            all.push_back(s);
        } else if (inputArgs[0] == "remove") {
            stringstream stream(inputArgs[1]);
            unsigned int inputId;
            stream >> inputId;
            auto ret = find_if(all.begin(), all.end(),
                               [&inputId](const student &s) {
                                   return s.getId() == inputId;
                               });
            if (ret == all.end())
                cout << "Not found" << endl;
            else {
                all.erase(ret);
                cout << "Successfully removed" << endl;
            }
        } else if (inputArgs[0] == "list") {
            cout << all;
        }
        char *s = stdin->_IO_read_ptr;
        stdin->_IO_read_ptr = s + strlen(s);
    } while (inputArgs.size() > 0 && inputArgs[0] != "quit");
    return 0;
}
