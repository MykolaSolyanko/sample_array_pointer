#include <stdio.h>
#include <stdlib.h>

int* allocate_memory() {
  int *memory = new int(100);
  return memory;
}

int main(void) {
  // в C++ необходимо явно преобразовывать возращаемый тип в функции malloc, т.к. функция возвращает нетипизированный указатель
  int *ptr = (int *)malloc(sizeof(int));
  printf("Value in ptr is %d \n", *ptr); // содержит муссор
  *ptr = 54;
  printf("Value in ptr is %d \n", *ptr); // print 54
  free(ptr);
  // free(ptr); // our program is crash double free
  ptr = nullptr;
  // free(ptr); // our program crash, ptr is null
  ptr = (int *)calloc(1, sizeof(int));
  printf("Value in ptr is %d \n", *ptr); // согласно документации calloc - the memory is set to zero.
  free(ptr);

  // C++ allocate memory style
  ptr = new int(20); // в отличии от системных функций в операторе new можно указывать инициализирующее значение 
  printf("Value in ptr is %d \n", *ptr); // print 20
  delete ptr; 

  const int count_memory = 5;
  // Allocate memory for array
  ptr = (int *)malloc(count_memory * sizeof(int)); // or calloc(count_memory, sizeof(int))
  free(ptr);

  ptr = new int [count_memory] {1,2,3,4}; // значения можно инициализировать также как массивы
  // delete ptr; // memory leaks
  delete[] ptr;
  
  auto ptr1 = allocate_memory();
  printf("Value in ptr1 is %d \n", *ptr1); // print 100
  delete ptr1;
  return 0;
}