#include "../include/optimizer-method.h"

int is_valid(Solution this, int size) {
  return is_cycle(this, size) && only_valid_elements(this, size);
}

int is_valid_vertex(Solution this, int current_size, int next_vertex) {
  int i;
  for (i = 0; i < current_size; i++) {
    if (this[i] == next_vertex) {
      return 0;
    }
  }
  return 1;
}

void add_edge(OptimizerOutput* current, Matrix distance, int current_idx, int next_vertex, int initial_value) {
  int previous = current->path[current_idx - 1];
  current->value = initial_value + distance[previous][next_vertex];
}

void branch(OptimizerOutput* best, OptimizerOutput* current, Matrix distance, int size, int i) {
  int j;
  for (j = 0; j < size; j++) {
    current->path[i] = j;
    recursive(best, current, distance, size, i+1);
  }
}

void leaf(OptimizerOutput* best, OptimizerOutput* current, Matrix distance, int size) {
  if (is_valid(current->path, size)) {
    update_best(best, *current, distance, size);
  }
}

void recursive(OptimizerOutput* best, OptimizerOutput* current, Matrix distance, int size, int i) {
  if (i < size) {
    branch(best, current, distance, size, i);
  } else {
    leaf(best, current, distance, size);
  }
}
