#include<iostream>
#include <stdlib.h>

void stack_seq_check() {
  int a = 10;
  int b = 20;

  int *ptr1 = &a;
  int *ptr2 = &b;
  std::cout << "ptr1 address " << ptr1 << " ptr2 address " << ptr2 << "\n";
  if (ptr1 < ptr2) { // может быть тоже неопределенным поведением (compiler reordining)
    std::cout << "ptr1 > ptr2 \n";
  }
}

void check_on_null(int *a, int *b) {
  if (a == nullptr || b == nullptr) {
    std::cout << "a or b is null \n";
    return;
  }
  if (a != b) {
    std::cout << "a and b is diferent \n";
  } else if (a == b) {
    std::cout << "a and b is the same \n";
  }
}

int main(void) {
  int *ptr = (int *)malloc(sizeof(int));
  int *ptr1 = (int *)malloc(sizeof(int));
  std::cout << "ptr address " << ptr << " ptr1 address " << ptr1 << "\n";
  if (ptr < ptr1) { // неопределенное поведение
    std::cout << "ptr < ptr1 \n" ;
  }
  stack_seq_check();
  int a = 20;
  int b = 30;
  check_on_null(&a, &b); // print a and b is different
  check_on_null(&a, &a); // print a and b is the same
  return 0;
}