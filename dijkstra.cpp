#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;
unordered_map<string, vector<pair<string, int>>> graph;

void dijkstra(const string& start, const string& goal) {
    unordered_map<string, int> dist;
    unordered_map<string, string> prev;

    for (unordered_map<string, vector<pair<string, int>>>::iterator it = graph.begin(); it != graph.end(); ++it) {
        dist[it->first] = INT_MAX;
    }

    dist[start] = 0;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        pair<int, string> top = pq.top();
        pq.pop();

        int currentDist = top.first;
        string current = top.second;

        if (current == goal) break;

        for (size_t i = 0; i < graph[current].size(); ++i) {
            string neighbor = graph[current][i].first;
            int weight = graph[current][i].second;
            int newDist = currentDist + weight;

            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                prev[neighbor] = current;
                pq.push(make_pair(newDist, neighbor));
            }
        }
    }

    if (dist[goal] == INT_MAX) {
        cout << "No path found using Dijkstra.\n";
        return;
    }

    // Reconstruction of the path
    vector<string> path;
    for (string at = goal; !at.empty(); at = prev[at])
        path.push_back(at);
    reverse(path.begin(), path.end());

    cout << "Dijkstra's shortest path (" << dist[goal] << " km): ";
    for (size_t i = 0; i < path.size(); ++i)
        cout << path[i] << (i == path.size() - 1 ? "\n" : " -> ");
}
//Even if the heuristic is 0, keeping the function in place allows you to easily update it later
int heuristic(const string& a, const string& b) {
    return 0;
}
