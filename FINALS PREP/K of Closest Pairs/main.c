#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    Point p1;
    Point p2;
    double distance;
} Pairs;

int compare(const void *a, const void *b)
{
    Pairs *pA = (Pairs *)a;
    Pairs *pB = (Pairs *)b;

    if (pA->distance < pB->distance)
    {
        return -1;
    }
    else if (pA->distance > pB->distance)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    Point points[n];
    Pairs pairs[n * (n - 1) / 2];
    int pairCount = 0;
    for (int i = 0; i < n; ++i)
    {
        Point p;
        printf("Enter x and y of point %d: ", i + 1);
        scanf("%d %d", &p.x, &p.y);
        points[i] = p;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            double distance = sqrt(((points[j].x - points[i].x), 2) + pow((points[j].y - points[i].y), 2));
            pairs[pairCount].p1 = points[i];
            pairs[pairCount].p2 = points[j];
            pairs[pairCount].distance = distance;
            pairCount++;
        }
    }
    qsort(pairs, pairCount, sizeof(Pairs), compare);
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        printf("((%d, %d), (%d, %d))\n", pairs[i].p1.x, pairs[i].p1.y, pairs[i].p2.x, pairs[i].p2.y);
    }
    return 0;
}