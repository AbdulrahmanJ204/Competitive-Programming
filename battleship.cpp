#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a *b / gcd(a, b)
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES"
#define cno cout << "NO"
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define cin1(v, n)             \
    for (ll i = 0; i < n; i++) \
        cin >> v[i];
#define cin2(v, n, m)               \
    for (ll i = 0; i < n; i++)      \
        for (int j = 0; j < m; j++) \
            cin >> v[i][j];
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define cout1(v, n)            \
    for (ll i = 0; i < n; i++) \
        cout << v[i] << ' ';   \
    cendl;
#define cout2(v, n, m)                \
    for (ll i = 0; i < n; i++, cendl) \
        for (int j = 0; j < m; j++)   \
            cout << v[i][j] << ' ';
#define assign1(v, n, value)   \
    for (ll i = 0; i < n; i++) \
        v[i] = value;
#define assign2(v, n, m, value)     \
    for (ll i = 0; i < n; i++)      \
        for (int j = 0; j < m; j++) \
            v[i][j] = value;
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define oo LLONG_MAX
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

const int mxN = 20;
int typeOfShip[mxN][mxN];
int shape[mxN][mxN];
int direction[mxN][mxN];
int rows[mxN], cols[mxN];
int newGrid[mxN][mxN];
int newShape[mxN][mxN];
int newDirection[mxN][mxN];
const int mxM = 20;
int ships[mxM];
int taken[mxM];
int n, m;
/*
type(1 , sea).
type(2 , ship).
type(3 , empty).

shape(0 , unknown).
shape(1 , curve).
shape(2 , square).
shape(3 , circle).
shape(4 , sea).

direction(0 , dontCare).
direction(1 , up).
direction(2 , down).
direction(3 , left).
direction(4 , right).

*/
enum Type {
    SEA = 1,
    SHIP = 2,
    EMPTY = 3
};
enum Shape {
    UNKNOWN,
    CURVE,
    SQUARE,
    CIRCLE
};
enum Direction {
    DONTCARE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};
