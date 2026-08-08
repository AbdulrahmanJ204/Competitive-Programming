// ============================================================================
// ADDITIONAL GEOMETRY FUNCTIONS FOR COMPETITIVE PROGRAMMING
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const long long INF = 1e18;

struct Point {
    long long x, y;
    int id;
    Point(long long x = 0, long long y = 0, int id = -1) : x(x), y(y), id(id) {}
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator*(long long t) const { return Point(x * t, y * t); }
    long long cross(const Point &p) const { return x * p.y - y * p.x; }
    long long dot(const Point &p) const { return x * p.x + y * p.y; }
    long long dist2() const { return x * x + y * y; }
    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator==(const Point &p) const {
        return x == p.x && y == p.y;
    }
};

// Purpose: Check if point c lies on line segment ab
// Time: O(1)
bool pointOnSegment(Point a, Point b, Point c) {
    if ((b - a).cross(c - a) != 0) return false;
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

// Purpose: Check if two line segments ab and cd intersect
// Time: O(1)
bool segmentsIntersect(Point a, Point b, Point c, Point d) {
    long long d1 = (b - a).cross(c - a);
    long long d2 = (b - a).cross(d - a);
    long long d3 = (d - c).cross(a - c);
    long long d4 = (d - c).cross(b - c);
    
    // Proper intersection (segments cross each other)
    if (((d1 > 0) != (d2 > 0)) && ((d3 > 0) != (d4 > 0))) {
        return true;
    }
    
    // Collinear cases - check if endpoints lie on the other segment
    if (d1 == 0 && pointOnSegment(a, b, c)) return true;
    if (d2 == 0 && pointOnSegment(a, b, d)) return true;
    if (d3 == 0 && pointOnSegment(c, d, a)) return true;
    if (d4 == 0 && pointOnSegment(c, d, b)) return true;
    
    return false;
}

// Purpose: Check if two segments intersect at exactly one point (no overlap)
// Time: O(1)
bool segmentsIntersectStrict(Point a, Point b, Point c, Point d) {
    long long d1 = (b - a).cross(c - a);
    long long d2 = (b - a).cross(d - a);
    long long d3 = (d - c).cross(a - c);
    long long d4 = (d - c).cross(b - c);
    
    return ((d1 > 0) != (d2 > 0)) && ((d3 > 0) != (d4 > 0));
}

// Purpose: Find intersection point of two line segments (if exists)
// Time: O(1)
// Returns: intersection point or Point(INF, INF) if no intersection
Point segmentIntersectionPoint(Point a, Point b, Point c, Point d) {
    long long d1 = (b - a).cross(c - a);
    long long d2 = (b - a).cross(d - a);
    long long d3 = (d - c).cross(a - c);
    long long d4 = (d - c).cross(b - c);
    
    // Check if segments intersect
    if (!(((d1 > 0) != (d2 > 0)) && ((d3 > 0) != (d4 > 0)))) {
        // Check collinear cases
        if (d1 == 0 && pointOnSegment(a, b, c)) return c;
        if (d2 == 0 && pointOnSegment(a, b, d)) return d;
        if (d3 == 0 && pointOnSegment(c, d, a)) return a;
        if (d4 == 0 && pointOnSegment(c, d, b)) return b;
        return Point(INF, INF); // No intersection
    }
    
    // Calculate intersection point using cross products
    long long num_x = (a.x * (b.y - a.y) - a.y * (b.x - a.x)) * (d.x - c.x) - 
                      (c.x * (d.y - c.y) - c.y * (d.x - c.x)) * (b.x - a.x);
    long long num_y = (a.x * (b.y - a.y) - a.y * (b.x - a.x)) * (d.y - c.y) - 
                      (c.x * (d.y - c.y) - c.y * (d.x - c.x)) * (b.y - a.y);
    long long den = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
    
    if (den == 0) return Point(INF, INF); // Parallel lines
    
    // Note: This returns integer coordinates only if intersection is at integer point
    return Point(num_x / den, num_y / den);
}

// Purpose: Distance from point to line segment
// Time: O(1)
double distancePointToSegment(Point p, Point a, Point b) {
    Point ab = b - a;
    Point ap = p - a;
    
    if (ab.dist2() == 0) return sqrt(ap.dist2()); // Segment is a point
    
    long long t_num = ap.dot(ab);
    long long t_den = ab.dist2();
    
    if (t_num <= 0) return sqrt(ap.dist2()); // Closest to point a
    if (t_num >= t_den) return sqrt((p - b).dist2()); // Closest to point b
    
    // Projection lies on segment
    double t = (double)t_num / t_den;
    Point projection = Point(a.x + t * ab.x, a.y + t * ab.y);
    return sqrt((p.x - projection.x) * (p.x - projection.x) + 
                (p.y - projection.y) * (p.y - projection.y));
}

// Purpose: Check visibility between two points in a polygon
// Time: O(n) where n is number of polygon vertices
bool isVisible(const vector<Point>& polygon, int from, int to) {
    if (from == to) return true;
    
    Point start = polygon[from];
    Point end = polygon[to];
    int n = polygon.size();
    
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        
        // Skip edges that contain start or end points
        if (i == from || next == from || i == to || next == to) {
            continue;
        }
        
        if (segmentsIntersectStrict(start, end, polygon[i], polygon[next])) {
            return false;
        }
    }
    
    return true;
}

