/* Type for point in the plane */
typedef struct Point2d {
    double x;
    double y;
} Point2d;

/* Functions on points */
int point_isequal(Point2d, Point2d);
int lex_compare(Point2d, Point2d);

/* Generating random points */
double rand_double(double,double);
Point2d rand_point(double,double,double,double);
Point2d* whitenoise(unsigned int,double,double,double,double);