int countTypeInRow(int row, Type type) {
    int cnt = 0;
    for (int col = 0; col < n; col++) {
        if (typeOfShip[row][col] == type)
            cnt++;
    }
    return cnt;
}
int countTypeInCol(int col, Type type) {
    int cnt = 0;
    for (int row = 0; row < n; row++) {
        if (typeOfShip[row][col] == type)
            cnt++;
    }
    return cnt;
}
bool fillWaterForCompletedRows() {
    bool res = false;
    for (int row = 0; row < n; row++) {
        int cnt = countTypeInRow(row, Type::SHIP);
        if (rows[row] == cnt)
            for (int col = 0; col < n; col++)
                if (typeOfShip[row][col] == Type::EMPTY)
                    typeOfShip[row][col] = Type::SEA, res = true;
    }
    return res;
}
bool fillWaterForCompletedColumns() {
    bool res = false;
    for (int col = 0; col < n; col++) {
        int cnt = countTypeInCol(col, Type::SHIP);

        if (cols[col] == cnt)
            for (int row = 0; row < n; row++)
                if (typeOfShip[row][col] == Type::EMPTY)
                    typeOfShip[row][col] = Type::SEA, res = true;
    }
    return res;
}
bool fillWaterForCompletedLines() {
    bool rs = fillWaterForCompletedRows();
    rs |= fillWaterForCompletedColumns();
    return rs;
}
bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}
bool fillShipsForCompletedRows() {
    bool res = false;
    for (int row = 0; row < n; row++) {
        int cnt = countTypeInRow(row, Type::EMPTY);
        cnt += countTypeInRow(row, Type::SHIP);
        if (rows[row] == cnt)
            for (int col = 0; col < n; col++)
                if (typeOfShip[row][col] == Type::EMPTY)
                    typeOfShip[row][col] = Type::SHIP, shape[row][col] = Shape::UNKNOWN, res = true;
    }
    return res;
}
bool fillShipsForCompletedColumns() {
    bool res = false;
    for (int col = 0; col < n; col++) {
        int cnt = countTypeInCol(col, Type::EMPTY);
        cnt += countTypeInCol(col, Type::SHIP);
        if (cols[col] == cnt)
            for (int row = 0; row < n; row++)
                if (typeOfShip[row][col] == Type::EMPTY)
                    typeOfShip[row][col] = Type::SHIP, shape[row][col] = Shape::UNKNOWN, res = true;
    }
    return res;
}
bool fillShipsForCompletedLines() {
    bool rs = fillShipsForCompletedRows() ||
              fillShipsForCompletedColumns();
    return rs;
}
bool fillAroundShips() {
    bool res = false;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (typeOfShip[row][col] == Type::SHIP) {
                for (int i = -1; i <= 1; i++)
                    for (int j = -1; j <= 1; j++) {
                        if (!j && !i)
                            continue;
                        int newR = row + i, newC = col + j;
                        if (!isValid(newR, newC))
                            continue;
                        if (shape[row][col] == Shape::CURVE) {
                            // assuming 0 , 0 is top left corner , and n,n is bottom right corner
                            // increasing i moves to down , increasing j moves to right
                            if (direction[row][col] == Direction::UP && (i == 1 && !j))
                                continue;

                            if (direction[row][col] == Direction::DOWN && (i == -1 && !j))
                                continue;

                            if (direction[row][col] == Direction::LEFT && (!i && j == 1))
                                continue;

                            if (direction[row][col] == Direction::RIGHT && (!i && j == -1))
                                continue;
                            if (typeOfShip[newR][newC] == Type::EMPTY)
                                typeOfShip[newR][newC] = Type::SEA, res = true;
                        }

                        if ((shape[row][col] == Shape::SQUARE || shape[row][col] == Shape::UNKNOWN) && (i == j || i + j == 0)) {

                            if (typeOfShip[newR][newC] == Type::EMPTY)
                                typeOfShip[newR][newC] = Type::SEA, res = true;
                        }

                        if (shape[row][col] == Shape::CIRCLE) {

                            if (typeOfShip[newR][newC] == Type::EMPTY)
                                typeOfShip[newR][newC] = Type::SEA, res = true;
                        }
                    }
            }
        }
    }
    return res;
}
bool placeUnkownShipsForGivenShips() {
    bool res = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (typeOfShip[i][j] == Type::SHIP) {
                if (shape[i][j] == Shape::CURVE) {
                    if (direction[i][j] == Direction::UP) {
                        if (typeOfShip[i + 1][j] == Type::EMPTY)
                            typeOfShip[i + 1][j] = Type::SHIP, shape[i + 1][j] = Shape::UNKNOWN, res = true;
                    }
                    if (direction[i][j] == Direction::DOWN) {
                        if (typeOfShip[i - 1][j] == Type::EMPTY)
                            typeOfShip[i - 1][j] = Type::SHIP, shape[i - 1][j] = Shape::UNKNOWN, res = true;
                    }
                    if (direction[i][j] == Direction::LEFT) {
                        if (typeOfShip[i][j + 1] == Type::EMPTY)
                            typeOfShip[i][j + 1] = Type::SHIP, shape[i][j + 1] = Shape::UNKNOWN, res = true;
                    }
                    if (direction[i][j] == Direction::RIGHT) {
                        if (typeOfShip[i][j - 1] == Type::EMPTY)
                            typeOfShip[i][j - 1] = Type::SHIP, shape[i][j - 1] = Shape::UNKNOWN, res = true;
                    }
                }
                if (shape[i][j] == Shape::SQUARE) {
                    if (!isValid(i, j + 1) || !isValid(i, j - 1)) {
                        if (typeOfShip[i - 1][j] == Type::EMPTY)
                            typeOfShip[i - 1][j] = Type::SHIP, shape[i - 1][j] = Shape::UNKNOWN, res = true;
                        if (typeOfShip[i + 1][j] == Type::EMPTY)
                            typeOfShip[i + 1][j] = Type::SHIP, shape[i + 1][j] = Shape::UNKNOWN, res = true;

                        continue;
                    }
                    if (!isValid(i + 1, j) || !isValid(i - 1, j)) {

                        if (typeOfShip[i][j + 1] == Type::EMPTY)
                            typeOfShip[i][j + 1] = Type::SHIP, shape[i][j + 1] = Shape::UNKNOWN, res = true;
                        if (typeOfShip[i][j - 1] == Type::EMPTY)
                            typeOfShip[i][j - 1] = Type::SHIP, shape[i][j - 1] = Shape::UNKNOWN, res = true;
                        continue;
                    }
                    if (typeOfShip[i + 1][j] == Type::SHIP || typeOfShip[i - 1][j] == Type::SHIP) {
                        if (typeOfShip[i - 1][j] == Type::EMPTY)
                            typeOfShip[i - 1][j] = Type::SHIP, shape[i - 1][j] = Shape::UNKNOWN, res = true;
                        if (typeOfShip[i + 1][j] == Type::EMPTY)
                            typeOfShip[i + 1][j] = Type::SHIP, shape[i + 1][j] = Shape::UNKNOWN, res = true;
                    }
                    if (typeOfShip[i][j + 1] == Type::SHIP || typeOfShip[i][j - 1] == Type::SHIP) {

                        if (typeOfShip[i][j + 1] == Type::EMPTY)
                            typeOfShip[i][j + 1] = Type::SHIP, shape[i][j + 1] = Shape::UNKNOWN, res = true;
                        if (typeOfShip[i][j - 1] == Type::EMPTY)
                            typeOfShip[i][j - 1] = Type::SHIP, shape[i][j - 1] = Shape::UNKNOWN, res = true;
                    }
                    if (typeOfShip[i + 1][j] == Type::SEA || typeOfShip[i - 1][j] == Type::SEA) {

                        if (typeOfShip[i][j + 1] == Type::EMPTY)
                            typeOfShip[i][j + 1] = Type::SHIP, shape[i][j + 1] = Shape::UNKNOWN, res = true;
                        if (typeOfShip[i][j - 1] == Type::EMPTY)
                            typeOfShip[i][j - 1] = Type::SHIP, shape[i][j - 1] = Shape::UNKNOWN, res = true;
                    }
                    if (typeOfShip[i][j + 1] == Type::SEA || typeOfShip[i][j - 1] == Type::SEA) {
                        if (typeOfShip[i - 1][j] == Type::EMPTY)
                            typeOfShip[i - 1][j] = Type::SHIP, shape[i - 1][j] = Shape::UNKNOWN, res = true;
                        if (typeOfShip[i + 1][j] == Type::EMPTY)
                            typeOfShip[i + 1][j] = Type::SHIP, shape[i + 1][j] = Shape::UNKNOWN, res = true;
                    }
                }
            }
        }
    }
    return res;
}
int countSeaAroundCell(int row, int col) {
    int cnt = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (!i && !j)
                continue;
            int newR = row + i, newC = col + j;
            if (!isValid(newR, newC)) {
                cnt++;
                continue;
            }
            if (typeOfShip[newR][newC] == Type::SEA)
                cnt++;
        }
    }
    return cnt;
}
int countShipsAroundCell(int row, int col) {
    int cnt = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (!i && !j)
                continue;
            int newR = row + i, newC = col + j;
            if (!isValid(newR, newC)) {
                continue;
            }
            if (typeOfShip[newR][newC] == Type::SHIP)
                cnt++;
        }
    }
    return cnt;
}
int getCurveDirection(int row, int col) {
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (!i && !j)
                continue;
            int newR = row + i, newC = col + j;
            if (!isValid(newR, newC)) {
                continue;
            }
            if (typeOfShip[newR][newC] == Type::SHIP) {
                if (i == 1)
                    return Direction::UP;
                if (i == -1)
                    return Direction::DOWN;
                if (j == -1)
                    return Direction::RIGHT;
                if (j == 1)
                    return Direction::LEFT;
            }
        }
    }
    return 0;
}
bool convertUnknown() {
    bool res = false;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (typeOfShip[row][col] == Type::SHIP && shape[row][col] == Shape::UNKNOWN) {
                int sea = countSeaAroundCell(row, col);
                int ships = countShipsAroundCell(row, col);
                if (sea == 8)
                    shape[row][col] = Shape::CIRCLE, direction[row][col] = Direction::DONTCARE, res = true;
                if (sea == 6 && ships == 2) {
                    shape[row][col] = Shape::SQUARE, direction[row][col] = Direction::DONTCARE, res = true;
                }
                if (sea == 7 && ships == 1) {
                    shape[row][col] = Shape::CURVE, direction[row][col] = getCurveDirection(row, col), res = true;
                }
            }
        }
    }
    return res;
}
vector<int> markTakenShips() {
    vector<int> t;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (typeOfShip[i][j] == Type::SHIP) {
                if (shape[i][j] == Shape::CIRCLE) {
                    t.push_back(1);
                    cnt = 0;
                } else if (shape[i][j] != Shape::UNKNOWN)
                    cnt++;
                else
                    cnt = 0;
            } else {
                if (cnt > 1)
                    t.push_back(cnt);
                cnt = 0;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (typeOfShip[i][j] == Type::SHIP) {
                if (shape[i][j] != Shape::UNKNOWN && shape[i][j] != Shape::CIRCLE)
                    cnt++;
                else
                    cnt = 0;
            } else {
                if (cnt > 1)
                    t.push_back(cnt);
                cnt = 0;
            }
        }
    }
    return t;
}
bool correctSolution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (typeOfShip[i][j] == Type::SHIP && newGrid[i][j] != Type::SHIP)
                return false;
        }
    }

    return true;
}
int countSeaAroundCellNEW(int row, int col) {
    int cnt = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (!i && !j)
                continue;
            int newR = row + i, newC = col + j;
            if (!isValid(newR, newC)) {
                cnt++;
                continue;
            }
            if (newGrid[newR][newC] == Type::SEA)
                cnt++;
        }
    }
    return cnt;
}
int countShipsAroundCellNEW(int row, int col) {
    int cnt = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (!i && !j)
                continue;
            int newR = row + i, newC = col + j;
            if (!isValid(newR, newC)) {
                continue;
            }
            if (newGrid[newR][newC] == Type::SHIP)
                cnt++;
        }
    }
    return cnt;
}
int countTypeInRowNEW(int row, Type type) {
    int cnt = 0;
    for (int col = 0; col < n; col++) {
        if (newGrid[row][col] == type)
            cnt++;
    }
    return cnt;
}
int countTypeInColNEW(int col, Type type) {
    int cnt = 0;
    for (int row = 0; row < n; row++) {
        if (newGrid[row][col] == type)
            cnt++;
    }
    return cnt;
}

