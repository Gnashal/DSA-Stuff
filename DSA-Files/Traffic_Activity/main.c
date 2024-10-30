#include <stdio.h>
#include "traffic.h"
int main()
{
    Heap trafficList;
    initHeap(&trafficList);
    TrafficData trafficDataArray[12];

    trafficDataArray[0] = createData("M", 5);
    trafficDataArray[1] = createData("PM", 10);
    trafficDataArray[2] = createData("ML", 15);
    trafficDataArray[3] = createData("MR", 20);
    trafficDataArray[4] = createData("DL", 25);
    trafficDataArray[5] = createData("DR", 30);
    trafficDataArray[6] = createData("PM", 35);
    trafficDataArray[7] = createData("PD", 40);
    trafficDataArray[8] = createData("M", 50);
    trafficDataArray[9] = createData("D", 60);
    trafficDataArray[10] = createData("PM", 23);
    trafficDataArray[11] = createData("PD", 12);
    trafficDataArray[12] = createData("PR", 6);

    for (int i = 0; i < 12; ++i)
    {
        enqueue(&trafficList, trafficDataArray[i]);
    }
    
    char* filename = writeToFile(&trafficList, "traffic.dat");
    readFile(filename);



    return 0;
}