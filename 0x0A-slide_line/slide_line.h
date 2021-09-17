#ifndef SLINE_LINE_H
#define SLINE_LINE_H

#include <stdio.h>
#include <stdlib.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void slide_left(int *line, size_t size);
void slide_right(int *line, size_t size);

#endif /* SLINE_LINE_H */
