#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 座標を表す構造体
struct Point {
    int row, col;

    Point(int r, int c) : row(r), col(c) {}
};

// 幅優先探索
vector<Point> bfs(const Point& start, const Point& goal, vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<Point>> parent(rows, vector<Point>(cols, Point(-1, -1)));
    queue<Point> q;
    
    // 上下左右への移動ベクトル
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    q.push(start);
    visited[start.row][start.col] = true;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        // ゴールに到達したら探索を終了
        if (current.row == goal.row && current.col == goal.col) {
            break;
        }

        for (const auto& dir : directions) {
            int new_row = current.row + dir.first;
            int new_col = current.col + dir.second;

            // マップの範囲内かつ未訪問の座標を探索
            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && !visited[new_row][new_col] && grid[new_row][new_col] != '#') {
                q.push(Point(new_row, new_col));
                visited[new_row][new_col] = true;
                parent[new_row][new_col] = current;
            }
        }
    }

    // スタートからゴールまでのルートを復元
    vector<Point> path;
    Point current = goal;
    while (current.row != -1 && current.col != -1) {
        path.push_back(current);
        current = parent[current.row][current.col];
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // マップの例
    vector<vector<char>> mapGrid = {
        {'S', '.', '.', '#', '.', '.'},
        {'#', '#', '.', '#', '#', '.'},
        {'.', '.', '.', '.', '.', '.'},
        {'#', '#', '#', '#', '#', 'G'},
    };

    Point start(0, 0);
    Point goal(3, 5);

    vector<Point> route = bfs(start, goal, mapGrid);

    // 探索中の座標の出力
    cout << "Coordinates being searched:" << endl;
    for (size_t step = 0; step < route.size(); ++step) {
        cout << "Step " << step << ": (" << route[step].row << ", " << route[step].col << ")" << endl;
    }

    // スタートからゴールまでのルートの出力
    cout << "\nRoute from start to goal:" << endl;
    for (const auto& point : route) {
        cout << "(" << point.row << ", " << point.col << ")" << endl;
    }

    return 0;
}