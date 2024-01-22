#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// グラフの隣接リスト表現を使った深さ優先探索のクラス
class Graph {
public:
    // グラフの頂点数
    int vertices;
    // 隣接リスト
    vector<vector<int>> adjacencyList;

    // 頂点に対応する座標を格納するための配列
    vector<pair<int, int>> coordinates;

    // コンストラクタ
    Graph(int v) : vertices(v), adjacencyList(v), coordinates(v) {}

    // グラフに辺を追加する関数
    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
    }

    // 深さ優先探索の実装
    void DFS(int startVertex, int goalVertex) {
        // 訪れた頂点を格納するための配列
        vector<bool> visited(vertices, false);

        // スタックを使って深さ優先探索を実行
        stack<int> dfsStack;
        dfsStack.push(startVertex);

        while (!dfsStack.empty()) {
            // スタックから頂点を取り出す
            int currentVertex = dfsStack.top();
            dfsStack.pop();

            // 頂点がまだ訪れていない場合
            if (!visited[currentVertex]) {
                cout << "Current Coordinates: (" << coordinates[currentVertex].first << ", " << coordinates[currentVertex].second << ")" << endl;
                visited[currentVertex] = true;
            }

            // 頂点がゴールに到達したら終了
            if (currentVertex == goalVertex) {
                cout << "Goal Reached! Coordinates: (" << coordinates[currentVertex].first << ", " << coordinates[currentVertex].second << ")" << endl;
                break;
            }

            // 頂点の隣接する頂点をスタックに追加
            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    dfsStack.push(neighbor);
                }
            }
        }
    }
};

int main() {
    // グラフの頂点数
    int vertices = 5;
    Graph graph(vertices);

    // グラフに辺を追加
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);

    // 各頂点の座標を設定
    graph.coordinates[0] = make_pair(0, 0);
    graph.coordinates[1] = make_pair(1, 0);
    graph.coordinates[2] = make_pair(0, 1);
    graph.coordinates[3] = make_pair(2, 0);
    graph.coordinates[4] = make_pair(2, 1);

    // スタートとゴールの頂点
    int startVertex = 0;
    int goalVertex = 3;

    // 深さ優先探索を実行
    cout << "DFS starting from vertex " << startVertex << ":" << endl;
    graph.DFS(startVertex, goalVertex);

    return 0;
}