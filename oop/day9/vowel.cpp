#include <iostream>
#include <cctype>

template <typename T>
void checkVowel(const T *arr) {
  for (int i = 0; arr[i]; i++)
    switch (tolower(arr[i])) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      throw "Vowel found";
    }
}

int main() {
  using namespace std;
  try {
    char c[15];
    cout << "Enter a word: ";
    cin >> c;
    checkVowel(c);
    cout << "No vowels found";
  } catch (const char *c) {
    cout << c;
  }
  cout << endl;
  return 0;
}
