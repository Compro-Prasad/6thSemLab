#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STUDENTSMAX 3
#define SUBJECTSMAX 3

typedef struct {
  int roll;
  char *name;
  float subjects[SUBJECTSMAX];
  float avg;
} student;

int getInt(const char *msg) {
  int x;
  printf("%s", msg);
  scanf("%d", &x);
  return x;
}

float getReal(const char *msg, int n) {
  float x;
  printf(msg, n);
  scanf("%f", &x);
  return x;
}

char *strInputs[100];
int strs = 0;

char *getStr(const char *msg) {
  strInputs[strs] = (char *)malloc(sizeof(char) * 20);
  printf("%s", msg);
  scanf("%s", strInputs[strs]);
  ++strs;
  return strInputs[strs - 1];
}

void freeStrInputs() {
  for (int i = 0; i < strs; ++i)
    free(strInputs[i]);
}

int main() {
  int noOfStudents = getInt("Enter number of students: ");
  student students[noOfStudents];
  for (int i = 0; i < noOfStudents; ++i) {
    printf("\tStudent %d\n", i + 1);
    students[i].roll = getInt("Enter roll number: ");
    students[i].name = getStr("Enter name: ");
    students[i].avg = 0;
    for (int j = 0; j < SUBJECTSMAX; ++j) {
      students[i].subjects[j] = getReal("Enter subject %d: ", j + 1);
      students[i].avg += students[i].subjects[j];
    }
    students[i].avg /= SUBJECTSMAX;
  }
  printf("\nName\tAverage Marks");
  for (int i = 0; i < noOfStudents; ++i) {
    printf("\n%s\t%f", students[i].name, students[i].avg);
  }
  printf("\n");
  freeStrInputs();
  return 0;
}
