Flight Path Optimization System for Domestic Routes 

 🔍 An Optimized Flight Path Finder for Domestic Routes in India, built using C++ and Qt Framework. This project helps users find the shortest and most efficient path between two domestic airports in India using graph-based algorithms:
1) Dijkstra's Algorithm
2) A* Algorithm
It offers an interactive and visually appealing GUI to explore routes and also calculates the time taken by each algorithm to find the respective distance.

🧠 Core Functionalities:
✅ Data Loading & Cleaning
 Efficiently reads and pre-processes airport connection data from a CSV file handling data cleaning.
 
✅ Graph Construction
 Airports are modeled as nodes and flight distances as weighted edges. The backend constructs the graph and integrates Dijkstra and A* algorithms for pathfinding.
 
✅ Pathfinding Engine
 Allows users to choose between Dijkstra or A* to find the shortest route between two airports (via IATA code or full name). Returns the optimal path, total distance (in km), and execution time (in ms).
 
✅ Interactive GUI
 Developed using Qt, featuring intuitive search boxes with auto-complete, styled result displays, and real-time output for distance and time.

👨‍💻 Tools & Technologies:
Language: C++
Framework: Qt (for GUI)
Algorithms: Dijkstra, A*
Data Structures: Graph (Adjacency List), Priority Queues
Libraries Used: <iostream>, <fstream>, <sstream>, <unordered_map>, <queue>, Qt Widgets & Core
