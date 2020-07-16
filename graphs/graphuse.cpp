#include <iostream>

using namespace std;

#include "graph.hpp"

int main()
{
    
    Graph<int> g;
    g.addedge(1, 0);
    g.addedge(1, 2);
    g.addedge(2, 4);
    g.addedge(0, 4);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(5, 3);

    g.addedge(6, 7);
    g.addedge(6, 8);
    /*

    Graph<string> g;
    g.addedge("English", "Programming", false);
    g.addedge("Maths", "Programming", false);
    g.addedge("Programming", "HTML", false);
    g.addedge("Programming", "Python", false);
    g.addedge("Programming", "Java", false);
    g.addedge("Programming", "JS", false);
    g.addedge("Python", "Web Dev", false);
    g.addedge("HTML", "CSS", false);
    g.addedge("CSS", "JS", false);
    g.addedge("JS", "Web Dev", false);
    g.addedge("Java", "Web Dev", false);
    g.print();
    g.bfstoposort();*/
    cout << g.iscyclicbfsundir();
    return 0;
}