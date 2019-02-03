#include <stdio.h>

int print_value(int value) {
  printf("Callback Value is = %d\n", value);
  return value + 1;
}

// обьявляем тип указатель на функцию
typedef int (*FuncCallback)(int value);

int main(void) {
  // обьявляем массив указателей на функции
  FuncCallback func_callback[] = {print_value, print_value};
  int value = 1;
  for (auto callback : func_callback) {
    value = callback(value);
  }
  return 0;
}