// Purpose: Check visibility from external point to polygon vertex
// Time: O(n)
bool isVisibleFromPoint(const vector<Point>& polygon, Point external, int vertexIndex) {
    Point vertex = polygon[vertexIndex];
    int n = polygon.size();
    
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        
        // Skip edges that contain the target vertex
        if (i == vertexIndex || next == vertexIndex) {
            continue;
        }
        
        if (segmentsIntersect(external, vertex, polygon[i], polygon[next])) {
            return false;
        }
    }
    
    return true;
}

// Purpose: Check if point is strictly inside polygon (not on boundary)
// Time: O(n)
bool pointStrictlyInPolygon(Point p, const vector<Point>& polygon) {
    int n = polygon.size();
    bool inside = false;
    
    for (int i = 0, j = n - 1; i < n; j = i++) {
        // First check if point is on edge
        if (pointOnSegment(polygon[i], polygon[j], p)) {
            return false; // Point is on boundary, not strictly inside
        }
        
        // Ray casting algorithm
        if (((polygon[i].y > p.y) != (polygon[j].y > p.y)) &&
            (p.x < polygon[i].x + (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y) / (polygon[j].y - polygon[i].y))) {
            inside = !inside;
        }
    }
    
    return inside;
}

// Purpose: Find all polygon vertices visible from a given external point
// Time: O(n²) - can be optimized to O(n log n) with advanced techniques
vector<int> findVisibleVertices(const vector<Point>& polygon, Point external) {
    vector<int> visible;
    int n = polygon.size();
    
    for (int i = 0; i < n; i++) {
        if (isVisibleFromPoint(polygon, external, i)) {
            visible.push_back(i);
        }
    }
    
    return visible;
}

// Purpose: Calculate signed area of polygon (positive = counterclockwise)
// Time: O(n)
long long signedPolygonArea2(const vector<Point>& polygon) {
    long long area = 0;
    int n = polygon.size();
    
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        area += polygon[i].cross(polygon[next]);
    }
    
    return area; // Multiply by 2 to avoid floating point
}

// Purpose: Check if polygon vertices are in counterclockwise order
// Time: O(n)
bool isCounterClockwise(const vector<Point>& polygon) {
    return signedPolygonArea2(polygon) > 0;
}

