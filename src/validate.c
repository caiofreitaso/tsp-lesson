#include "../include/validate.h"

int greater_than(const void* a, const void* b) {
  return *(int*) a > *(int*) b;
}

int is_cycle(Solution this, int size) {
  Solution copy;

  Solution_copy(&copy, this, size);
  qsort(copy, size, sizeof(int), greater_than);

  int i, result = 1;
  for (i = 1; i < size; i++)
    if (copy[i] == copy[i - 1]) {
      result = 0;
      break;
    }

  free(copy);
  return result;
}

int only_valid_elements(Solution this, int size) {
  int i;
  for (i = 0; i < size; i++)
    if (this[i] >= size || this[i] < 0)
      return 0;
  return 1;
}
