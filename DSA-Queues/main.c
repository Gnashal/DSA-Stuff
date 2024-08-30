#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.c"
int main () {
    Queue q = createQueue(10);

    for (int i = 0; i < q.max; ++i) {
        enqueue(&q, i + 1);
    }

    display(&q);



    return 0;
}