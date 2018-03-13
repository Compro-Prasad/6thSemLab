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
    cout << "Inititalizing person: ";
    cout << sizeof(name) << " " << sizeof(code);
    cout << " -> " << sizeof(*this) << endl;
  }
};

class account : public virtual person
{
protected:
  float pay;
public:
  account()
  {
    cout << "Inititalizing account: ";
    cout << sizeof(name) << " " << sizeof(code);
    cout << " " << sizeof(pay);
    cout << " -> " << sizeof(*this) << endl;
  }
};

class admin : public virtual person
{
protected:
  int experience;
public:
  admin()
  {
    cout << "Inititalizing admin: ";
    cout << sizeof(name) << " " << sizeof(code);
    cout << " " << sizeof(experience);
    cout << " -> " << sizeof(*this) << endl;
  }
};

class master : public account, public admin
{
public:
  master()
  {
    cout << "Inititalizing master: ";
    cout << sizeof(name) << " " << sizeof(code);
    cout << " " << sizeof(pay);
    cout << " " << sizeof(experience);
    cout << " -> " << sizeof(*this) << endl;
  }
};

int main ()
{
  person p;
  account a;
  admin ad;
  master m;
  return 0;
}
