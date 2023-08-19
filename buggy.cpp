#include <iostream>
#include <string.h>

// hi, again
// FIXME: add appropriate declarative region to scope
using namespace std;

struct Point {
    int x, y;

    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
};

class Shape {
    int vertices;
    Point** points;

// FIXME: add appropriate access modifier
public:
    Shape (int _vertices) {
        vertices = _vertices;
        points = new Point*[vertices+1];
    }

    ~Shape () {
        // FIXME: fill out destructor to avoid memory leaks
        for (int i = 0; i <= vertices; i++) {
            delete points[i];
        }
        delete[] points;
    }

    // FIXME: add formal parameter for unsized array called pts
    void addPoints (Point pts[]) {
        for (int i = 0; i <= vertices; i++) {
            // FIXME: add allocation of Point
            points[i] = new Point();
            memcpy(points[i], &pts[i%vertices], sizeof(Point));
        }
    }

    // FIXME: correct inner computation to return pointer on heap
    //        instead of pointer to value on stack
    double area () {
        int temp = 0;
        // FIXME: fix end of for loop (< instead of <=)
        for (int i = 0; i < vertices; i++) {
            // FIXME: fix pointer member access (-> or (*p). instead of .)
            //        use one method for lhs and the other for rhs
            int lhs = points[i]->x * points[i+1]->y;
            int rhs = (*points[i+1]).x * (*points[i]).y;
            temp += (lhs - rhs);
        }
        double area = abs(temp)/2.0;
        return area;
    }
};

int main () {
    // FIXME: create the following points using the three different methods
    //        of defining structs:
    //          tri1 = (0, 0)
    //          tri2 = (1, 2)
    //          tri3 = (2, 0)
    struct Point tri1(0, 0);
    struct Point tri2 = {1, 2};
    struct Point tri3;
    tri3.x = 2;
    tri3.y = 0;

    Point triPts[3] = {tri1, tri2, tri3};
    Shape* tri = new Shape(3);
    tri->addPoints(triPts);

    // FIXME: create the following points using your preferred struct
    //        definition:
    //          quad1 = (0, 0)
    //          quad2 = (0, 2)
    //          quad3 = (2, 2)
    //          quad4 = (2, 0)
    struct Point quad1(0, 0);
    struct Point quad2(0, 2);
    struct Point quad3(2, 2);
    struct Point quad4(2, 0);

    Point quadPts[4] = {quad1, quad2, quad3, quad4};
    Shape* quad = new Shape(4);
    quad->addPoints(quadPts);

    // FIXME: print out area of triangle and area of square
    double triArea = tri->area();
    cout << triArea << endl;
    double quadArea = quad->area();
    cout << quadArea << endl;

    // FIXME: clean-up dynamically allocated memory to avoid memory leaks
    delete tri;
    delete quad;
}
