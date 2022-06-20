/* Program that returns the maximum distance from a node. */
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <random>
using namespace std;
 
//I think the intuative solution would be to make a "GraphNode" class, generate a network, then run through the network while marking each node as the lowest of the connected distances+1
//I've coded that before in my graceful tree and graph isomorphism projects, but I think I can avoid extranious classes.
//As the connections are non-weighted, only integer distances will be used. I can use this to build a simpler solution that just tracks jumps away.

//the plan is as follows:
//make  dictionary of connected nodes for search efficiency
//the set of connected nodes += nodes connected to connected nodes, distAway+=1
//when all nodes connected, return distAway

//provided it's implemented right, it's time complexity should be O(c), where c is connections. Each node is run once, and on it each connection is examined once.


int furthestRoom(vector<pair<int, int> > input) {
	int size = input.size();
	map<int,set<int>> Connections;
	set<int> connectedNodes;
	set<int> freshlyConnected;
	set<int> toConnect;
	int highestRoom=-1;
	int distAway = 0;
	int lastFrame = 0;
	//add each item to map
	for (int i = 0;i < size;i++)
	{
		Connections[input[i].first].insert(input[i].second);//sets can handle duplicate connections
		Connections[input[i].second].insert(input[i].first);
		if (highestRoom < input[i].first)
			highestRoom = input[i].first;
		if (highestRoom < input[i].second)
			highestRoom = input[i].second;
	}
	connectedNodes.insert(0);
	freshlyConnected.insert(0);
	set<int> newConnections;
	//this loop looks for connections to new nodes, off of the nodes added last cycle
	while (lastFrame != freshlyConnected.size() && !connectedNodes.count(highestRoom))
	{
		distAway++;
		//run while you're still adding new rooms, or until you've found the last room 
		for (int node : freshlyConnected)
		{
			newConnections.clear();
			set_difference(Connections[node].begin(), Connections[node].end(), connectedNodes.begin(), connectedNodes.end(),//upon review, this line makes it O(n^2) for worst case as it reads all of SetConnections
				inserter(newConnections, newConnections.begin()));//It should be replaced with something that ignores connections' length, i.e. foreach thing in newConnections, check if in connections, yes/no
			
			toConnect.insert(newConnections.begin(),newConnections.end());
		}
		freshlyConnected = toConnect;
		connectedNodes.insert(toConnect.begin(),toConnect.end());
		toConnect.clear();
	}
	if (!connectedNodes.count(highestRoom))
		return -1;//not reachable through any path
	return distAway;
}

int main() {
	

	vector<pair<int, int> > input;
	input.push_back(pair<int, int>(0, 1));
	input.push_back(pair<int, int>(1, 2));
	input.push_back(pair<int, int>(1, 3));
	input.push_back(pair<int, int>(2, 4));
	input.push_back(pair<int, int>(4, 5));
	input.push_back(pair<int, int>(3, 4));

	cout << furthestRoom(input) << endl;
	return 0;
}