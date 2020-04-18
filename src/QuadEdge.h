/* A node on a QuadEdge Mesh */
struct QuadEdge;
typedef struct QuadEdge QuadEdge;

/* A Mesh structure for QuadEdges */
struct Mesh {
    point    *vertices;
    QuadEdge *left;
    QuadEdge *right;
};
typedef struct Mesh Mesh;

/* Find Delaunay triangulation */
Mesh triangulate(point*, unsigned int);

/* Access vertex / face information */
point origin(QuadEdge*);
point dest(QuadEdge*);
point left(QuadEdge*);
point right(QuadEdge*);

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
QuadEdge* make_edge(point, point);
void      delete_edge(QuadEdge*);
void      splice(QuadEdge*, QuadEdge*);
QuadEdge* connect(QuadEdge*, QuadEdge*);
