#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
struct point {
    int X, Y;
} p1;
typedef struct {
    double a; /* x-coefficient */
    double b; /* y-coefficient */
    double c; /* constant term */
} line;
void points_to_line(point p1, point p2, line *l) {
    if (p1.X == p2.X) {
        l->a = 1;
        l->b = 0;
        l->c = -p1.X;
    } else {
        l->b = 1;
        l->a = -(p1.Y - p2.Y) / (p1.X - p2.X);
        l->c = -(l->a * p1.X) - (l->b * p1.Y);
    }


}
int main() {
    p1.X = 1;
    cout<<EPSILON;
    return 0;
}