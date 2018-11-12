#ifndef __OPTIMIZER_METHOD_H__
#define __OPTIMIZER_METHOD_H__

#include "optimizer.h"

int is_valid(Solution this, int size);
int is_valid_vertex(Solution this, int current_size, int next_vertex);
void add_edge(OptimizerOutput* current, Matrix distance, int current_idx, int next_vertex, int initial_value);


void branch(OptimizerOutput* best, OptimizerOutput* current, Matrix distance, int size, int i);
void leaf(OptimizerOutput* best, OptimizerOutput* current, Matrix distance, int size);
void recursive(OptimizerOutput* best, OptimizerOutput* current, Matrix distance, int size, int i);

#endif
