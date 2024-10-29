#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    PM = 1, PD, M, D, ML ,DL, MR, DR
} Description;

typedef struct 
{
    Description desc;
    int prio;
    int time;
} TrafficData;

typedef struct {
    TrafficData data[20];
    int count;
}Heap;

Description determine(const char *desc) {
    if (strcmp(desc, "M") == 0) return M;
    if (strcmp(desc, "D") == 0) return D;
    if (strcmp(desc, "ML") == 0) return ML;
    if (strcmp(desc, "MR") == 0) return MR;
    if (strcmp(desc, "DL") == 0) return DL;
    if (strcmp(desc, "DR") == 0) return DR;
    if (strcmp(desc, "PM") == 0) return PM;
    if (strcmp(desc, "PD") == 0) return PD;

    // // Handle unrecognized description
    // fprintf(stderr, "Unrecognized description: %s\n", desc);
    // exit(EXIT_FAILURE);  // Or return a default value
}
const char* convertEnum(Description desc) {
    switch (desc) {
        case M: return "M";
        case D: return "D";
        case ML: return "ML";
        case MR: return "MR";
        case DL: return "DL";
        case DR: return "DR";
        case PM: return "PM";
        case PD: return "PD";
        default: return "Unknown";
    }
}
TrafficData createData (char*desc, int time) {
    TrafficData td;
    td.desc = determine(desc);
    td.prio = td.desc;
    td.time = time;
    return td;
}
void initHeap(Heap* h){
    h->count = 0;
}

bool enqueue(Heap* hp, TrafficData td) {
    if (hp->count >= 20) return false;
    int curr = hp->count;
    int parent;
    while (curr > 0 && td.prio < hp->data[(curr - 1) / 2].prio) {
        parent = (curr - 1) / 2;
        hp->data[curr] = hp->data[parent];
        curr = parent;
    }
    hp->data[curr] = td;
    hp->count++;
    return true;
}



void displayData(TrafficData td) {
    printf("%15s - %d - %d\n", convertEnum(td.desc), td.time, td.prio);
}

#endif