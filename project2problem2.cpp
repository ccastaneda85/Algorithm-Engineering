/*
Abstract:
Develop a pseudocode for an algorithm; analyze your pseudocode mathematically; implement the code
for the algorithm of your choice; test your implementation; and describe your results.

Problem 2: Network delay time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as
directed edges times[i] = (ui , vi , wi ), where ui is the source node, vi is the target node, and wi is the 
time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to
receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

*/

/*
Pseudocode:

    int networkDelayTime(times, int n, int k) -> returns output of signal traversal, returns -1 if impossible
        Create the graph: graph(n) -> O(e)
        
        Initialize distance array using total number of nodes in graph -> O(n)
        Push sourcee node into the priority queue -> O(logn)
        Worst case for exploring edges, updates distance and pushes to priority queue -> O(logn)
        
        Iterate through the array, finding max distance -> O(n)

    Total Time Complexity:
        T(n)    = e + n + logn + logn + n
                = e + 2logn + 2n
        T(n)    = O((e + n)logn)
*/


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

    int dijkstra(const vector<vector<pair<int, int>>>& graph, int src) {
/* Initializes the distance array with infinity*/
        vector<int> dist(graph.size(), INT_MAX);
        using P = pair<int, int>;  // uses d, u        
        priority_queue<P, vector<P>, greater<>> minHeap; // Create a min-heap,priority queue, to store nodes and their distances
 
        dist[src] = 0; // Sets source node distance to 0, push to min-heap stack
        minHeap.emplace(dist[src], src);

/* Begins Dijkstra's algorithm loop */
        while (!minHeap.empty()) {
            const auto [d, u] = minHeap.top(); // Extracts node with smallest distance from min-heap
            minHeap.pop();
            for (const auto& [v, w] : graph[u]) // Explore all adjacent neighbors of the extracted node
/* Update the distance if a shorter path is found */                
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    minHeap.emplace(dist[v], v);  // Push the updated distance and neighbor onto the min-heap
                }
        }

        const int maxDist = *max_element(dist.begin(), dist.end()); // Finds max distance from source node to other node
        return maxDist == INT_MAX ? -1 : maxDist;    // If any node cannot be reached, return -1; else, return the maximum distance

    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
/* Initializing an empty graph with an n # of nodes*/

        vector<vector<pair<int, int>>> graph(n); // Constructs graph from the 3 given times

        for (const vector<int>& time : times) {
            const int u = time[0] - 1; //Source node
            const int v = time[1] - 1; //Target node
            const int w = time[2];     //Time taken to traverse from source to target
            graph[u].emplace_back(v, w); 
        }
/* Using Dijkstra's algorithm to find the minimum time for signal propagation*/
   
        return dijkstra(graph, k - 1);
    }



int main() {

    vector<vector<int>> example1 = {{2,1,1},{2,3,1},{3,4,1}};
    cout << networkDelayTime(example1, 4, 2) << endl;  // Output: 2

    vector<vector<int>> example2 = {{1,2,1}};
    cout << networkDelayTime(example2, 2, 1) << endl;  // Output: 1

    vector<vector<int>> example3 = {{1,2,1}};
    cout << networkDelayTime(example3, 2, 2) << endl;  // Output: -1
    
    return 0;
}