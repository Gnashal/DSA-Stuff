#include <stdio.h>
#include "functions.h"

void freePerson(Person *p)
{
    free(p->name);
    free(p->add.city);
}

void freeDict(PersonOpenDict *dict)
{
    // Free the dictionary entries if needed
    for (int i = 0; i < SIZE; ++i)
    {
        freePerson(&(dict->list[i]->p));
    }
}

int main()
{
    // person list with a maximum size of 20
    PersonList voters = createPersonList(20);

    Address addresses[] = {
        createAddress("New York", 10001),
        createAddress("Los Angeles", 90001),
        createAddress("Chicago", 60001),
        createAddress("Houston", 77001),
        createAddress("Phoenix", 85001),
        createAddress("Philadelphia", 19101),
        createAddress("San Antonio", 78201),
        createAddress("San Diego", 92101),
        createAddress("Dallas", 75201),
        createAddress("San Jose", 95101),
        createAddress("New York", 10001),    // Duplicate city
        createAddress("New York", 10002),    // Different zip but same city
        createAddress("Los Angeles", 90001), // Duplicate city
        createAddress("Chicago", 60002),     // Different zip, same city
        createAddress("Houston", 77002),     // Different zip, same city
        createAddress("New York", 10003)     // Another entry for New York
    };

    Person people[] = {
        createPerson(1, "John Doe", addresses[0]),
        createPerson(2, "Jane Smith", addresses[1]),
        createPerson(3, "Sam Johnson", addresses[2]),
        createPerson(4, "Emily Davis", addresses[3]),
        createPerson(5, "Michael Brown", addresses[4]),
        createPerson(6, "Sarah Lee", addresses[5]),
        createPerson(7, "David Kim", addresses[6]),
        createPerson(8, "James Miller", addresses[7]),
        createPerson(9, "Robert Wilson", addresses[8]),
        createPerson(10, "Lisa Clark", addresses[9]),
        createPerson(11, "John Doe", addresses[10]),    // Duplicate person name, different address
        createPerson(12, "Emily Davis", addresses[11]), // Same name as earlier, different address
        createPerson(13, "Laura Adams", addresses[12]),
        createPerson(14, "Sam Johnson", addresses[13]),  // Same name, different zip
        createPerson(15, "Jane Smith", addresses[14]),   // Same name, different zip
        createPerson(16, "Michael Brown", addresses[15]) // Another person in New York
    };

    // Add persons to the list
    for (int i = 0; i < 16; ++i)
    {
        addPerson(&voters, people[i]);
    }

    // Displaying all persons in list
    printf("All Persons:\n");
    for (int i = 0; i < voters.count; ++i)
    {
        printf("ID: %d \nName: %s \nCity: %s \nZip: %d\n\n", voters.personList[i].id, voters.personList[i].name, voters.personList[i].add.city, voters.personList[i].add.zip);
    }

    PersonOpenDict dict = {0}; // All entries set to NULL
    dict.count = 0;

    // Insert persons into the dictionary
    for (int i = 0; i < 16; ++i)
    {
        insert(&dict, people[i]);
    }

    // Retrieve names of people from "New York"
    String *names = getNames(dict, "New York");

    // Print the names of people from New York
    printf("People from New York:\n");
    for (int i = 0; names[i][0] != '\0'; ++i)
    {
        printf("%s\n\n", names[i]);
    }

    // Free the allocated memory
    free(names);
    for (int i = 0; i < 20; ++i)
    {
        freePerson(&voters.personList[i]);
    }
    freeDict(&dict);

    return 0;
}