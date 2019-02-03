#include <stdio.h>
#include <stdlib.h>

size_t const array_size = 5;

// необходимо передавать двойной указатель т.к. в функции выделяеться память для
// каждого элемента массива, т.е. необходимо перезаписать адресс 
void allocate_memory(int **memory) {
  *memory = (int *)malloc(array_size * sizeof(int));
  for (size_t i = 0; i < array_size; ++i) {
    (*memory)[i] = i + 1;
  }
}

int main(void) {
  int *array[array_size] = {0};
  for (auto &ptr : array)
    allocate_memory(&ptr);

  for (size_t i = 0; i < array_size; ++i) {
    for (size_t j = 0; j < array_size; ++j) {
      printf("Array [%zu][%zu] = %d\n", i, j, array[i][j]);
    }
  }
  // надо не забывать освобождать выделенную память,
  // т.к. буде утечка памяти
  for (auto &ptr: array) {
    if (ptr != nullptr) {
      free(ptr);
    }
  }
  return 0;
}