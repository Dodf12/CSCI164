#include <iostream>
#include "graph.h"

using namespace std;


int main()
{
    graph<string> g;


    cin >> g;
    cout << g;


    cout << "Vertices: ";
    for (auto &v: g.V())
      cout << v << " " ;
    cout << endl;

    for (auto &e: g.E())
      cout << e << " ";
    
    cout << endl;

    return 0;
}

