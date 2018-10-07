#ifndef __OPTIMIZER_METHOD_H__
#define __OPTIMIZER_METHOD_H__

#include "optimizer.h"

int is_valid(Solution this, int size);

void branch(Solution* best, int* best_value, Solution* current, Matrix distance, int size, int i, int value);
void leaf(Solution* best, int* best_value, Solution* current, Matrix distance, int size);
void recursive(Solution* best, int* best_value, Solution* current, Matrix distance, int size, int i);

#endif
