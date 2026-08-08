// ============================================================================
//                              UTILITIES
// ============================================================================

// Purpose: Next Greater Element for each position
// Time: O(n)
vector<int> nextGreater(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(arr[i]);
    }
    return result;
}

// Purpose: Previous Greater Element for each position
// Time: O(n)
vector<int> prevGreater(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(arr[i]);
    }
    return result;
}

// Purpose: Generate all subsets recursively
// Time: O(2ⁿ)
void generateSubsets(vector<int> &arr, int index, vector<int> &current, vector<vector<int>> &result) {
    if (index == arr.size()) {
        result.push_back(current);
        return;
    }
    // Include current element
    current.push_back(arr[index]);
    generateSubsets(arr, index + 1, current, result);
    current.pop_back();

    // Exclude current element
    generateSubsets(arr, index + 1, current, result);
}

// Purpose: Generate subsets using bitmask
// Time: O(n * 2ⁿ)
void generateSubsetsBitmask(vector<int> &arr) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }
        // Process subset
    }
}

// Purpose: Generate combinations of size m from n elements
// Time: O(C(n,m))
vector<int> combination;
int cnt_combinations = 0;

void getCombinations(int n, int m, int i = 0, int last_val = 0) {
    if (i == m) {
        cnt_combinations++;
        // Process combination
        return;
    }
    for (int j = last_val + 1; j <= n; j++) {
        combination.push_back(j);
        getCombinations(n, m, i + 1, j);
        combination.pop_back();
    }
}

// Purpose: Inclusion-Exclusion Principle implementation
// Time: O(2ᵏ)
void inclusionExclusion(int k) {
    ll ans = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        ll cur = 0, cnt = 0;
        for (int bit = 0; bit < k; bit++) {
            if (!(mask & (1 << bit)))
                continue;
            cnt++;
            // Process bit
        }
        // Calculate cur based on the bits set
        ll sign = cnt % 2 ? 1 : -1;
        ans += sign * cur;
    }
}
