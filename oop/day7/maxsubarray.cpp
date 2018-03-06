#include <iostream>

#define INT_MIN (1 << (sizeof(int)*8 - 1))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define print(msg) {                            \
    if (argc == 2 && **(argv + 1) == 'p')       \
      cout << msg;                              \
  }

int main(int argc, char **argv) {
  using namespace std;
  int a, maxSum = INT_MIN;
  int n, sum = 0, max = INT_MIN;
  bool fpos = false;
  print("Enter n: ");
  cin >> n;
  print("\nEnter elements: ");
  while (n--) {
    cin >> a;
    max = MAX(max, a);
    fpos = a > 0 ? true : fpos;
    sum += a;
    sum = sum < 0 ? 0 : sum;
    maxSum = MAX(maxSum, sum);
  }
  print("\nMax Sum: ");
  cout << (fpos ? maxSum : max) << endl;
  return 0;
}
