#!/bin/bash

for FILE in test/*.o
do
  ./${FILE}
done
