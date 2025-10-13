/*
 * Problem: Graph Traversal (DFS and BFS)
 * 
 * Implement Depth-First Search (DFS) and Breadth-First Search (BFS) for graph traversal.
 * Support both adjacency list and adjacency matrix representations.
 * 
 * Time Complexity: O(V + E) for adjacency list, O(V^2) for adjacency matrix
 * Space Complexity: O(V) for recursion stack/queue and visited array
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;
    vector<vector<int>> adjMatrix;
    bool useMatrix;
    
public:
    // Constructor for adjacency list representation
    Graph(int vertices, bool matrix = false) : numVertices(vertices), useMatrix(matrix) {
        adjList.resize(vertices);
        if (matrix) {
            adjMatrix.assign(vertices, vector<int>(vertices, 0));
        }
    }
    
    // Add edge (undirected graph)
    void addEdge(int src, int dest) {
        if (useMatrix) {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1; // For undirected graph
        } else {
            adjList[src].push_back(dest);
            adjList[dest].push_back(src); // For undirected graph
        }
    }
    
    // Add directed edge
    void addDirectedEdge(int src, int dest) {
        if (useMatrix) {
            adjMatrix[src][dest] = 1;
        } else {
            adjList[src].push_back(dest);
        }
    }
    
    // DFS Recursive
    vector<int> dfsRecursive(int startVertex) {
        vector<int> result;
        vector<bool> visited(numVertices, false);
        dfsRecursiveHelper(startVertex, visited, result);
        return result;
    }
    
    // DFS Iterative using stack
    vector<int> dfsIterative(int startVertex) {
        vector<int> result;
        vector<bool> visited(numVertices, false);
        stack<int> st;
        
        st.push(startVertex);
        
        while (!st.empty()) {
            int vertex = st.top();
            st.pop();
            
            if (!visited[vertex]) {
                visited[vertex] = true;
                result.push_back(vertex);
                
                // Add neighbors to stack (in reverse order for consistent traversal)
                if (useMatrix) {
                    for (int i = numVertices - 1; i >= 0; i--) {
                        if (adjMatrix[vertex][i] && !visited[i]) {
                            st.push(i);
                        }
                    }
                } else {
                    for (int i = adjList[vertex].size() - 1; i >= 0; i--) {
                        int neighbor = adjList[vertex][i];
                        if (!visited[neighbor]) {
                            st.push(neighbor);
                        }
                    }
                }
            }
        }
        
        return result;
    }
    
    // BFS using queue
    vector<int> bfs(int startVertex) {
        vector<int> result;
        vector<bool> visited(numVertices, false);
        queue<int> q;
        
        visited[startVertex] = true;
        q.push(startVertex);
        
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            result.push_back(vertex);
            
            // Add unvisited neighbors to queue
            if (useMatrix) {
                for (int i = 0; i < numVertices; i++) {
                    if (adjMatrix[vertex][i] && !visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            } else {
                for (int neighbor : adjList[vertex]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        
        return result;
    }
    
    // Find all connected components
    vector<vector<int>> findConnectedComponents() {
        vector<vector<int>> components;
        vector<bool> visited(numVertices, false);
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfsComponentHelper(i, visited, component);
                components.push_back(component);
            }
        }
        
        return components;
    }
    
    // Check if graph is connected
    bool isConnected() {
        vector<int> traversal = dfsRecursive(0);
        return traversal.size() == numVertices;
    }
    
    // Detect cycle in undirected graph
    bool hasCycleUndirected() {
        vector<bool> visited(numVertices, false);
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                if (hasCycleUndirectedHelper(i, -1, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // Detect cycle in directed graph
    bool hasCycleDirected() {
        vector<bool> visited(numVertices, false);
        vector<bool> recStack(numVertices, false);
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                if (hasCycleDirectedHelper(i, visited, recStack)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // Find path between two vertices using BFS
    vector<int> findPathBFS(int start, int end) {
        if (start == end) return {start};
        
        vector<bool> visited(numVertices, false);
        vector<int> parent(numVertices, -1);
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            
            if (useMatrix) {
                for (int i = 0; i < numVertices; i++) {
                    if (adjMatrix[vertex][i] && !visited[i]) {
                        visited[i] = true;
                        parent[i] = vertex;
                        q.push(i);
                        
                        if (i == end) {
                            return reconstructPath(parent, start, end);
                        }
                    }
                }
            } else {
                for (int neighbor : adjList[vertex]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        parent[neighbor] = vertex;
                        q.push(neighbor);
                        
                        if (neighbor == end) {
                            return reconstructPath(parent, start, end);
                        }
                    }
                }
            }
        }
        
        return {}; // No path found
    }
    
    // Print adjacency list
    void printAdjacencyList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    
    // Print adjacency matrix
    void printAdjacencyMatrix() {
        cout << "Adjacency Matrix:" << endl;
        cout << "  ";
        for (int i = 0; i < numVertices; i++) {
            cout << i << " ";
        }
        cout << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << i << " ";
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
private:
    void dfsRecursiveHelper(int vertex, vector<bool>& visited, vector<int>& result) {
        visited[vertex] = true;
        result.push_back(vertex);
        
        if (useMatrix) {
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[vertex][i] && !visited[i]) {
                    dfsRecursiveHelper(i, visited, result);
                }
            }
        } else {
            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    dfsRecursiveHelper(neighbor, visited, result);
                }
            }
        }
    }
    
    void dfsComponentHelper(int vertex, vector<bool>& visited, vector<int>& component) {
        visited[vertex] = true;
        component.push_back(vertex);
        
        if (useMatrix) {
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[vertex][i] && !visited[i]) {
                    dfsComponentHelper(i, visited, component);
                }
            }
        } else {
            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    dfsComponentHelper(neighbor, visited, component);
                }
            }
        }
    }
    
    bool hasCycleUndirectedHelper(int vertex, int parent, vector<bool>& visited) {
        visited[vertex] = true;
        
        if (useMatrix) {
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[vertex][i]) {
                    if (!visited[i]) {
                        if (hasCycleUndirectedHelper(i, vertex, visited)) {
                            return true;
                        }
                    } else if (i != parent) {
                        return true;
                    }
                }
            }
        } else {
            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    if (hasCycleUndirectedHelper(neighbor, vertex, visited)) {
                        return true;
                    }
                } else if (neighbor != parent) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool hasCycleDirectedHelper(int vertex, vector<bool>& visited, vector<bool>& recStack) {
        visited[vertex] = true;
        recStack[vertex] = true;
        
        if (useMatrix) {
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[vertex][i]) {
                    if (!visited[i] && hasCycleDirectedHelper(i, visited, recStack)) {
                        return true;
                    } else if (recStack[i]) {
                        return true;
                    }
                }
            }
        } else {
            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor] && hasCycleDirectedHelper(neighbor, visited, recStack)) {
                    return true;
                } else if (recStack[neighbor]) {
                    return true;
                }
            }
        }
        
        recStack[vertex] = false;
        return false;
    }
    
    vector<int> reconstructPath(const vector<int>& parent, int start, int end) {
        vector<int> path;
        int current = end;
        
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        reverse(path.begin(), path.end());
        return path;
    }
    
public:
    // Helper function to print vector
    static void printVector(const vector<int>& vec, const string& label) {
        cout << label << ": ";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i < vec.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
    
    // Helper function to print components
    static void printComponents(const vector<vector<int>>& components) {
        cout << "Connected Components:" << endl;
        for (int i = 0; i < components.size(); i++) {
            cout << "Component " << i + 1 << ": ";
            for (int j = 0; j < components[i].size(); j++) {
                cout << components[i][j];
                if (j < components[i].size() - 1) cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "=== Graph Traversal (DFS and BFS) ===" << endl << endl;
    
    // Test case 1: Connected graph with adjacency list
    cout << "Test 1: Connected Graph (Adjacency List)" << endl;
    Graph g1(6);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(2, 5);
    
    g1.printAdjacencyList();
    
    Graph::printVector(g1.dfsRecursive(0), "DFS Recursive");
    Graph::printVector(g1.dfsIterative(0), "DFS Iterative");
    Graph::printVector(g1.bfs(0), "BFS");
    
    cout << "Is Connected: " << (g1.isConnected() ? "Yes" : "No") << endl;
    cout << "Has Cycle: " << (g1.hasCycleUndirected() ? "Yes" : "No") << endl;
    
    vector<int> path = g1.findPathBFS(0, 4);
    Graph::printVector(path, "Path from 0 to 4");
    cout << endl;
    
    // Test case 2: Graph with multiple components
    cout << "Test 2: Disconnected Graph" << endl;
    Graph g2(7);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(3, 4);
    g2.addEdge(5, 6);
    
    g2.printAdjacencyList();
    
    Graph::printVector(g2.dfsRecursive(0), "DFS from vertex 0");
    Graph::printVector(g2.bfs(0), "BFS from vertex 0");
    
    cout << "Is Connected: " << (g2.isConnected() ? "Yes" : "No") << endl;
    
    auto components = g2.findConnectedComponents();
    Graph::printComponents(components);
    cout << endl;
    
    // Test case 3: Graph with cycle
    cout << "Test 3: Graph with Cycle" << endl;
    Graph g3(4);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    g3.addEdge(3, 0); // Creates a cycle
    
    g3.printAdjacencyList();
    cout << "Has Cycle: " << (g3.hasCycleUndirected() ? "Yes" : "No") << endl;
    cout << endl;
    
    // Test case 4: Directed graph with adjacency matrix
    cout << "Test 4: Directed Graph (Adjacency Matrix)" << endl;
    Graph g4(4, true); // Use adjacency matrix
    g4.addDirectedEdge(0, 1);
    g4.addDirectedEdge(1, 2);
    g4.addDirectedEdge(2, 3);
    g4.addDirectedEdge(3, 1); // Creates a cycle in directed graph
    
    g4.printAdjacencyMatrix();
    
    Graph::printVector(g4.dfsRecursive(0), "DFS Recursive");
    Graph::printVector(g4.bfs(0), "BFS");
    
    cout << "Has Cycle (Directed): " << (g4.hasCycleDirected() ? "Yes" : "No") << endl;
    
    return 0;
}