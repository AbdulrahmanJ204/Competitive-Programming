// Purpose: Ternary Search - find maximum/minimum of unimodal function
// Time: O(log₃(range/precision))
double ternary_search(double l, double r, function<double(double)> f) {
    for (int i = 0; i < 100; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) { // Change for min/max
            l = m1;
        } else {
            r = m2;
        }
    }
    return f(l);
}

