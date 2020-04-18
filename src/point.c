#include <stdlib.h>
#include <math.h>
#include "point.h"

/* Dealing with points */
int point_isequal(point a, point b) {
    return a.x == b.x && a.y == b.y;
}

/* Euclidian distance */
double dist2(point a, point b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

int lex_compare(point a, point b) {
    if (a.x > b.x || a.x == b.x && a.y > b.y)
        return 1;
    if (a.x < b.x || a.x == b.x && a.y < b.y)
        return -1;
    return 0;
}

/*
 Random point generation
*/

/* A double on an interval */
double rand_double(double from, double to) {
    return (double)rand() / RAND_MAX * (to - from) + from;
}

#define rand_unit() rand_double(0.0,1.0)

point rand_point(double min_x, double max_x, double min_y, double max_y) {
    point a;
    a.x = rand_double(min_x, max_x);
    a.y = rand_double(min_y, max_y);
    return a;
}

point* whitenoise(unsigned int n, double min_x, double max_x, double min_y, double max_y) {
    point *pts, *p;
    pts = malloc(n * sizeof(*pts));
    for (p=pts; p < pts + n; ++p) {
        p->x = rand_double(min_x, max_x);
        p->y = rand_double(min_y, max_y);
    }
    return pts;
}
