#include "../include/optimizer.h"
#include "../include/load-instance.h"
#include <stdio.h>

void print_solution(Solution this, int size) {
  int i;
  printf("[ ");
  for (i = 0; i < size; i++) printf("%d ", this[i]);
  printf("]\n");
}

int print_usage(char const* programname) {
  printf("Usage: %s instance_file\n", programname);
  printf("\n");
  printf("  instance_file must have the following pattern:\n");
  printf("  SIZE\n");
  printf("  [0, 0]      ... [0, SIZE-1]\n");
  printf("    .                   .\n");
  printf("    .                   .\n");
  printf("    .                   .\n");
  printf("  [SIZE-1, 0] ... [SIZE-1, SIZE-1]\n");

  return 1;
}

int main(int argc, char const* argv[]) {
  int size;
  Matrix distance;

  if (argc != 2) {
    return print_usage(argv[0]);
  }
  if (!load_instance(&distance, &size, argv[1])) {
    return print_usage(argv[0]);
  }

  Solution best = optimizer(distance, size);

  print_solution(best, size);
  printf("Value: %d\n", objective_function(distance, best, size));

  return 0;
}
