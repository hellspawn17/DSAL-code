#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// Structure to represent an edge
struct Edge {
char destination;
int cost;
};
// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<Edge>>& graph, char source, char destination) {
int numCities = graph.size();
// Create a vector to store the shortest distance from source to each city
vector<int> distance(numCities, INT_MAX);
// Create a min heap to store the vertices and their distances
priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
// Initialize the distance of source city as 0 and push it into the min heap
distance[source - 'A'] = 0;
pq.push({0, source});
// Process vertices until the min heap is empty
while (!pq.empty()) {
char currentCity = pq.top().second;
int currentDistance = pq.top().first;
pq.pop();
// If the current distance is greater than the shortest distance, skip
if (currentDistance > distance[currentCity - 'A']) {
continue;
}
// Iterate through all the neighboring cities of the current city
for (Edge& edge : graph[currentCity - 'A']) {
int newDistance = distance[currentCity - 'A'] + edge.cost;
// If the new distance is shorter, update the shortest distance
if (newDistance < distance[edge.destination - 'A']) {
distance[edge.destination - 'A'] = newDistance;
pq.push({newDistance, edge.destination});
}
}
}
// Print the shortest distance from source to destination
cout << "Shortest distance from city " << source << " to city " << destination << ": ";
if (distance[destination - 'A'] == INT_MAX) {
cout << "No path found." << endl;
} else {
cout << distance[destination - 'A'] << endl;
}
}
int main() {
int numCities, numFlights;
cout << "Enter the number of cities: ";
cin >> numCities;
cout << "Enter the number of flights: ";
cin >> numFlights;
// Create a graph to represent the flight paths between cities
vector<vector<Edge>> graph(numCities);
// Take input for flight paths and their costs
for (int i = 0; i < numFlights; i++) {
char source, destination;
int cost;
cout << "Enter the source city, destination city, and cost of flight " << i + 1 << ": ";
cin >> source >> destination >> cost;
// Add the flight path to the graph
graph[source - 'A'].push_back({destination, cost});
}
char source, destination;
cout << "Enter the source city: ";
cin >> source;
cout << "Enter the destination city: ";
cin >> destination;
// Call the Dijkstra's algorithm function
dijkstra(graph, source, destination);
return 0;
}