bool canPlaceShipH(int idx, int row, int col) {
    if (ships[idx] + col - 1 >= n)
        return false;
    if (countTypeInRowNEW(row, Type::SHIP) + ships[idx] > rows[row])
        return false;
    for (int i = col; i < col + ships[idx]; i++) {
        if (countTypeInColNEW(i, Type::SHIP) + 1 > cols[i])
            return false;
        if (newGrid[row][i] != Type::EMPTY)
            return false;
        if (countShipsAroundCellNEW(row, i))
            return false;
    }
    return true;
};
bool canPlaceShipV(int idx, int row, int col) {
    if (ships[idx] + row - 1 >= n)
        return false;
    if (countTypeInColNEW(col, Type::SHIP) + ships[idx] > cols[col])
        return false;
    for (int i = row; i < row + ships[idx]; i++) {
        if (countTypeInRowNEW(i, Type::SHIP) + 1 > rows[i])
            return false;
        if (newGrid[i][col] != Type::EMPTY)
            return false;
        if (countShipsAroundCellNEW(i, col))
            return false;
    }
    return true;
};
void placeShipH(int idx, int row, int col) {
    if (ships[idx] == 1) {

        newGrid[row][col] = Type::SHIP;
        newShape[row][col] = Shape::CIRCLE;
        newDirection[row][col] = Direction::DONTCARE;
        return;
    }
    for (int i = col; i < col + ships[idx]; i++) {
        newGrid[row][i] = Type::SHIP;
        newShape[row][i] = Shape::SQUARE;
        newDirection[row][i] = Direction::DONTCARE;
    }
    newShape[row][col] = newShape[row][col + ships[idx] - 1] = Shape::CURVE;
    newDirection[row][col] = Direction::LEFT;
    newDirection[row][col + ships[idx] - 1] = Direction::RIGHT;
};
void placeShipV(int idx, int row, int col) {
    if (ships[idx] == 1) {

        newGrid[row][col] = Type::SHIP;
        newShape[row][col] = Shape::CIRCLE;
        newDirection[row][col] = Direction::DONTCARE;
        return;
    }
    for (int i = row; i < row + ships[idx]; i++) {
        newGrid[i][col] = Type::SHIP;
        newShape[i][col] = Shape::SQUARE;
        newDirection[i][col] = Direction::DONTCARE;
    }
    newShape[row][col] = newShape[row + ships[idx] - 1][col] = Shape::CURVE;
    newDirection[row][col] = Direction::UP;
    newDirection[row + ships[idx] - 1][col] = Direction::DOWN;
};
void removeShipH(int idx, int row, int col) {

    for (int i = col; i < col + ships[idx]; i++) {
        newGrid[row][i] = Type::EMPTY;
        newShape[row][i] = Shape::UNKNOWN;
        newDirection[row][i] = Direction::DONTCARE;
    }
};
void removeShipV(int idx, int row, int col) {
    for (int i = row; i < row + ships[idx]; i++) {
        newGrid[i][col] = Type::EMPTY;
        newShape[i][col] = Shape::UNKNOWN;
        newDirection[i][col] = Direction::DONTCARE;
    }
};
bool bt(int idx) {
    if (idx == m) {
        return correctSolution();
    }
    if (taken[idx])
        return bt(idx + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (canPlaceShipH(idx, i, j)) {
                placeShipH(idx, i, j);
                bool x = bt(idx + 1);
                if (x)
                    return true;
                removeShipH(idx, i, j);
            }
            if (canPlaceShipV(idx, i, j)) {
                placeShipV(idx, i, j);
                bool x = bt(idx + 1);
                if (x)
                    return true;
                removeShipV(idx, i, j);
            }
        }
    }
    return false;
}
void removeUncompletedShips(){
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n;) {
        if (newGrid[i][j] == Type::SHIP) {
            int start = j;
            while (j < n && newGrid[i][j] == Type::SHIP) j++;
            bool complete = true;
            
            for (int k = start; k < j; k++) {
                if (countSeaAroundCellNEW(i, k) + countShipsAroundCellNEW(i, k) != 8) {
                    complete = false;
                    break;
                }
            }
            if (!complete) {
                for (int k = start; k < j; k++) {
                    newGrid[i][k] = Type::EMPTY;
                    newShape[i][k] = Shape::UNKNOWN;
                    newDirection[i][k] = Direction::DONTCARE;
                }
            }
        } else {
            j++;
        }
    }
}















