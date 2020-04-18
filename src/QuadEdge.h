/* A node on a QuadEdge Mesh */
struct QuadEdge;
typedef struct QuadEdge QuadEdge;

/* Access vertex / face information */
Point2d origin(QuadEdge*);
Point2d dest(QuadEdge*);
Point2d left(QuadEdge*);
Point2d right(QuadEdge*);

/* Access rotated quad-edge information */
QuadEdge* rot(QuadEdge*);
QuadEdge* sym(QuadEdge*);
QuadEdge* invrot(QuadEdge*);

/*
    Access neighbouring edges.
    Function names follow the pattern:
    _next: counter-clockwise neighbour
    _prev: clockwise neighbour
    o_: around origin vertex
    d_: around dest   vertex
    r_: around left   face
    l_: around right  face
*/
QuadEdge* onext(QuadEdge*);
QuadEdge* dnext(QuadEdge*);
QuadEdge* rnext(QuadEdge*);
QuadEdge* lnext(QuadEdge*);

QuadEdge* oprev(QuadEdge*);
QuadEdge* dprev(QuadEdge*);
QuadEdge* rprev(QuadEdge*);
QuadEdge* lprev(QuadEdge*);

/* Edge manipulation */
QuadEdge* make_edge(Point2d, Point2d);
void      delete_edge(QuadEdge*);
void      splice(QuadEdge*, QuadEdge*);
QuadEdge* connect(QuadEdge*, QuadEdge*);
