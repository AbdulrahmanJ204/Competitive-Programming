// Purpose: Matrix Exponentiation - compute A^n efficiently
// Time: O(k³ log n) where k is matrix dimension
vector<vector<ll>> multiplyMatrices(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> matrixExponentiation(vector<vector<ll>> &A, ll n) {
    int size = A.size();
    vector<vector<ll>> result(size, vector<ll>(size, 0));
    for (int i = 0; i < size; i++)
        result[i][i] = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            result = multiplyMatrices(result, A);
        }
        A = multiplyMatrices(A, A);
        n /= 2;
    }
    return result;
}

// Purpose: Fibonacci with Matrix Exponentiation
// Time: O(log n)
ll fibonacciModulo(ll n) {
    if (n == 0)
        return 0;
    vector<vector<ll>> A = {{1, 1}, {1, 0}};
    vector<vector<ll>> result = matrixExponentiation(A, n - 1);
    return result[0][0];
}

