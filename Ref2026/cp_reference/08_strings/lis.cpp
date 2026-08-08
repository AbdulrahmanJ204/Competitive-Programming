// Purpose: Longest Increasing Subsequence - find length of LIS
// Time: O(n log n)
int LIS(vector<int> &nums) {
    vector<int> lis;
    for (int x : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            *it = x;
        }
    }
    return lis.size();
}

