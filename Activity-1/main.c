#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "Student.h"
#include "Queue.h"

int main() {    
    Queue q = createQueue();

    String firstNames[10] = {"Yousif", "Gran", "Godwin", "Voltaire", "Clarence", "Paul", "John", "Mark", "Charles", "Quirico"};
    String lastNames[10] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez"};

    for (int i = 0; i < 10; ++i) {
        Name name = createName(firstNames[i], lastNames[i]);
        Student student = createStudent(i + 100, name, i % 2 == 0 ? MALE : FEMALE, i % 4 == 0 ? BSIT : i % 4 == 1 ? BSCS : i % 4 == 2 ? BSIS : BSCE);
        enqueue(&q, student);
    }
    display(q);

    String program, sex;
    printf("\nEnter program: ");
    scanf("%s", program);
    printf("\nEnter sex: ");
    scanf("%s", sex);

    Name *names = getStudent(q, program, sex);

    printf("\n-------------------------------------------------------------\n");
    printf("| %-10s | %-10s |\n", "First Name", "Last Name");
    printf("-------------------------------------------------------------\n");

      for (int i = 0; strcmp(names[i].fname, "") != 0; ++i) {
        printf("| %-10s | %-10s |\n", 
            names[i].fname,
            names[i].lname
        );
    }

    free(names);

    return 0;
}
