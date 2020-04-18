#include <stdlib.h>
#include "point.h"
#include "QuadEdge.h"

/* Types used on this module */
struct QuadEdge {
    struct Point2d   origin;
    struct QuadEdge* rot;
    struct QuadEdge* onext;
};

/* Access Vertex information */
Point2d origin(QuadEdge* e) {
    return e->origin;
}

Point2d dest(QuadEdge* e) {
    return origin(sym(e));
}

Point2d right(QuadEdge* e) {
    return origin(rot(e));
}

Point2d left(QuadEdge* e) {
    return origin(invrot(e));
}

/* Access QuadEdge components */
QuadEdge* rot(QuadEdge* e) {
    return e->rot;
}

QuadEdge* sym(QuadEdge* e) {
    return rot(rot(e));
}

QuadEdge* invrot(QuadEdge* e) {
    return rot(sym(e));
}


/* Next edges ccw */
QuadEdge* onext(QuadEdge* e) {
    return e->onext;
}

QuadEdge* lnext(QuadEdge* e) {
    return rot(onext(invrot(e)));
}

QuadEdge* rnext(QuadEdge* e) {
    return invrot(onext(rot(e)));
}

QuadEdge* dnext(QuadEdge* e) {
    return sym(onext(sym(e)));
}

/* Prev edges (cw) */
QuadEdge* oprev(QuadEdge* e) {
    return rot(onext(rot(e)));
}

QuadEdge* lprev(QuadEdge* e) {
    return sym(onext(e));
}

QuadEdge* rprev(QuadEdge* e) {
    return onext(sym(e));
}

QuadEdge* dprev(QuadEdge* e) {
    return invrot(onext(invrot(e)));
}

/* Generate a new valid edge e going from x to y.
   Satisfies:
     - onext(e) = e
     - onext(sym(e)) = sym(e)
     - onext(rot(e)) = invrot(e)
     - onext(invrot(e)) = rot(e)
*/
QuadEdge* make_edge(Point2d x, Point2d y) {
    QuadEdge* e1 = malloc(sizeof *e1);
    QuadEdge* e2 = malloc(sizeof *e2);
    QuadEdge* e3 = malloc(sizeof *e3);
    QuadEdge* e4 = malloc(sizeof *e4);
    e1->origin = x; /* Set origin */
    e3->origin = y; /* Set destination */
    e1->rot = e2;
    e2->rot = e3;
    e3->rot = e4;
    e4->rot = e1;
    e1->onext = e1;
    e2->onext = e4;
    e3->onext = e3;
    e4->onext = e2;
    return e1;
}

void splice(QuadEdge* a, QuadEdge* b) {
    QuadEdge* temp;
    temp = a->onext->rot->onext;
    a->onext->rot->onext = b->onext->rot->onext;
    b->onext->rot->onext = temp;
    temp = a->onext;
    a->onext = b->onext;
    b->onext = temp;
}

QuadEdge* connect(QuadEdge* a, QuadEdge* b) {
    QuadEdge* c = make_edge(dest(a), origin(b));
    splice(c, lnext(a));
    splice(sym(c), b);
    return c;
}

void delete_edge(QuadEdge* e) {
    splice(e, oprev(e));
    splice(sym(e), oprev(sym(e)));
    free(rot(sym(e)));
    free(rot(e));
    free(sym(e));
    free(e);
}
