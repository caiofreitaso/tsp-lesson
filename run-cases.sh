#!/bin/bash

find cases/ -type f -name instance* | sort --version-sort | xargs -n1 ./main
