#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX 100



typedef struct {
    char fname[20];
    char lname[20];
}Name;

typedef struct node {
    Name name;
    int weight;
    struct node * next;
}Node, *NodePtr;

typedef struct {
    int vertices;
    NodePtr * adjNodes;
}Graph;

Name createName(char* fname, char * lname) {
    Name newName;
    strcpy(newName.fname ,fname);
    strcpy(newName.lname ,lname);
    return newName;
}

NodePtr createNode(Name name, int weight) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->name = name;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}



Graph createGraph() {
    Graph newGraph;
    newGraph.vertices = 0;
    newGraph.adjNodes = (NodePtr*)malloc(sizeof(NodePtr) * MAX);
     for (int i = 0; i < MAX; i++) {
        newGraph.adjNodes[i] = NULL;
    }
    return newGraph;
}

unsigned long hash(char* fname, char* lname) {
    unsigned long hash = 5381;
    int c;
    while ((c = *fname++)) {
        hash = ((hash << 5) + hash) + c;
    }
    while ((c = *lname++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % MAX;
}
bool insertToGraph(NodePtr newNode, Graph* gh) {
    if (!newNode) {
        return false;
    }
    int pos = hash(newNode->name.fname, newNode->name.lname);
    gh->adjNodes[pos] = newNode;
    gh->vertices++;
    return true;
}

bool addConnection(NodePtr from, NodePtr to,Graph * gh) {
    int pos = hash(from->name.fname, from->name.lname);
    NodePtr curr = gh->adjNodes[pos];
    if (!curr) {
        gh->adjNodes[pos] = to;
    } else {
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = to;
    }
    return true;
}

bool addEdge(Graph* gh, NodePtr from, NodePtr to, int weight) {
    NodePtr newNode = createNode(to->name, weight);
    if (!newNode) {
        return false;
    }
    return addConnection(from ,newNode, gh);
}




void display(Graph gh) {
    for (int i = 0; i < MAX; ++i) {
        if (gh.adjNodes[i]) {
            NodePtr curr = gh.adjNodes[i];
            printf("%s: ", curr->name.fname);
            curr = curr->next;
            while (curr)
            {
                Name name = curr->name;
                printf("(W: %d, %s) -> ",curr->weight,name.fname);
                curr = curr->next;
            }
            printf("\n");
        }
    }
}

void freeGraph(Graph * gh) {
    for (int i = 0;  i < gh->vertices; ++i) {
        NodePtr curr = gh->adjNodes[i];
        while (curr) {
            NodePtr temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(gh->adjNodes);
}

#endif