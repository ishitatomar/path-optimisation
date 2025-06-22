void loadCSV(const string& filename) {
    ifstream file(filename);
    string line;

    getline(file, line); 

    set<string> seenEdges;
    while (getline(file, line)) {
        stringstream ss(line);
        string src, dest, distStr;
        getline(ss, src, ',');
        getline(ss, dest, ',');
        getline(ss, distStr);

        if (src.empty() || dest.empty() || distStr.empty())
            continue;

        int distance;
        try {
            distance = stoi(distStr);
        } catch (...) {
            continue; 
        }

        string edgeKey1 = src + "-" + dest;
        string edgeKey2 = dest + "-" + src;

        if (seenEdges.count(edgeKey1) == 0 && seenEdges.count(edgeKey2) == 0) {
            graph[src].push_back(make_pair(dest, distance));
            graph[dest].push_back(make_pair(src, distance)); 
            seenEdges.insert(edgeKey1);
            seenEdges.insert(edgeKey2);
        }
    }
}
