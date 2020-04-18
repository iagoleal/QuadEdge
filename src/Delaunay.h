/* Type containing a mesh */
struct Mesh {
    QuadEdge* left;
    QuadEdge* right;
};
typedef struct Mesh Mesh;

Mesh triangulate(Point2d*, unsigned int);
