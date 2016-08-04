#include <iostream>
#include <stdlib.h>
#include <iterator>     //istream_iterator
#include <limits.h>
#include <algorithm>    //min_element()
#include <fstream>      //ifstream
#include "graph.h"

#define UNKNOWN 99999
using namespace std;

////////////////////// RANDOM NUMBER GENERATOR //////////////////////////////////////////
unsigned int graph::randr(unsigned int min, unsigned int max)
{
       double scaled = (double)rand()/RAND_MAX;
       return (max - min +1)*scaled + min;
}


// GRAPH CLASS
//////////////////////////////////////////CONSTRUCTOR /////////////////////////////////////
graph::graph(int s,double d,int weightMin,int weightMax):
    size(s),density(d){

        srand(time(0));
        //allocate memory
        adjMatrix = new int* [s];
        for(int i = 0; i < s; i++){
            adjMatrix[i] = new int [s];
        }

        //fill with values
        for (int i = 0; i < s; i++){
            for (int j = i; j < s; j++){
                if(randr(0,100)/100.0 < d && i!=j){
                    adjMatrix[i][j] = randr(weightMin,weightMax);
                    adjMatrix[j][i]=adjMatrix[i][j];
                }
                else{
                    adjMatrix[i][j]=INT_MAX;
                    adjMatrix[j][i]=INT_MAX;
                }
            }
        }
    };

//////////////////////////////////////CONSTRUCTOR FROM FILE ///////////////////////////////
graph::graph(string filename){
    int a,b,c;
    ifstream data_file(filename);

    data_file >> a;     //first number in file is size
    this->size = a;

    adjMatrix = new int* [a];
    for(int i = 0; i < a; i++){
            adjMatrix[i] = new int [a];
            for(int j = 0; j < a; j++){
                adjMatrix[i][j]=INT_MAX;        //initialize whole doubledim array with INT MAX
            }
    }

    while(data_file >>a>>b>>c){         //read input stream and overwrite array on read indexes
        //cout << a << " "<<  b << " " << c << endl;
        adjMatrix[a][b] = c;
    }
}

////////////////////////////////////PRINT ADJACENCY MATRIX /////////////////////////////
void graph::printGraph(){
    for(int i=0;i<this->verticesCount();i++){
        for(int j=0;j<this->verticesCount();j++){
                cout << this->adjMatrix[i][j] << " ";
        }
    cout << endl;
    }
}


double graph::getDensity(){
    return density;
}

int graph::verticesCount(){
    return size;
}

int graph::edgesCount(){
    int countEdges=0;
    for (int i = 0; i < size; i++){
            for (int j = i; j < size; ++j){
                   if(adjMatrix[i][j]!=INT_MAX){
                        countEdges++;
                   }
            }
    }
    return countEdges;
}

bool graph::adjacent(int first, int second){
    if(adjMatrix[first][second]!=INT_MAX){
                        return true;
    }
    return false;
}

/////////////////////////////////////////// RETURN NEIGHBORS OF THE SPECIFIED VERTEX //////////////////////////
map<int,int> graph::neighbors(int vertice){
     //vector <int> neighs;
     map<int,int> neighs;
     for (int j = 0; j < size; ++j){
                   if(adjMatrix[vertice][j]!=INT_MAX){
                        //neighs.push_back(j);
                        neighs.insert ( pair<int,int>(j,adjMatrix[vertice][j]));        //insert neighboring Id and distance of the edge
                   }
     }
     return neighs;
}

void graph::add(int first,int second){
    if(adjMatrix[first][second]==INT_MAX && first!=second){
            srand(time(0));
            adjMatrix[first][second] = randr(1,10);
            adjMatrix[second][first]=adjMatrix[first][second];
    }
}

void graph::del(int first,int second){
    if(adjMatrix[first][second]!=INT_MAX){
            adjMatrix[first][second] = INT_MAX;
            adjMatrix[second][first]=INT_MAX;
    }
}

void graph::set_edge_value(int first,int second,int val){
    adjMatrix[first][second] = val;
    adjMatrix[second][first]= val;
}

int graph::get_edge_value(int first,int second){
    return adjMatrix[first][second];
}


bool compare(VertexDistancePair i, VertexDistancePair j)      //comparator for getMin method
{
  return i.second < j.second;
}

VertexDistancePair getMin(map<int, int> vertexes)
{
  VertexDistancePair min = *min_element(vertexes.begin(), vertexes.end(), &compare);
  return min;
}


