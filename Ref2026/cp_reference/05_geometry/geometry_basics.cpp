// ============================================================================
//                               GEOMETRY
// ============================================================================

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double t) const { return Point(x * t, y * t); }
    double operator*(const Point &p) const { return x * p.x + y * p.y; } // dot product
    double operator^(const Point &p) const { return x * p.y - y * p.x; } // cross product
};

// Purpose: Euclidean distance between two points
// Time: O(1)
double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
// Count lattice points on line segment from (x1,y1) to (x2,y2)
ll latticePointsOnSegment(ll x1, ll y1, ll x2, ll y2) {
    return gcd(abs(x2 - x1), abs(y2 - y1)) + 1;
}

// Purpose: Manhattan distance between two points
// Time: O(1)
double manhattanDist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

ll euclideanDist2(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

ll manhattanDist(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Purpose: Rotate point by angle (in radians)
// Time: O(1)
void rotate(Point &p, double angle) {
    double x_new = p.x * cos(angle) - p.y * sin(angle);
    double y_new = p.x * sin(angle) + p.y * cos(angle);
    p.x = x_new;
    p.y = y_new;
}

double calculateAngleWith_X_Axis(Point p1, Point p2) {
    return atan2(p2.y - p1.y, p2.x - p1.x);
}

// BASIC GEOMETRIC FORMULAS:

// Area of triangle using coordinates
double triangleArea(Point a, Point b, Point c) {
    return abs((b - a) ^ (c - a)) / 2.0;
}

// Check if three points are collinear
bool areCollinear(Point a, Point b, Point c) {
    return abs((b - a) ^ (c - a)) < 1e-9;
}

// Orientation test: returns positive if counterclockwise, negative if clockwise, 0 if collinear
double orientation(Point a, Point b, Point c) {
    return (b - a) ^ (c - a);
}

// Check if point lies on line segment
bool pointOnSegment(Point p, Point a, Point b) {
    return areCollinear(p, a, b) &&
           min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

// CIRCLE GEOMETRY:

struct Circle {
    Point center;
    double radius;
    Circle(Point c = Point(), double r = 0) : center(c), radius(r) {}
};

// Circle through three points
Circle circumcircle(Point a, Point b, Point c) {
    double d = 2 * ((b - a) ^ (c - a));
    if (abs(d) < 1e-9)
        return Circle(); // Points are collinear

    double ux = ((b - a) * (b - a)) * (c.y - a.y) - ((c - a) * (c - a)) * (b.y - a.y);
    double uy = ((c - a) * (c - a)) * (b.x - a.x) - ((b - a) * (b - a)) * (c.x - a.x);

    Point center = Point(a.x + ux / d, a.y + uy / d);
    double radius = dist(center, a);

    return Circle(center, radius);
}

// Check if point is inside circle
bool pointInCircle(Point p, Circle c) {
    return dist(p, c.center) <= c.radius + 1e-9;
}

// Circle-circle intersection
vector<Point> circleIntersection(Circle c1, Circle c2) {
    double d = dist(c1.center, c2.center);
    if (d > c1.radius + c2.radius || d < abs(c1.radius - c2.radius) || d == 0) {
        return {}; // No intersection or infinite intersections
    }

    double a = (c1.radius * c1.radius - c2.radius * c2.radius + d * d) / (2 * d);
    double h = sqrt(c1.radius * c1.radius - a * a);

    Point p = c1.center + (c2.center - c1.center) * (a / d);
    Point delta = Point(-(c2.center.y - c1.center.y), c2.center.x - c1.center.x) * (h / d);

    return {p + delta, p - delta};
}

// LINE GEOMETRY:

struct Line {
    double a, b, c; // ax + by + c = 0
    Line(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}
    Line(Point p1, Point p2) {
        if (abs(p1.x - p2.x) < 1e-9) {
            a = 1;
            b = 0;
            c = -p1.x;
        } else {
            a = p2.y - p1.y;
            b = p1.x - p2.x;
            c = p2.x * p1.y - p1.x * p2.y;
        }
        double norm = sqrt(a * a + b * b);
        a /= norm;
        b /= norm;
        c /= norm;
    }
};

// Distance from point to line
double pointToLineDistance(Point p, Line l) {
    return abs(l.a * p.x + l.b * p.y + l.c);
}

// Line intersection
Point lineIntersection(Line l1, Line l2) {
    double det = l1.a * l2.b - l2.a * l1.b;
    if (abs(det) < 1e-9)
        return Point(1e9, 1e9); // Parallel lines

    double x = (l2.c * l1.b - l1.c * l2.b) / det;
    double y = (l1.c * l2.a - l2.c * l1.a) / det;
    return Point(x, y);
}

// Perpendicular line through point
Line perpendicular(Line l, Point p) {
    return Line(-l.b, l.a, l.b * p.x - l.a * p.y);
}

// Parallel line through point
Line parallel(Line l, Point p) {
    return Line(l.a, l.b, -l.a * p.x - l.b * p.y);
}

// POLYGON GEOMETRY:

// Area of simple polygon (positive if counterclockwise)
double polygonArea(vector<Point> &poly) {
    double area = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        area += poly[i] ^ poly[(i + 1) % n];
    }
    return area / 2.0;
}

// Check if polygon is convex
bool isConvex(vector<Point> &poly) {
    int n = poly.size();
    if (n < 3)
        return false;

    bool positive = false, negative = false;
    for (int i = 0; i < n; i++) {
        double cross = orientation(poly[i], poly[(i + 1) % n], poly[(i + 2) % n]);
        if (cross > 1e-9)
            positive = true;
        if (cross < -1e-9)
            negative = true;
        if (positive && negative)
            return false;
    }
    return true;
}

// Point in polygon test (ray casting)
bool pointInPolygon(Point p, vector<Point> &poly) {
    int n = poly.size();
    bool inside = false;

    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((poly[i].y > p.y) != (poly[j].y > p.y)) &&
            (p.x < (poly[j].x - poly[i].x) * (p.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

// Convex hull (Graham scan)
vector<Point> convexHull(vector<Point> points) {
    int n = points.size();
    if (n <= 1)
        return points;

    sort(points.begin(), points.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    // Build lower hull
    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 &&
               orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    // Build upper hull
    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > lower_size &&
               orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back(); // Remove duplicate point
    return hull;
}

// ADVANCED TECHNIQUES:

// Rotating calipers - find diameter of convex polygon
double rotatingCalipers(vector<Point> &hull) {
    int n = hull.size();
    if (n <= 1)
        return 0;
    if (n == 2)
        return dist(hull[0], hull[1]);

    double maxDist = 0;
    int j = 1;

    for (int i = 0; i < n; i++) {
        Point edge = hull[(i + 1) % n] - hull[i];

        while (true) {
            Point toNext = hull[(j + 1) % n] - hull[j];
            if ((edge ^ toNext) <= 0)
                break;
            j = (j + 1) % n;
        }

        maxDist = max(maxDist, max(dist(hull[i], hull[j]),
                                   dist(hull[(i + 1) % n], hull[j])));
    }

    return maxDist;
}

// Closest pair of points (divide and conquer)
double closestPairRec(vector<Point> &px, vector<Point> &py) {
    int n = px.size();
    if (n <= 3) {
        double minDist = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                minDist = min(minDist, dist(px[i], px[j]));
            }
        }
        return minDist;
    }

    int mid = n / 2;
    Point midPoint = px[mid];

    vector<Point> pyl(mid), pyr(n - mid);
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++) {
        if (py[i].x <= midPoint.x && li < mid)
            pyl[li++] = py[i];
        else
            pyr[ri++] = py[i];
    }

    vector<Point> pxl(px.begin(), px.begin() + mid);
    vector<Point> pxr(px.begin() + mid, px.end());

    double dl = closestPairRec(pxl, pyl);
    double dr = closestPairRec(pxr, pyr);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = 0; i < n; i++) {
        if (abs(py[i].x - midPoint.x) < d) {
            strip.push_back(py[i]);
        }
    }

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }

    return d;
}

double closestPair(vector<Point> &points) {
    vector<Point> px = points, py = points;
    sort(px.begin(), px.end(), [](Point a, Point b) { return a.x < b.x; });
    sort(py.begin(), py.end(), [](Point a, Point b) { return a.y < b.y; });
    return closestPairRec(px, py);
}

// GEOMETRIC CONSTANTS & FORMULAS:

const double GOLDEN_RATIO = (1.0 + sqrt(5.0)) / 2.0;

// Regular polygon properties
double regularPolygonArea(int n, double sideLength) {
    return (n * sideLength * sideLength) / (4 * tan(PI / n));
}

double regularPolygonPerimeter(int n, double sideLength) {
    return n * sideLength;
}

double regularPolygonCircumradius(int n, double sideLength) {
    return sideLength / (2 * sin(PI / n));
}

double regularPolygonInradius(int n, double sideLength) {
    return sideLength / (2 * tan(PI / n));
}

// COORDINATE TRANSFORMATIONS:

// Translate point
Point translate(Point p, double dx, double dy) {
    return Point(p.x + dx, p.y + dy);
}

// Scale point from origin
Point scale(Point p, double sx, double sy) {
    return Point(p.x * sx, p.y * sy);
}

// Reflect point across line y = mx + b
Point reflect(Point p, double m, double b) {
    double a = -m, c = -b; // Line: ax + y + c = 0
    double norm = a * a + 1;
    double x = p.x - 2 * a * (a * p.x + p.y + c) / norm;
    double y = p.y - 2 * (a * p.x + p.y + c) / norm;
    return Point(x, y);
}

// SPECIAL TRIANGLES:

// Check if triangle is right-angled
bool isRightTriangle(Point a, Point b, Point c) {
    double ab = dist(a, b), bc = dist(b, c), ca = dist(c, a);
    vector<double> sides = {ab, bc, ca};
    sort(sides.begin(), sides.end());
    return abs(sides[0] * sides[0] + sides[1] * sides[1] - sides[2] * sides[2]) < 1e-9;
}

// Triangle centers
Point centroid(Point a, Point b, Point c) {
    return Point((a.x + b.x + c.x) / 3, (a.y + b.y + c.y) / 3);
}

Point circumcenter(Point a, Point b, Point c) {
    return circumcircle(a, b, c).center;
}

Point orthocenter(Point a, Point b, Point c) {
    Line altA = perpendicular(Line(b, c), a);
    Line altB = perpendicular(Line(a, c), b);
    return lineIntersection(altA, altB);
}

// Normalize a direction vector (dx, dy)
// helpful to know points that are on same line.
void normalizeDirection(long long &dx, long long &dy) {
    // --- Step 1: Handle signs consistently ---
    if (dx * dy < 0) {
        // Opposite signs → make dx negative, dy positive
        dx = -abs(dx);
        dy = abs(dy);
    } else if (dx * dy > 0) {
        // Same signs → make both positive
        dx = abs(dx);
        dy = abs(dy);
    } else {
        // One of them is zero (pure horizontal or vertical)
        if (dy)
            dy = 1e6; // placeholder to represent "vertical"
        if (dx)
            dx = 1e6; // placeholder to represent "horizontal"
    }

    // --- Step 2: Reduce to simplest ratio ---
    long long g = std::gcd(abs(dx), abs(dy));
    if (g != 0) {
        dx /= g;
        dy /= g;
    }
}