for (int j = 0; j < n; j++) {
    for (int i = 0; i < n;) {
        if (newGrid[i][j] == Type::SHIP) {
            int start = i;
            while (i < n && newGrid[i][j] == Type::SHIP) i++;
            bool complete = true;
            for (int k = start; k < i; k++) {
                if (countSeaAroundCellNEW(k, j) + countShipsAroundCellNEW(k, j) != 8) {
                    complete = false;
                    break;
                }
            }
            if (!complete) {
                for (int k = start; k < i; k++) {
                    newGrid[k][j] = Type::EMPTY;
                    newShape[k][j] = Shape::UNKNOWN;
                    newDirection[k][j] = Direction::DONTCARE;
                }
            }
        } else {
            i++;
        }
    }
}

}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> typeOfShip[i][j] >> shape[i][j] >> direction[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> rows[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cols[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> ships[i];
    }

    bool res = true;
    while (res) {
        res = false;
        res |= fillWaterForCompletedLines();
        res |= fillShipsForCompletedLines();
        res |= fillAroundShips();
        res |= placeUnkownShipsForGivenShips();
        res |= convertUnknown();
        cendl;
        cout2(typeOfShip, n, n);
    }
    assign1(taken, m, false);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newGrid[i][j] = typeOfShip[i][j];
            newDirection[i][j] = direction[i][j];
            newShape[i][j] = shape[i][j];
        }
    }
    
    removeUncompletedShips();
    auto v = markTakenShips();
    sort(all(v));
    sort(ships , ships + m);
    reverse(ships , ships +m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < v.size(); j++) {
            if (ships[i] == v[j]) {
                taken[i] = true;
                v[j] = 0;
                break;
            }
        }
    }
    if (v.size() != m) {
        bt(0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                typeOfShip[i][j] = newGrid[i][j];
                direction[i][j] = newDirection[i][j];
                shape[i][j] = newShape[i][j];
                if (typeOfShip[i][j] == Type::EMPTY)
                    typeOfShip[i][j] = Type::SEA, direction[i][j] = Direction::DONTCARE, shape[i][j] = Shape::UNKNOWN;
            }
        }
    }
    cendl;
    cout2(typeOfShip, n, n);
    cendl;
    cout2(shape, n, n);
    cendl;
    cout2(direction, n, n);
    cendl;
    return;
}

