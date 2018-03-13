#include <iostream>
#include <string>

using namespace std;

class person
{
protected:
  string name;
  int code;
public:
  person()
  {
    this->name = "";
    this->code = 1;
  }
  person(const string &n, const int c)
    : name(n), code(c)
  {}

  void updateName(const string &s)
  {
    this->name = s;
  }

  void updateCode(const int c)
  {
    this->code = c;
  }

  void display()
  {
    cout << "Person object" << endl;
    cout << "\tName: " << name << endl;
    cout << "\tCode: " << code << endl;
  }
};

class account : public virtual person
{
protected:
  float pay;
public:
  account(const string &n, const int c, const float p)
    : person(n, c), pay(p)
  {}

  account(const float p) : pay(p)
  {}

  void updatePay(const float p)
  {
    this->pay = p;
  }

  void display()
  {
    cout << "Account object" << endl;
    cout << "\tName: " << name << endl;
    cout << "\tCode: " << code << endl;
    cout << "\tPay : " << pay << endl;
  }
};

class admin : public virtual person
{
protected:
  int experience;
public:
  admin(const string &n, const int c, const int e)
    : person(n, c), experience(e)
  {}

  admin(const int e) : experience(e)
  {}

  void updateExp(const int e)
  {
    this->experience = e;
  }

  void display()
  {
    cout << "Admin object" << endl;
    cout << "\tName: " << name << endl;
    cout << "\tCode: " << code << endl;
    cout << "\tExp : " << experience << endl;
  }
};

class master : public account, public admin
{
public:
  master(const string &n, const int c,
         const float p, const int e)
    : person(n, c), account(p), admin(e)
  {}

  void display()
  {
    cout << "Master object" << endl;
    cout << "\tName: " << name << endl;
    cout << "\tCode: " << code << endl;
    cout << "\tPay : " << pay << endl;
    cout << "\tExp : " << experience << endl;
  }
};

int main ()
{
  master m("Ankush", 5, 40000, 4);
  int n;
  string s;
  int x;
  float f;
  while (true) {
    m.display();
    cout << "Update:\n";
    cout << "1. Name\n";
    cout << "2. Code\n";
    cout << "3. Pay\n";
    cout << "4. Experience\n";
    cout << "5. Quit\nChoice: ";
    cin >> n;
    switch (n) {
    case 1:
      cout << "Enter name: ";
      cin >> s;
      m.updateName(s);
      break;
    case 2:
      cout << "Enter code: ";
      cin >> x;
      m.updateCode(x);
      break;
    case 3:
      cout << "Enter pay: ";
      cin >> f;
      m.updatePay(f);
      break;
    case 4:
      cout << "Enter experience: ";
      cin >> x;
      m.updateExp(x);
      break;
    case 5:
      return 0;
    default:
      cout << "Wrong choice\n";
    }
  }
  return 0;
}
