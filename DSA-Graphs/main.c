#include "graph.h"
#include <stdio.h>

int main () {
    Graph graph = createGraph();

    Name name1 = createName("John", "Doe");
    Name name2 = createName("Jane", "Smith");
    Name name3 = createName("Alice", "Johnson");
    Name name4 = createName("Alice", "May");

    NodePtr a = createNode(name1, 0);
    NodePtr b = createNode(name2, 0);
    NodePtr c = createNode(name3, 0);
    NodePtr d = createNode(name4, 0);


    // Insert nodes into the graph
    insertToGraph(a, &graph);
    insertToGraph(b, &graph);
    insertToGraph(c, &graph);
    insertToGraph(d, &graph);

    addEdge(&graph, a, b, 4);
    addEdge(&graph, a, c, 1);
    addEdge(&graph, b, c, 2);

    // Display the graph
    printf("Graph contents:\n");
    display(graph);

    // Free the graph's memory
    freeGraph(&graph);

    return 0;
}