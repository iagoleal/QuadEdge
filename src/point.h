/* Type for point in the plane */
typedef struct point {
    double x;
    double y;
} point;

/* Functions on points */
int    point_isequal(point, point);
int    lex_compare(point, point);
double dist2(point, point);

/* Generating random points */
double rand_double(double, double);
point  rand_point(double, double, double, double);
point* whitenoise(unsigned int,double, double, double, double);
