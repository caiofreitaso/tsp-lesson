#ifndef __LOAD_INSTANCE_H__
#define __LOAD_INSTANCE_H__

#include <stdio.h>

int load_instance(Matrix* distance, int* size, char const* filename) {
  FILE *file;

  file = fopen(filename, "r");
  if (file == NULL) return 0;

  fscanf(file, "N: %d\n", size);
  Matrix_init(distance, *size);

  int skiped_lines;
  fscanf(file, "M: %d\n", &skiped_lines);
  skiped_lines += 2;

  int i;
  for (i = 0; i < skiped_lines; i++)
    fscanf(file, "%*[^\n]\n");

  int j;
  for (i = 0; i < *size; i++)
    for (j = 0; j < *size; j++)
      fscanf(file, "%d", &(*distance)[i][j]);

  fclose(file);
  return 1;
}

#endif
