#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX 10



typedef struct {
    char fname[20];
    char lname[20];
}Name;

typedef struct node {
    Name name;
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

NodePtr createNode(Name name) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->name = name;
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

unsigned long hash(char* fname, char*lname) {
    unsigned long hash = 5381;
    int c;
    while ((c = *lname +((*fname))++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return (int)hash % MAX;
}

bool insertToGraph(NodePtr newNode, Graph* gh) {
    if (!newNode) {
        return false;
    }
    int pos = hash(newNode->name.fname, newNode->name.lname);
    NodePtr curr = gh->adjNodes[pos];
    if (!curr) {
        gh->adjNodes[pos] = newNode;
    } else {
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    gh->vertices++;
    return true;
}


void display(Graph gh) {
    for (int i = 0; i < MAX; ++i) {
        if (gh.adjNodes[i]) {
             NodePtr curr = gh.adjNodes[i];
            while (curr)
            {
                Name name = curr->name;
                printf("%d: %s, %s->",i,name.lname, name.fname);
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