#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    // Create a person list with a maximum size of 10
    PersonList voters = createPersonList(10);

    // Create some sample people
    Address addr1 = createAddress("New York", 10001);
    Address addr2 = createAddress("Los Angeles", 90001);
    Address addr3 = createAddress("Chicago", 60001);
    Address addr4 = createAddress("New York", 10002);
    Address addr5 = createAddress("Houston", 77001);

    Person p1 = createPerson(1, "John Doe", addr1);
    Person p2 = createPerson(2, "Jane Smith", addr2);
    Person p3 = createPerson(3, "Sam Johnson", addr3);
    Person p4 = createPerson(4, "Emily Davis", addr4);
    Person p5 = createPerson(5, "Michael Brown", addr5);

    // Add persons to the list
    addPerson(&voters, p1);
    addPerson(&voters, p2);
    addPerson(&voters, p3);
    addPerson(&voters, p4);
    addPerson(&voters, p5);

    // Printing all Person List
    for (int i = 0; i < voters.count; ++i)
    {
        printf("ID: %d \nName: %s \nCity: %s \nZip: %d\n\n", voters.personList[i].id, voters.personList[i].name, voters.personList[i].address.city, voters.personList[i].address.zip);
    }

    // Initialize the stack
    StackList voterStack;
    initStack(&voterStack);

    // Get voters from "New York"
    getVoters(voters, "New York", &voterStack);

    // Print the voters from the stack
    printf("\nExtracteed Voters from the Array List: \n\n");
    while (!isEmpty(voterStack))
    {
        Person p = peek(voterStack);
        printf("ID: %d \nName: %s \nCity: %s \nZip: %d\n\n", p.id, p.name, p.address.city, p.address.zip);
        pop(&voterStack);
    }

    // Free the person list
    free(voters.personList);

    return 0;
}