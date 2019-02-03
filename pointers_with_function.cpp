#include <stdio.h>

void copy_swap_func(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void swap_func(int *a, int *b) {
  if (a != nullptr && b != nullptr) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  } else {
    printf("One of the argument is null\n");
  }
}

int main(void) {
  int first_value = 10;
  int second_value = 20;
  printf("Before swaping first value is %d second value is %d \n", first_value, second_value);
  copy_swap_func(first_value, second_value); // ничего не измениться т.к. внутри функции происходим обмен данными для копий
  printf("After swaping first value is %d second value is %d \n", first_value, second_value);
  swap_func(&first_value, &second_value);
  printf("After ptr swaping first value is %d second value is %d \n", first_value, second_value);
  swap_func(&first_value, nullptr); // напечатаеться сообщение что один из аргументов null
  return 0;
}