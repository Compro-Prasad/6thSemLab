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
  person p("Abhishek", 2);
  account a("Prasad", 3, 32000);
  admin ad("Sonu", 4, 3);
  master m("Ankush", 5, 40000, 4);
  p.display();
  a.display();
  ad.display();
  m.display();
  return 0;
}
