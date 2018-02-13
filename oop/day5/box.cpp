#include <iostream>

using namespace std;

class box {
    double l, b, h;

    double vol() const;

public:

    box(const double, const double, const double);

    friend double volDiff(const box &, const box &);
};

#define abs(x) ((x) > 0 ? (x) : -(x))

box::box(const double len, const double bre, const double hgt) :
    l(len), b(bre), h(hgt) {
    cout << "Initialized box with dimensions: ";
    cout << "(" << l << ", " << b << ", " << h << ")" << endl;
}

double box::vol() const {
    return (l * b * h);
}

double volDiff(const box &b1, const box &b2) {
    cout << "Volume of box 1  : " << b1.vol() << endl;
    cout << "Volume of box 2  : " << b2.vol() << endl;
    return abs(b1.vol() - b2.vol());
}

int main() {
    box b1(1, 2, 3), b2(2, 3, 4);
    cout << "Volume difference: " << volDiff(b1, b2) << endl;
    return 0;
}
