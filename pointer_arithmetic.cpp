#include <iostream>
#include <stdlib.h>

// Печать содержимого динамического массива, используя указатель на начало массива
// и указатель на элемент следующий за последним элементом массива
void print(int *begin, int *end) {
  if (begin != nullptr && end != nullptr && begin != end) {
    while (begin != end) {
      std::cout << " Value = " << *(begin++);
    }
    std::cout << "\n";
  }
}

void stack_arithmetic() {
  int a = 10;
  int b = 20;
  std::cout << " a = " << a << " b = " << b << "\n";

  int *ptr = &a;
  // if compile project with optimization flag (-O2) this behaviour is undefined
  // but if compiled without optimization flag probably print 10 and 20
  std::cout << " ptr to a = " << *ptr << " ptr to b = " << *(++ptr) << "\n";
}
int main(void) {
  int *ptr_array = (int *)malloc(6 * sizeof(int));
  int *begin = ptr_array;
  int *end = ptr_array + 6l;
  char counter = 0;
  while (begin != end) {
    *(begin++) = ++counter; 
  }
  print((begin = ptr_array), end);

  void *void_ptr = ptr_array;
  //++void_ptr; // любая адрессная арифиметика для нетипизированого указателя запрещена
  free(void_ptr);

  int *ptr_value = (int *)malloc(sizeof(int));
  *ptr_value = 20;
  std::cout << "Int ptr value is " << *ptr_value << "\n";
  // ++ptr_value; // является неопределенным элементом, т.к. выход за границы выделенной памяти
  stack_arithmetic();
  return 0;
}