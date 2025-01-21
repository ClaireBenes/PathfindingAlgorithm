#include "Djikstra.h"

void Djikstra::Dijkstra(int origin, int graph[12][12], int dist[], int prev[])
{
    std::vector<int> openNodes;

    for(int i = 0; i < sizeof(graph[0]) / sizeof(int); i++)
    {

        dist[i] = inf;
        prev[i] = -1;

        openNodes.push_back(i);
    }

    dist[origin] = 0;

    while(!openNodes.empty())
    {
        int currentNode = openNodes[0];
        for(int node : openNodes)
        {
            if(dist[node] < dist[currentNode])
            {
                currentNode = node;
            }
        }

        auto it = std::find(openNodes.begin(), openNodes.end(), currentNode);
        openNodes.erase(it);

        for(int neighbor : openNodes)
        {
            int tempDistance = dist[currentNode] + graph[currentNode][neighbor];

            if(tempDistance < dist[neighbor] && tempDistance > 0)
            {
                dist[neighbor] = tempDistance;
                prev[neighbor] = currentNode;
            }
        }
    }
}

void Djikstra::GetPath(int destination, int dist[], int prev[], std::string letters[])
{
    int origin = destination;
    int node = destination;

    std::string path = "";
    while(node >= 0)
    {
        path = letters[node] + path;
        if(prev[node] < 0)
        {
            origin = node;
        }
        else
        {
            path = "-" + path;
        }

        node = prev[node];
    }


    printf("\nBest path from %s to %s is : %s\n", letters[origin].c_str(), letters[destination].c_str(), path.c_str());
    printf("The cost is : %i\n\n", dist[destination]);
}

void Djikstra::GPS(int origin, int destination)
{
    int graph[12][12] =
    {
        //   A,  B , C , D , E , F , G , H , I , J , K , L
              0,  2,inf,inf, 13,inf,inf,inf,inf,inf,  7, 10, //A
            inf,  0,inf,inf,inf,inf,  1,inf,inf,inf,inf,inf, //B
            inf,inf,  0,inf,  1,inf,inf,  1,inf,  2,inf,inf, //C
            inf,inf,inf,  0,inf,  8,inf,  4,inf,inf,inf,inf, //D
            inf,inf,inf,inf,  0,inf,inf,inf,inf,  5,inf,inf, //E
            inf,inf,inf,inf,inf,  0,inf,inf,inf,inf,inf,inf, //F
            inf,inf,inf,  5,inf,inf,  0,  2,inf,inf,inf,  3, //G
            inf,inf,inf,inf,inf, 10,inf,  0,  4,  7,inf,inf, //H
            inf,inf,inf,inf,inf,  5,inf,inf,  0,inf,inf,inf, //I
            inf,inf,inf,inf,inf,  1,inf,inf,  9,  0,inf,inf, //J
            inf,inf,  3,inf,  8,inf,inf,inf,inf,inf,  0,  5, //K
            inf,  6,inf,inf,inf,inf,inf, 12,inf,inf,inf,  0  //L

    };

    std::string allLetters[12] =
    {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"
    };

    int dist[12];
    int prev[12];

    Dijkstra(origin, graph, dist, prev);

    for(int i = 0; i < sizeof(graph[0]) / sizeof(int); i++)
    {
        if(dist[i] != inf && prev[i] >= 0)
        {
            printf("%s : %s = %i\n", allLetters[prev[i]].c_str(), allLetters[i].c_str(), dist[i]);
        }
    }

    GetPath(destination, dist, prev, allLetters);
}
