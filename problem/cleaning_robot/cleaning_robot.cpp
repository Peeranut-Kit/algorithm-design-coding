#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class state {
public:
    int score;
    int row, col;
    vector<vector<int>> floor;

    state(int s, int r, int c, vector<vector<int>> f) : score(s), row(r), col(c), floor(f) {} // floor[r][c] ระบุความสกปรกของช่องนั้น ถ้า -1 แปลว่าเดินไปไม่ได้

    bool operator<(const state &other) const {
        return score > other.score; // for comparing in priority queue (min-heap)
    }
};

bool clean(state &x) {
    if (x.floor[x.row][x.col] > 0) {
        x.score -= x.floor[x.row][x.col];  // Reduce score by the amount of dirtiness cleaned
        x.floor[x.row][x.col] = 0;         // Clean the current cell
    }
}

vector<state> children_of(state x) {
    vector<state> children;
    int rows = x.floor.size();
    int cols = x.floor[0].size();
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right

    for (auto way : directions) {
        int newRow = x.row + way.first;
        int newCol = x.col + way.second;
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && x.floor[newRow][newCol] != -1) {
            children.push_back(state(x.score, newRow, newCol, x.floor));
        }
    }

    return children;
}

int heuristic(state x) {
    int totalDirtiness = 0;
    for (const auto &row : x.floor) {
        for (int dirt : row) {
            if (dirt > 0) totalDirtiness += dirt;
        }
    }
    return totalDirtiness;
}

state cleaning_robot(state start) {
    int best = INT_MAX;
    priority_queue<state> pq;
    pq.push(start);

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        if (clean(current)) {
            if (current.score < best)
            {
                best = current.score;
                //best_s = s;
            }
        }
        else {
            vector<state> children = children_of(current);
            for (auto &child : children) {
                if (heuristic(child) < best) pq.push(child);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    vector<vector<int>> floor = {
        {5, 2, -1, 4},
        {2, -1, 3, 2},
        {2, 2, 2, 2},
        {-1, 2, 3, 5}
    };
    state start(0, 0, 0, floor);
    state result = cleaning_robot(start);

    cout << "Total Score: " << result.score << endl;
    return 0;
}