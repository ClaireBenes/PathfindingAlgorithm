#pragma once

#include <string>;
#include <vector>

#include <limits>
#define inf std::numeric_limits<int>::max()

class Djikstra
{
public:
	void Dijkstra(int origin, int graph[12][12], int dist[], int prev[]);
	void GetPath(int destination, int dist[], int prev[], std::string letters[]);

	void GPS(int origin, int destination);
};

