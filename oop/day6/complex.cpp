#include <iostream>

using namespace std;

template <typename T>
class Complex {
  T real;
  T imag;
public:
  Complex() : real(0), imag(0) {}
  Complex(T r, T i) :
    real(r), imag(i) {}
  T r() const { return this->real; }
  T i() const { return this->imag; }
  Complex operator+(const Complex<T> &y) const;
  void input();
};

template <typename T>
Complex<T> Complex<T>::operator+(const Complex<T> &y) const {
  Complex<T> z(this->r() + y.r(), this->i() + y.i());
  return z;
}

template <typename T>
void Complex<T>::input() {
  cout << "Enter Real and Imaginary: ";
  cin >> this->real;
  cin >> this->imag;
}

template <typename T>
ostream& operator<<(ostream &out, const Complex<T> &x) {
  out << x.r();
  if (x.i() < 0)
    out << " - i" << -x.i();
  else
    out << " + i" << x.i();
  return out;
}

int main() {
  Complex<double> a, b;
  a.input();
  b.input();
  cout << "(" << a << ") + (" << b << ") = " << (a + b) << endl;
  return 0;
}
