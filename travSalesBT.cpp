// C++ implementation of the approach
#include <iostream>
using namespace std;
#define V 4

// Function to find the minimum weight Hamiltonian Cycle
void tsp(int graph[][V], vector<bool>& v, int currPos,
		int n, int count, int cost, int& ans)
{
	if (count == n && graph[currPos][0]) {
		ans = min(ans, cost + graph[currPos][0]);
		return;
	}
	// BACKTRACKING STEP
	for (int i = 0; i < n; i++) {
		if (!v[i] && graph[currPos][i]) {

			// Mark as visited
			v[i] = true;
			tsp(graph, v, i, n, count + 1,
				cost + graph[currPos][i], ans);

			// Mark ith node as unvisited
			v[i] = false;
		}
	}
};

// Driver code
int main()
{
	// n is the number of nodes i.e. V
	int n = 4;

	int graph[][V] = {
		{ 0, 10, 15, 20 },
		{ 10, 0, 35, 25 },
		{ 15, 35, 0, 30 },
		{ 20, 25, 30, 0 }
	};

	// Boolean array to check if a node
	// has been visited or not
	vector<bool> v(n);
	for (int i = 0; i < n; i++)
		v[i] = false;

	// Mark 0th node as visited
	v[0] = true;
	int ans = INT_MAX;

	// Find the minimum weight Hamiltonian Cycle
	tsp(graph, v, 0, n, 1, 0, ans);

	// ans is the minimum weight Hamiltonian Cycle
	cout << ans;

	return 0;
}
