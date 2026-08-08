// Purpose: Mo's Algorithm for offline range queries
// Time: O((n + q) * sqrt(n))
struct Query {
    int l, r, idx;
};

bool moComparator(Query a, Query b) {
    int block_size = sqrt(MAXN);
    if (a.l / block_size != b.l / block_size) {
        return a.l / block_size < b.l / block_size;
    }
    return (a.l / block_size & 1) ? (a.r < b.r) : (a.r > b.r);
}

void moAlgorithm(vector<int> &arr, vector<Query> &queries) {
    sort(queries.begin(), queries.end(), moComparator);

    int currentL = 0, currentR = -1;
    // Current answer state

    for (Query q : queries) {
        while (currentR < q.r) {
            currentR++;
            // Add arr[currentR] to current answer
        }
        while (currentR > q.r) {
            // Remove arr[currentR] from current answer
            currentR--;
        }
        while (currentL < q.l) {
            // Remove arr[currentL] from current answer
            currentL++;
        }
        while (currentL > q.l) {
            currentL--;
            // Add arr[currentL] to current answer
        }

        // Store answer for queries[q.idx]
    }
}

struct MoPairs {
    int n, block_size;
    long long K;
    vector<int> arr;
    vector<Query> queries;
    unordered_map<int, long long> freq; // added to calculate the answers ,dependes on the problem
    long long currentAnswer = 0;
    int currL = 0, currR = -1;

    MoPairs(const vector<int> &a, const vector<Query> &qs, long long target)
        : n((int)a.size()), arr(a), queries(qs), K(target) {
        block_size = max(1, (int)sqrt(n));
    }

    static bool cmp(const Query &a, const Query &b, int block_size) {
        int ab = a.l / block_size, bb = b.l / block_size;
        if (ab != bb)
            return ab < bb;
        return (ab & 1) ? (a.r < b.r) : (a.r > b.r);
    }

    void add(int pos) {
        // here modify the answer depending on problem
        int x = arr[pos];
        currentAnswer += freq[K - x];
        freq[x]++;
    }
    void remove_(int pos) {
        // here modify the answer depending on problem
        int x = arr[pos];
        freq[x]--;
        currentAnswer -= freq[K - x];
    }

    vector<long long> run() {
        sort(queries.begin(), queries.end(),
             [&](const Query &a, const Query &b) {
                 return cmp(a, b, block_size);
             });
        vector<long long> answers(queries.size());
        for (auto &q : queries) {
            while (currL > q.l) {
                --currL;
                add(currL);
            }
            while (currR < q.r) {
                ++currR;
                add(currR);
            }
            while (currL < q.l) {
                remove_(currL);
                ++currL;
            }
            while (currR > q.r) {
                remove_(currR);
                --currR;
            }
            answers[q.idx] = currentAnswer;
        }
        return answers;
    }
};

/*
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<Query> qs(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        --l; --r;
        qs[i] = {l, r, i};
    }

    MoPairs solver(a, qs, K);
    vector<long long> ans = solver.run();

    for (auto x : ans) cout << x << "\n";
 */

