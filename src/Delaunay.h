/* Type containing a mesh */
static Mesh delaunay(point*, unsigned int);
static Mesh merge(Mesh, Mesh);
Mesh make_ccw_triangle(point*);
static int left_of(point, QuadEdge*);
static int right_of(point, QuadEdge*);
static int incircle(point, point, point, point);
static int ccw(point, point, point);
static double det2(double, double, double, double);
static double det3(double, double, double, double, double, double, double, double, double);