int32_t main() {
    // InTheNameOfAllah
    // freopen("./input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}

/*
lvl 1
6 6
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 1 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 2 3 0 3 0 0 2 2 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
2 1 2 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
2 2 2 2 1 1
2 2 0 3 0 3
3 2 2 1 1 1
*/
/*
lvl 2
6 6
2 1 3 3 0 0 3 0 0 1 0 0 3 0 0 1 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 2 3 0 3 0 0 2 1 2 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 1 0 0 3 0 0 3 0 0 3 0 0 3 0 0
4 0 2 3 0 1
1 2 1 3 1 2
3 2 2 1 1 1
*/
/*
lvl 40
8 10
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 1 0 0 2 1 2 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 2 1 2 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 2 3 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 1 0 0
2 3 1 4 1 4 0 5
3 2 5 1 1 3 0 5
4 3 3 2 2 2 1 1 1 1
*/
/*
lvl 40
10 10
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 1 0 0
2 1 3 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 2 1 1 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 2 2 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 1 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 1 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 1 0 0 3 0 0 3 0 0 3 0 0 3 0 0
1 4 2 3 2 2 3 2 0 1
4 1 1 3 2 1 2 1 4 1
4 3 3 2 2 2 1 1 1 1
*/
/*

10 10
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 1 0 0
2 1 3 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 2 1 1 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 2 2 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 1 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 1 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 1 0 0 3 0 0 3 0 0 3 0 0 3 0 0
1 4 2 3 2 2 3 2 0 1
4 1 1 3 2 1 2 1 4 1
4 3 3 2 2 2 1 1 1 1
*/

/*

10 10
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 2 3 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 2 1 2 3 0 0 3 0 0 3 0 0 2 1 2 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
1 1 2 2 2 2 2 4 1 3
1 2 1 2 1 5 1 1 4 2
4 3 3 2 2 2 1 1 1 1
*/
/*

10 10
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 2 3 0
2 1 1 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
3 0 0 3 0 0 3 0 0 2 1 3 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0 3 0 0
1 4 1 2 2 1 2 4 1 2
3 2 2 2 2 1 1 3 3 1
4 3 3 2 2 2 1 1 1 1
*/