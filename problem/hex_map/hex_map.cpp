#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int inf = numeric_limits<int>::max();
int value[1000][1000];
int cost[1000][1000];
int r, c;

int dx_odd[] = {0, 0, -1, -1, 1, 1};
int dy_odd[] = {-1, 1, -1, 0, -1, 0};

int dx_even[] = {0, 0, -1, -1, 1, 1};
int dy_even[] = {-1, 1, 0, 1, 0, 1};

class location {
public:
    int x;
    int y;
    int cost;

    location(int a, int b, int c) : x(a), y(b), cost(c) {}

    bool operator<(const location &other) const {
        return cost > other.cost;
    }

    bool operator==(const location &other) const {
        return (x == other.x) && (y == other.y);
    }
};

int shortest_path_hex_map(location start, location stop) {
    priority_queue<location> pq;
    pq.push(start);
    cost[start.y][start.x] = start.cost;

    while (!pq.empty()) {
        location present = pq.top();
        pq.pop();

        // Went here at lower cost
        if (cost[present.y][present.x] < present.cost) {
            continue;
        }
        // Reach stop point
        if (present == stop) {
            break;
        }

        if (present.x % 2 != 0) {
            for (int i = 0; i < 6; i++) {
                int x = present.x + dx_even[i];
                int y = present.y + dy_even[i];
                if (x < 0 || y < 0 || x >= c || y >= r) {
                    continue;
                }
                if (cost[y][x] > present.cost + value[y][x]) {
                    cost[y][x] = present.cost + value[y][x];
                    pq.push(location(x, y, cost[y][x]));
                }
            }
        } else {
            for (int i = 0; i < 6; i++) {
                int x = present.x + dx_odd[i];
                int y = present.y + dy_odd[i];
                if (x < 0 || y < 0 || x >= c || y >= r) {
                    continue;
                }
                if (cost[y][x] > present.cost + value[y][x]) {
                    cost[y][x] = present.cost + value[y][x];
                    pq.push(location(x, y, cost[y][x]));
                }
            }
        }
    }
    return cost[stop.y][stop.x];
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a1, b1, a2, b2;
    cin >> r >> c;
    cin >> a1 >> b1 >> a2 >> b2;
    a1--; b1--; a2--; b2--;  // Convert to 0-based indexing

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> value[i][j];
            cost[i][j] = inf;
        }
    }

    location start(a1, b1, value[b1][a1]);
    location stop(a2, b2, inf);

    cout << shortest_path_hex_map(start, stop) << endl;
    return 0;
}