#include <stdio.h>

void printFib(int n) {
  int a = 0, b = 1, c;
  if (n > 0) {
    printf("%d", a);
  }
  if (n > 1) {
    printf(", %d", b);
  }
  if (n > 2) {
    for (int i = 2; i < n; ++i) {
      c = a + b;
      a = b;
      b = c;
      printf(", %d", c);
    }
  }
  printf("\n");
}

int main() {
  using namespace std;
  int n;
  printf("Enter n: ");
  scanf("%d", &n);
  printFib(n);
  return 0;
}