pair<int,vector<int>> graph::shortestPath(int startNode, int endNode){
    int current = startNode;
    int traveled = 0;
    int newDistance = 0;            //new calculated distane

    //INIT OF PATHS MAP
    map<int,int> vertexes;
    map<int,int> parents;
    vector<int> parentsTaken;
    vector<int> nodesTaken;
    for(int i=0; i<this->verticesCount();i++){
         vertexes.insert ( VertexDistancePair (i,INT_MAX));         //<vertexID, vertexSmallestDistance>
         parents.insert ( VertexDistancePair (i,UNKNOWN));          //vertexID, vertexParent>
    }
    vertexes.erase(startNode);     //exclude startNode from possible steps -> acts like visited flag

    map<int,int> neighs;
    map<int,int>::iterator it;
    VertexDistancePair minPath;     //each iteration chosen minPath from options

    while(current!=endNode){        //till not in final node
        neighs = this->neighbors(current);

        if(current==startNode){     //just add startNode to results
            parentsTaken.push_back(UNKNOWN);
        }
        else{
            parentsTaken.push_back(parents.at(current));    //add a parent of new current in each iteration
        }
        nodesTaken.push_back(current);

        for (it=neighs.begin(); it!=neighs.end(); ++it){
            newDistance = traveled + it->second;            //distance to current + edge value
            if(vertexes.find(it->first) != vertexes.end()){     //if vertice still exists -> means hasn't yet been visited
                if(vertexes.at(it->first)>newDistance){         //if new found path is better, then overwrite distance value and also parent
                    vertexes.at(it->first)=newDistance;
                    parents.at(it->first)=current;
                }
            }
        }

        //decide which step is the minimal distance and take it
        minPath=getMin(vertexes);             //get closest vertex from the options
        current = minPath.first;                    //take a step
        traveled = minPath.second;
        vertexes.erase(current);
    }
    parentsTaken.push_back(parents.at(current));        //push final vertexes to results
    nodesTaken.push_back(current);

    vector <int> traveledPath = reconstructPath(nodesTaken,parentsTaken,startNode);
   /* for(int i=0;i<nodesTaken.size();i++){
        cout << nodesTaken.at(i);
    }
    cout << endl;

    for(int i=0;i<parentsTaken.size();i++){
        cout << parentsTaken.at(i);
    }

    cout << endl;*/
    return make_pair(traveled,traveledPath);
}




vector <int> reconstructPath(vector<int> nodesTaken,vector<int> parents,int startNode){
    vector <int> traveledPath;
    traveledPath.push_back(nodesTaken.back());
    traveledPath.push_back(parents.back());
    int index;
    int value=nodesTaken.back();                //value of final node
    while(traveledPath.back()!=startNode){
        for(int i=0;i<nodesTaken.size();i++){
            if(nodesTaken.at(i)==value){
                index=i;                        //loop taken nodes and get index of current "step"
            }
        }
        value = parents.at(index);              //then go to parent
        traveledPath.push_back(value);          //and push parent to final path
    }
    return traveledPath;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                // HOMEWORK WEEK 3
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

pair<int,vector<pair<int,int> > > graph::MinSpanTree(){
    //declarations
    int lastConnected=0;        //last added/connected vertex
    pair<int,int> chosenEdge;   //chosen option open set - distance,secondVertex (first one not needed - already connected)
    int size=0;
    vector<tuple<int,int,int> > distances;      //open set
    vector<int> connectedVertexes = {lastConnected};    //vector with all connected vertexes - used to check
    vector <pair<int, int> > usedEdges;                 //output
    int min=INT_MAX;

    while(connectedVertexes.size()!=this->verticesCount()){
        //add new options to open set <distance,firstVertex,secondVertex>
        for(int i=0;i<this->verticesCount();i++){
            if(this->get_edge_value(lastConnected,i)!=INT_MAX){     //add all edges of newly connected vertex
                distances.push_back(make_tuple(this->get_edge_value(lastConnected,i),lastConnected,i));
            }
        }
        min=INT_MAX;
        for(int i=0;i<distances.size();i++){
            //choose adge where secondVertex is not added yet + distance is smallest possible
            if(min > get<0>(distances.at(i)) && find(connectedVertexes.begin(), connectedVertexes.end(), get<2>(distances.at(i))) == connectedVertexes.end()){
                min = get<0>(distances.at(i));
                chosenEdge=make_pair(get<1>(distances.at(i)),get<2>(distances.at(i)));
            }
        }
        lastConnected=chosenEdge.second;
        connectedVertexes.push_back(lastConnected);
        size = size + min;
        usedEdges.push_back(chosenEdge);
    }

    cout << "Minimal Spanning Tree size is  " << size << endl;
    cout << "Edges used are: " << endl;

    //iterating using C++11 feature of range iteration
    for(auto const& value: usedEdges) {
        cout << value.first << "-" << value.second << endl;
    }
    return make_pair(size,usedEdges);
}
