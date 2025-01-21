#include <iostream>

#include "Djikstra.h"
#include "AStar.h"

int main()
{
    //Djikstra dijkstra;

    //// A to J
    //dijkstra.GPS(0, 9);
    ////B to I
    //dijkstra.GPS(1, 8);

    std::vector<std::vector<int>> grid = {
        { 0, 0, 0, 1, 0 },
        { 1, 1, 0, 1, 0 },
        { 0, 0, 0, 1, 0 },
        { 0, 1, 1, 1, 0 },
        { 0, 0, 0, 0, 0 }
    };

    Vector2 start(0, 0);
    Vector2 goal(4, 4);

    AStar astar;
    astar.Algorithm(grid, start, goal);
}

