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
        Student student = createStudent(rand() % 1000, name, i % 2 == 0 ? MALE : FEMALE, i % 4 == 0 ? BSIT : i % 4 == 1 ? BSCS : i % 4 == 2 ? BSIS : BSCE);
        insertSorted(&q, student);
    }
    display(q);

    //   for (int i = 0; i < 10; ++i) {
    //     dequeue(&q);
    // }
    // display(q);

    // Name name1;
    // strcpy(name1.fname, "GORLOCK");
    // strcpy(name1.lname, "BAYOT");
    // Student stud1 = createStudent(1100,name1,MALE, BSCS);

    // insertSorted(&q, stud1);
    // display(q);

    // Name name2;
    // strcpy(name2.fname, "WHAT");
    // strcpy(name2.lname, "THEFUCK");
    // Student stud2 = createStudent(500,name2,FEMALE, BSCE);

    // insertSorted(&q, stud2);
    // display(q);

    

    // String program, sex;
    // printf("\nEnter program: ");
    // scanf("%s", program);
    // printf("\nEnter sex: ");
    // scanf("%s", sex);

    // Name *names = getStudent(q, program, sex);

    // printf("\n-------------------------------------------------------------\n");
    // printf("| %-10s | %-10s |\n", "First Name", "Last Name");
    // printf("-------------------------------------------------------------\n");

    //   for (int i = 0; strcmp(names[i].fname, "") != 0; ++i) {
    //     printf("| %-10s | %-10s |\n", 
    //         names[i].fname,
    //         names[i].lname
    //     );
    // }

    // sort(&q);
    // display(q);

    // free(names);

    return 0;
}
