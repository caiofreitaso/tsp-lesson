#include "../include/validate.h"
#include <assert.h>
#include <stdio.h>

const int SIZE = 5;

int main() {
  int not_a_cycle[] = { 0, 3, 2, 1, 1 };
  int invalid_elements[] = { 1, 2, 3, 4, 5 };
  int valid[] = { 0, 1, 2, 3, 4 };

  printf("Invalid elements...\n");
  assert(only_valid_elements(invalid_elements, SIZE) == 0);
  printf(" only_valid_elements OK\n");

  printf("Not a cycle...\n");
  assert(is_cycle(not_a_cycle, SIZE) == 0);
  printf("  is_cycle OK\n");

  printf("Valid...\n");
  assert(is_cycle(valid, SIZE) == 1);
  printf("  is_cycle OK\n");
  assert(only_valid_elements(valid, SIZE) == 1);
  printf("  only_valid_elements OK\n");

}
