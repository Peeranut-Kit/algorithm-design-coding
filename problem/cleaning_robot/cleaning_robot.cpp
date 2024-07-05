#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right

class state
{
public:
    int score;
    int row, col;
    vector< vector<int> > floor;

    int heuristic_value;

    state(int s, int r, int c, vector< vector<int> > f) : score(s), row(r), col(c), floor(f) {} // floor[r][c] ระบุความสกปรกของช่องนั้น ถ้า -1 แปลว่าเดินไปไม่ได้

    // For std::set check for position in row, col and floor matrix
    bool operator<(const state &other) const {
        return !(this->row == other.row && this->col == other.col && this->floor == other.floor);
    }
};

class heuristic_comparer {
public:
    bool operator()(const state &s1, const state &s2) const {
        return s1.heuristic_value > s2.heuristic_value;
    }
};

// Build bool matrix of floor[][] size where true is reachable cell and false is blocked cell
vector< vector<bool> > get_reachable_matrix(state &x)
{
    int rows = x.floor.size();
    int cols = x.floor[0].size();
    vector< vector<bool> > visited(rows, vector<bool>(cols, false));
    visited[x.row][x.col] = true;
    queue< pair<int, int> > q;
    q.push(make_pair(x.row, x.col));

    while (!q.empty())
    {
        pair<int,int> pair = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newRow = pair.first + directions[i][0];
            int newCol = pair.second + directions[i][1];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if (x.floor[newRow][newCol] != -1 && !visited[newRow][newCol]) {
                    q.push(make_pair(newRow, newCol));
                    visited[newRow][newCol] = true;
                }
            }
        }
    }

    return visited;
}

int heuristic(state &x) {
    vector< vector<bool> > reachable_matrix = get_reachable_matrix(x);
    int rows = reachable_matrix.size();
    int cols = reachable_matrix[0].size();
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (reachable_matrix[i][j] && x.floor[i][j] > 0) {
                int row_diff = abs(i - x.row);
                int col_diff = abs(j - x.col);
                sum += row_diff + col_diff + (2 * (x.floor[i][j] - 1)); // sum = every uncleaned cell score + distance that at least needed to travel to
            }
        }
    }
    return x.score + sum;
}

bool isClean(state &x)
{
    vector< vector<bool> > reachable_matrix = get_reachable_matrix(x);
    int rows = reachable_matrix.size();
    int cols = reachable_matrix[0].size();
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (reachable_matrix[r][c] && x.floor[r][c] > 0) {
                return false;
            }
        }
    }
    return true;
}

vector<state> children_of(state &x)
{
    vector<state> children;
    int rows = x.floor.size();
    int cols = x.floor[0].size();

    for (int i = 0; i < 4; i++) {
        int newRow = x.row + directions[i][0];
        int newCol = x.col + directions[i][1];
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && x.floor[newRow][newCol] != -1)
        {
            state child = state(x.score + 1, newRow, newCol, x.floor);
            child.heuristic_value = heuristic(child);
            children.push_back(child);
        }
    }
    return children;
}

void clean(state &x)
{
    if (x.floor[x.row][x.col] > 0) {
        x.floor[x.row][x.col] -= 1; // Decrease the dirtiness by 1
        x.score += 1;               // Increase the score by 1 for cleaning
    }
}

// Display currect state to output log
void print_state(state &x, int best_so_far, int state_number) {
    vector< vector<int> > v = x.floor;
    cout << "State Number: " << state_number << endl;
    cout << "At position row: " << x.row << " column: " << x.col << endl;
    cout << "Score: " << x.score << " isClean = " << isClean(x) << endl;
    cout << "Heuristic score: " << x.heuristic_value << endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Best min value so far: " << best_so_far << endl;
    cout << "------------------------------" << endl;
}

// Least cost search main function
state cleaning_robot(state &start)
{
    vector< vector<bool> > reachable_matrix = get_reachable_matrix(start);
    int best = INT_MAX;
    state best_state = start;
    int state_num = 0;

    set<state> state_collection;
    priority_queue<state, vector<state>, heuristic_comparer> pq;

    state_collection.insert(start);
    pq.push(start);
    while (!pq.empty())
    {
        state current = pq.top();
        pq.pop();
        state_num++;
        print_state(current, best, state_num);

        if (isClean(current))
        {
            if (current.score < best)
            {
                best = current.score;
                best_state = current;
            }
        }
        else {
            clean(current);
            vector<state> children = children_of(current);
            for (state &child : children)
            {
                if (child.heuristic_value < best) {
                    if (state_collection.find(child) == state_collection.end()) {
                        state_collection.insert(child);
                        pq.push(child);
                    }
                }
            }
        }
    }
    return best_state;
}

int main(int argc, char const *argv[])
{
    vector< vector<int> > floor(4, vector<int> (4));
    floor[0][0] = 3;
    floor[0][1] = 2;
    floor[0][2] = -1;
    floor[0][3] = 1;
    floor[1][0] = 0;
    floor[1][1] = 1;
    floor[1][2] = -1;
    floor[1][3] = 5;
    floor[2][0] = 2;
    floor[2][1] = 1;
    floor[2][2] = -1;
    floor[2][3] = 3;
    floor[3][0] = 2;
    floor[3][1] = -1;
    floor[3][2] = -1;
    floor[3][3] = 48;
    /* start at (0,0)
    3 2 -1 1
    0 1 -1 5
    2 1 -1 3
    2 -1 -1 48
    finish
    0 0 -1 1
    0 0 -1 5
    0 0 -1 3
    0 -1 -1 48
    */
    state start(0, 0, 0, floor);
    state result = cleaning_robot(start);

    //print_state(result, result.score, -1);
    cout << "Total Score: " << result.score << endl;
    return 0;
}