#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

class relation {
  string name;
  int age;
  string phone;
  string rel;
public:
  relation() : name(), age(18), phone(), rel() {}
  relation(string n, int a, string ph, string re) : name(n), age(a), phone(ph), rel(re) {}
  string Rel() const {
    return rel;
  }
  friend ostream& operator<<(ostream&, const relation&);
  friend istream& operator>>(istream&, relation&);
};

ostream& operator<<(ostream &out, const relation &x) {
  out << x.name << "\t";
  out << x.age << "\t";
  out << x.phone << "\t";
  out << x.rel;
  return out;
}

istream& operator>>(istream &in, relation &x) {
  cout << "Enter name: ";
  getline(in, x.name);
  cout << "Enter age: ";
  in >> x.age;
  cout << "Enter phone: ";
  getline(in, x.phone);
  cout << "Enter rel: ";
  getline(in, x.rel);
  return in;
}

string capitalize(string &s) {
  string ret = "";
  int i = 0;
  ret += toupper(s[i++]);
  for (; i < s.length(); ++i)
    ret += s[i];
  return ret;
}

int main() {
  relation abhi[] = {
    relation("Shankar Prasad", 50, "9475742654", "Father"),
    relation("Manorama Prasad", 45, "9547135216", "Mother"),
    relation("Abhishek Prasad", 21, "7602867497", "Myself"),
    relation("Gourav Pratap", 22, "8214871893", "Cousin"),
    relation("Rahul Prasad", 20, "7812381782", "Cousin")
  };
  string reln;
  for (auto &i : abhi) {
    cout << i << endl;
  }
  cout << "Enter relation: ";
  cin >> reln;
  reln = capitalize(reln);
  bool f = 1;
  for (auto &i : abhi) {
    if (i.Rel() == reln) {
      f = 0;
      cout << i << endl;
    }
  }
  if (f)
    cout << "No relation found" << endl;
  return 0;
}
