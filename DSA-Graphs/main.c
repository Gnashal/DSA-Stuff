#include "graph.h"
#include <stdio.h>

int main () {
    Graph graph = createGraph();

    Name name1 = createName("John", "Doe");
    Name name2 = createName("Jane", "Smith");
    Name name3 = createName("Alice", "Johnson");
    Name name4 = createName("Alice", "May");

    NodePtr node1 = createNode(name1);
    NodePtr node2 = createNode(name2);
    NodePtr node3 = createNode(name3);
    NodePtr node4 = createNode(name4);


    // Insert nodes into the graph
    insertToGraph(node1, &graph);
    insertToGraph(node2, &graph);
    insertToGraph(node3, &graph);
    insertToGraph(node4, &graph);

    // Display the graph
    printf("Graph contents:\n");
    display(graph);

    // Free the graph's memory
    freeGraph(&graph);

    return 0;
}