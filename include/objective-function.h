#ifndef __OBJECTIVE_FUNCTION_H__
#define __OBJECTIVE_FUNCTION_H__

#include "tsp.h"

int objective_function(Matrix distance, Solution cycle, int size) {
  int result = 0;
  int origin_city, target_city;
  int i;

  for (i = 1; i < size; i++) {
    origin_city = cycle[i - 1];
    target_city = cycle[i];
    result += distance[origin_city][target_city];
  }

  origin_city = cycle[size - 1];
  target_city = cycle[0];
  result += distance[origin_city][target_city];

  return result;
}

#endif
