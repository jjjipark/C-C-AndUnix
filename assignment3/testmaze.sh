#!/bin/bash

./maze input.txt > maze_output.txt
diff output.txt maze_output.txt
