#include <stdlib.h>
#include "point.h"

/* Dealing with points */
int point_isequal(Point2d a, Point2d b) {
    return a.x == b.x && a.y == b.y;
}

/*
 Random point generation
*/

/* A double on an interval */
double rand_double(double from, double to) {
    return (double)rand() / RAND_MAX * (to - from) + from;
}

#define rand_unit() rand_double(0.0,1.0)

Point2d rand_point(double min_x, double max_x, double min_y, double max_y) {
    Point2d a;
    a.x = rand_double(min_x, max_x);
    a.y = rand_double(min_y, max_y);
    return a;
}

Point2d* whitenoise(unsigned int n, double min_x, double max_x, double min_y, double max_y) {
    Point2d *pts, *p;
    pts = malloc(n * sizeof(*pts));
    for (p=pts; p < pts + n; ++p) {
        p->x = rand_double(min_x, max_x);
        p->y = rand_double(min_y, max_y);
    }
    return pts;
}
