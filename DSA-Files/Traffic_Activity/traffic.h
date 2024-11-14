#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum
{
    M = 1,
    D,
    ML,
    DL,
    MR,
    DR,
    PM, 
    PD

} Description;

typedef struct
{
    Description desc;
    int prio;
    int time;
} TrafficData;

typedef struct
{
    TrafficData data[20];
    int count;
} Heap;

Description determine(const char *desc)
{
    if (strcmp(desc, "M") == 0)
        return M;
    if (strcmp(desc, "D") == 0)
        return D;
    if (strcmp(desc, "ML") == 0)
        return ML;
    if (strcmp(desc, "MR") == 0)
        return MR;
    if (strcmp(desc, "DL") == 0)
        return DL;
    if (strcmp(desc, "DR") == 0)
        return DR;
    if (strcmp(desc, "PM") == 0)
        return PM;
    if (strcmp(desc, "PD") == 0)
        return PD;
}
const char *convertEnum(Description desc)
{
    switch (desc)
    {
    case M:
        return "M";
    case D:
        return "D";
    case ML:
        return "ML";
    case MR:
        return "MR";
    case DL:
        return "DL";
    case DR:
        return "DR";
    case PM:
        return "PM";
    case PD:
        return "PD";
    default:
        return "Unknown";
    }
}
TrafficData createData(char *desc, int time)
{
    TrafficData td;
    td.desc = determine(desc);
    td.prio = td.desc;
    td.time = time;
    return td;
}
void initHeap(Heap *h)
{
    h->count = 0;
}

bool enqueue(Heap *hp, TrafficData td)
{
    if (hp->count >= 20)
        return false;
    int curr = hp->count;
    int parent;
    while (curr > 0 && td.prio < hp->data[(curr - 1) / 2].prio)
    {
        parent = (curr - 1) / 2;
        hp->data[curr] = hp->data[parent];
        curr = parent;
    }
    hp->data[curr] = td;
    hp->count++;
    return true;
}
TrafficData dequeue(Heap *hp)
{
    TrafficData last;
    if (hp->count == 0)
    {
        last = createData(0, 0);
        return last;
    }
    last = hp->data[hp->count - 1];
    (hp->count)--;
    int index = 0, lesser;
    while (index < hp->count)
    {
        int left = (2 * index) + 1;
        if (left >= hp->count)
            break;
        if (left + 1 < hp->count && hp->data[left + 1].prio < hp->data[left].prio)
        {
            lesser = left + 1;
        }
        else
        {
            lesser = left;
        }
        if (last.prio <= hp->data[lesser].prio)
        {
            break;
        }
        hp->data[index] = hp->data[lesser];
        index = lesser;
    }
    hp->data[index] = last;
    return last;
}

void displayData(TrafficData td)
{
    printf("%15s - %d - %d\n", convertEnum(td.desc), td.time, td.prio);
}
void displayAllData(Heap *trafficList)
{
    printf("_________________________\n");
    for (int i = 0; i < trafficList->count; ++i)
    {
        displayData(trafficList->data[i]);
    }
    printf("_________________________\n");
}

char * writeToFile(const Heap * hp, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if(!file) {
        perror("Error opening file");
        return NULL;
    }
    fwrite(&hp->count, sizeof(int), 1 , file);
        for (int i = 0; i < hp->count; i++)
        {
            fwrite(&hp->data[i], sizeof(TrafficData), 1, file);
        }

        fclose(file);
        return (char*)filename;
}



int readFile (const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error reading file");
        return EXIT_FAILURE; 
    }

    Heap tempHeap;
    initHeap(&tempHeap);

    fread(&tempHeap.count, sizeof(int), 1 ,file);

    for (int i = 0; i < tempHeap.count; ++i) {
        TrafficData tempData;
        if (fread(&tempData, sizeof(TrafficData), 1, file) == 1) {
            tempHeap.data[i] =  tempData;
        } else {
            fclose(file);
            return EXIT_FAILURE;
        }
    }
    fclose(file);
    displayAllData(&tempHeap);
    return EXIT_SUCCESS;
}

int findTotalTime(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file ) {
        return EXIT_FAILURE;
    }

    

    Heap tempHeap;
    initHeap(&tempHeap);
    fread(&tempHeap.count, sizeof(int), 1, file);
    for (int i = 0; i < tempHeap.count;++i) {
        TrafficData tempData;
        if (fread(&tempData, sizeof(TrafficData), 1, file) == 1) {
            tempHeap.data[i] = tempData;
        }else {
            fclose(file);
            return EXIT_FAILURE;
        }
    }
    fclose(file);

    int totalTime = 0;
    int i = 0;
    while (i < tempHeap.count && tempHeap.data[i].desc < PM) {
        TrafficData td = tempHeap.data[i];
        totalTime += td.time;
        ++i;
        dequeue(&tempHeap);
    }
    return totalTime;
}

#endif