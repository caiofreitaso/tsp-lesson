#include "../include/optimizer-method.h"
#include "../include/load-instance.h"
#include <stdio.h>

void print_array(Solution this, int size) {
  int i;
  for (i = 0; i < size; i++) printf("%d ", this[i]);
}

void print_solution(Solution this, int size) {
  printf("[ ");
  print_array(this, size);
  printf("]\n");
}

int print_usage(char const* programname) {
  printf("Usage: %s instance_file\n", programname);
  printf("\n");
  printf("  instance_file from http://www.cs.nott.ac.uk/~pszdk/gtsp.html\n");

  return 1;
}

void print_matrix(Matrix distance, int size) {
  int i;
  for (i = 0; i < size; i++) {
    print_array(distance[i], size);
    printf("\n");
  }
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

//  print_matrix(distance, size);

  OptimizerOutput output = optimizer(distance, size, recursive);

  print_solution(output.best, size);
  printf("Value: %d\n", output.best_value);
  printf("Time: %f s\n", output.seconds);

  Matrix_free(distance, size);
  Solution_free(output.best);
  return 0;
}