// Purpose: Reverse polygon orientation if needed to make it counterclockwise
// Time: O(n)
void ensureCounterClockwise(vector<Point>& polygon) {
    if (!isCounterClockwise(polygon)) {
        reverse(polygon.begin(), polygon.end());
    }
}

// Purpose: Find the leftmost-bottommost point in a set of points
// Time: O(n)
int findBottomLeftPoint(const vector<Point>& points) {
    int idx = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].y < points[idx].y || 
           (points[i].y == points[idx].y && points[i].x < points[idx].x)) {
            idx = i;
        }
    }
    return idx;
}

// Purpose: Compare points by polar angle relative to a base point
// Time: O(1)
struct PolarAngleComparator {
    Point base;
    PolarAngleComparator(Point b) : base(b) {}
    
    bool operator()(const Point& a, const Point& b) {
        Point va = a - base;
        Point vb = b - base;
        long long cross = va.cross(vb);
        
        if (cross == 0) {
            // Same angle, sort by distance
            return va.dist2() < vb.dist2();
        }
        
        return cross > 0; // Counterclockwise order
    }
};

/*
USAGE EXAMPLES:

1. Visibility Problem (like the contest problem):
   vector<int> visible = findVisibleVertices(polygon, Point(0, 0));

2. Line Segment Intersection:
   if (segmentsIntersect(a, b, c, d)) {
       Point intersection = segmentIntersectionPoint(a, b, c, d);
   }

3. Point-to-Line Distance:
   double dist = distancePointToSegment(point, lineStart, lineEnd);

4. Polygon Orientation:
   ensureCounterClockwise(polygon);

5. Visibility within Polygon:
   bool canSee = isVisible(polygon, vertex1Index, vertex2Index);
*/



*****************************************************************************************

#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    bool operator<(const Point &other) const {
        if (fabs(x - other.x) > 1e-9) return x < other.x;
        return y < other.y;
    }
};

struct Line {
    double a, b, c;
};

Line getLine(double x1, double y1, double x2, double y2) {
    Line L;
    L.a = y1 - y2;
    L.b = x2 - x1;
    L.c = x1 * y2 - x2 * y1;
    return L;
}

// تحقق من تقاطع خطين
bool intersect(Line l1, Line l2, Point &p) {
    double det = l1.a * l2.b - l2.a * l1.b;
    if (fabs(det) < 1e-12) return false; // خطوط متوازية
    p.x = (l1.b * l2.c - l2.b * l1.c) / det;
    p.y = (l1.c * l2.a - l2.c * l1.a) / det;
    return true;
}

// حساب مساحة مضلع
double polygonArea(const vector<Point> &poly) {
    double A = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        int j = (i+1)%n;
        A += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
    }
    return fabs(A) / 2.0;
}

// اتجاه بين نقطتين
Point dir(Point a, Point b) {
    return {b.x - a.x, b.y - a.y};
}

// cross product
double cross(Point a, Point b) {
    return a.x*b.y - a.y*b.x;
}

