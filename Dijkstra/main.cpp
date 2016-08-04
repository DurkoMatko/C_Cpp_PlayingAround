#include <iostream>
#include "graph.cpp"

using namespace std;

int main()
{

    cout << "************************ WEEK 2+3 ******************************" << endl;
    graph g  = graph(9,0.44,1,10);

    pair<int,vector<int> > dijkstraPathResult = g.shortestPath(8,0);

    cout << "Shortest path from path_size is " <<  dijkstraPathResult.first<< endl << "Steps are following: " << endl;

    for(int i=dijkstraPathResult.second.size()-1;i>=0;i--){
        cout << dijkstraPathResult.second.at(i);
    }


    //HOMEWORK WEEK 3
    cout << endl<<endl << "************************ WEEK 4 ******************************" << endl;
    graph g2  = graph("graph_data.txt");
    g2.MinSpanTree();
    return 0;
}
