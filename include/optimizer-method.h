#ifndef __OPTIMIZER_METHOD_H__
#define __OPTIMIZER_METHOD_H__

#include "optimizer.h"

int is_valid(Solution this, int size);

void branch(OptimizerOutput* best, Solution* current, Matrix distance, int size, int i);
void leaf(OptimizerOutput* best, Solution* current, Matrix distance, int size);
void recursive(OptimizerOutput* best, Solution* current, Matrix distance, int size, int i);

#endif
