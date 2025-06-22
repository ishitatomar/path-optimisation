void aStar(const string& start, const string& goal) {
    unordered_map<string, int> gScore;
    unordered_map<string, int> fScore;
    unordered_map<string, string> prev;

    for (unordered_map<string, vector<pair<string, int>>>::iterator it = graph.begin(); it != graph.end(); ++it) {
        gScore[it->first] = INT_MAX;
        fScore[it->first] = INT_MAX;
    }

    gScore[start] = 0;
    fScore[start] = heuristic(start, goal);

    // Priority queue 
    typedef pair<int, string> PQItem;
    priority_queue<PQItem, vector<PQItem>, greater<PQItem>> openSet;
    openSet.push(make_pair(fScore[start], start));

    set<string> visited;

    while (!openSet.empty()) {
        PQItem currentItem = openSet.top();
        openSet.pop();
        string current = currentItem.second;

        if (visited.count(current)) continue;
        visited.insert(current);

        if (current == goal) break;

        for (size_t i = 0; i < graph[current].size(); ++i) {
            string neighbor = graph[current][i].first;
            int weight = graph[current][i].second;

            int tentativeG = gScore[current] + weight;
            if (tentativeG < gScore[neighbor]) {
                prev[neighbor] = current;
                gScore[neighbor] = tentativeG;
                fScore[neighbor] = tentativeG + heuristic(neighbor, goal);
                openSet.push(make_pair(fScore[neighbor], neighbor));
            }
        }
    }

    if (gScore[goal] == INT_MAX) {
        cout << "No path found using A*.\n";
        return;
    }

    vector<string> path;
    for (string at = goal; !at.empty(); at = prev[at])
        path.push_back(at);
    reverse(path.begin(), path.end());

    cout << "A* shortest path (" << gScore[goal] << " km): ";
    for (size_t i = 0; i < path.size(); ++i)
        cout << path[i] << (i == path.size() - 1 ? "\n" : " -> ");
}

int main() {
    string filename = "airport_connections.csv";
    loadCSV(filename);

    string source, destination;
    cout << "Enter source airport code (e.g., DEL): ";
    cin >> source;
    cout << "Enter destination airport code (e.g., BLR): ";
    cin >> destination;

    cout << "\nRunning Dijkstra...\n";
    dijkstra(source, destination);

    cout << "\nRunning A*...\n";
    aStar(source, destination);

    return 0;
}