int main() {
    // مثال: 4 خطوط تشكل مربع 1x1
    vector<pair<Point, Point>> lines = {
        {{0,0},{1,0}}, // L1
        {{0,1},{1,1}}, // L2
        {{0,0},{0,1}}, // L3
        {{1,0},{1,1}}  // L4
    };
    
    int N = lines.size();
    vector<Line> lineForms;
    for(auto &p: lines)
        lineForms.push_back(getLine(p.first.x,p.first.y,p.second.x,p.second.y));

    // 1. إيجاد نقاط التقاطع
    set<Point> pointsSet;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            Point p;
            if(intersect(lineForms[i], lineForms[j], p))
                pointsSet.insert(p);
        }
    }
    vector<Point> points(pointsSet.begin(), pointsSet.end());
    
    // 2. بناء الرسم البياني (adjacency list)
    map<Point, vector<Point>> adj;
    for(auto &l: lines){
        vector<Point> onLine;
        for(auto &p: points){
            // تحقق إن النقطة على الخط
            double val = l.second.x - l.first.x !=0 ? (p.x - l.first.x)/(l.second.x - l.first.x) : (p.y - l.first.y)/(l.second.y - l.first.y);
            double valY = (p.y - l.first.y);
            if(fabs(valY - val*(l.second.y - l.first.y)) < 1e-9)
                onLine.push_back(p);
        }
        sort(onLine.begin(), onLine.end(), [&](Point a, Point b){
            if(fabs(a.x - b.x) > 1e-9) return a.x < b.x;
            return a.y < b.y;
        });
        for(int i=0;i+1<onLine.size();i++){
            adj[onLine[i]].push_back(onLine[i+1]);
            adj[onLine[i+1]].push_back(onLine[i]);
        }
    }
    
    // 3. Left-turn walk لاكتشاف المضلع
    map<pair<Point, Point>, bool> used;
    double minArea = 1e18;
    
    for(auto &[p, neighbors]: adj){
        for(auto &q: neighbors){
            if(used[{p,q}]) continue;
            vector<Point> face;
            Point start = p, next = q;
            Point u = start, v = next;
            while(true){
                face.push_back(u);
                used[{u,v}] = true;
                // اختيار أقصى يسار
                Point dv = dir(u,v);
                Point best;
                double bestCross = -1e18;
                for(auto &w: adj[v]){
                    if((fabs(w.x-u.x)<1e-9 && fabs(w.y-u.y)<1e-9)) continue;
                    Point dw = dir(v,w);
                    double c = cross(dv,dw);
                    if(c > bestCross){
                        bestCross = c;
                        best = w;
                    }
                }
                Point nxt = best;
                u = v; v = nxt;
                if(fabs(u.x-start.x)<1e-9 && fabs(u.y-start.y)<1e-9 && fabs(v.x-next.x)<1e-9 && fabs(v.y-next.y)<1e-9)
                    break;
            }
            double area = polygonArea(face);
            if(area>1e-9)
                minArea = min(minArea, area);
        }
    }
    
    if(minArea > 1e17) cout << -1 << endl;
    else printf("%.6f\n", minArea);

    return 0;
}

**********************************************************************************************************


// حساب مركز الدائرة الداخلية
Point incenter(Point a, Point b, Point c) {
    double ab = distance(a, b); // الضلع المقابل لـ c
    double bc = distance(b, c); // الضلع المقابل لـ a
    double ca = distance(c, a); // الضلع المقابل لـ b
    
    double perimeter = ab + bc + ca;
    
    // حساب الإحداثيات باستخدام الأوزان (أطوال الأضلاع)
    double x = (bc * a.x + ca * b.x + ab * c.x) / perimeter;
    double y = (bc * a.y + ca * b.y + ab * c.y) / perimeter;
    
    return Point(x, y);
}


***********************************************************************************************************
// USEFUL GEOMETRIC FACTS:

/*
1. Euler Line: In any triangle, the circumcenter, centroid, and orthocenter are collinear
2. Nine-point circle: Passes through 9 special points including midpoints of sides
3. Napoleon's Theorem: Constructing equilateral triangles on sides of any triangle
4. Pick's Theorem: Area = Interior_Points + Boundary_Points/2 - 1
5. Shoelace Formula: Area = |Σ(xi*yi+1 - xi+1*yi)| / 2
6. For convex polygons: sum of interior angles = (n-2) * 180°
7. Circle through 3 points has center at intersection of perpendicular bisectors
8. Incenter is intersection of angle bisectors
9. Pappus-Guldinus: Volume = Area × distance traveled by centroid
10. Law of Cosines: c² = a² + b² - 2ab*cos(C)
11. Law of Sines: a/sin(A) = b/sin(B) = c/sin(C) = 2R
12. Heron's formula: Area = √[s(s-a)(s-b)(s-c)] where s = (a+b+c)/2
*/
