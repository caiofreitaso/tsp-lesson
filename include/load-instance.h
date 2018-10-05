#ifndef __LOAD_INSTANCE_H__
#define __LOAD_INSTANCE_H__

#include <stdio.h>

int load_instance(Matrix* distance, int* size, char const* filename) {
  FILE *file;

  file = fopen(filename, "r");
  if (file == NULL) return 0;

  fscanf(file, "%d", size);
  Matrix_init(distance, *size);

  int i, j;
  for (i = 0; i < *size; i++)
    for (j = 0; j < *size; j++)
      fscanf(file, "%d", &(*distance)[i][j]);

  fclose(file);
  return 1;
}

#endif
