#include <iostream>
#include <vector>
#include <map>
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

using namespace std;
typedef std::pair<int, int> VertexDistancePair;


//GRAPH
class graph{
public:
    graph(int s=0,double d=0.5,int weightMin=1,int weightMax=20);
    graph(string filename);
    void printGraph();
    double getDensity();
    int verticesCount();
    int edgesCount();
    unsigned int randr(unsigned int min, unsigned int max);
    bool adjacent(int first,int second);
    map<int,int> neighbors(int vertice);
    void add(int first,int second);
    void del(int first,int second);
    int get_edge_value(int first,int second);
    void set_edge_value(int first,int second,int val);
    pair<int,vector<int>> shortestPath(int startNode, int endNode);
    pair<int,vector<pair<int,int> > > MinSpanTree();      // return cost + vector of edges(pairs of 2 vertexes)

protected:
    int size;
    double density;
    int **adjMatrix;
    /* int adjMatrix[9][9]= {
          {INT_MAX,4,3,INT_MAX,7,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
          {4, INT_MAX,INT_MAX,1,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
          {3,INT_MAX,INT_MAX,INT_MAX,4,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
          {INT_MAX,1,INT_MAX,INT_MAX,3,1,INT_MAX,INT_MAX,INT_MAX},
          {7,INT_MAX,4,3,INT_MAX,1,5,INT_MAX,3},
          {INT_MAX,INT_MAX,INT_MAX,1,1,INT_MAX,INT_MAX,2,4},
          {INT_MAX,INT_MAX,INT_MAX,INT_MAX,5,INT_MAX,INT_MAX,INT_MAX,5},
          {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,2,INT_MAX,INT_MAX,3},
          {INT_MAX,INT_MAX,INT_MAX,INT_MAX,3,4,5,3,INT_MAX}
        };

   int adjMatrix[9][9]= {
          {INT_MAX,INT_MAX,1,3,INT_MAX,INT_MAX},
          {INT_MAX,INT_MAX,INT_MAX,5,INT_MAX,INT_MAX},
          {1,INT_MAX,INT_MAX,2,1,4},
          {3,5,2,INT_MAX,7,INT_MAX},
          {INT_MAX,INT_MAX,1,7,INT_MAX,2},
          {INT_MAX,INT_MAX,4,INT_MAX,2,INT_MAX}
    };*/
};

//helper methods
static bool compare(VertexDistancePair i, VertexDistancePair j);
VertexDistancePair getMin(map<int, int> mymap);
vector <int> reconstructPath(vector<int> nodesTaken,vector<int> parents,int startNode);

#endif // GRAPH_H_INCLUDED
