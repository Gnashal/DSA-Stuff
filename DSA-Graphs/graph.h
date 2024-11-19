#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct node {
    char dest;
    struct node * next;
}Node, *NodePtr;

typedef struct {
    int vertices;
    NodePtr * adjNodes;
}*Graph;

NodePtr createNode(char dest) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}



Graph createGraph(int vertices) {
    Graph newGraph = (Graph)malloc(sizeof(Graph));
    newGraph->vertices = vertices;
    newGraph->adjNodes = (NodePtr*)malloc(sizeof(Node) * newGraph->vertices);
     for (int i = 0; i < vertices; i++) {
        newGraph->adjNodes[i] = NULL;
    }
    return newGraph;
}

#endif