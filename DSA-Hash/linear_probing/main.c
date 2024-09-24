#include <stdio.h>
#include "hash.h"

int main() {
    HashTable ht = createHashTable(10);


    Student students[] = {
        createStudents("Computer Science", "Alice", 1001),
        createStudents("Computer Science", "Alisha", 1008),
        createStudents("Computer Science", "Alivine", 1003),
        createStudents("Engineering", "David", 1004),
        createStudents("Biology", "Eva", 1005),
        createStudents("Chemistry", "Frank", 1006),
        createStudents("Mathematics", "Grace", 1007),
        createStudents("Computer Science", "Hannah", 1008),
        createStudents("Physics", "Ian", 1009),
        createStudents("Engineering", "Jack", 1010),
        createStudents("Biology", "Kathy", 1011),
        createStudents("Chemistry", "Leo", 1012),
        createStudents("Mathematics", "Mona", 1013),
        createStudents("Computer Science", "Nina", 1014),
        createStudents("Physics", "Oscar", 1015),
        createStudents("Engineering", "Pam", 1016),
        createStudents("Biology", "Quinn", 1017),
        createStudents("Chemistry", "Rick", 1018),
        createStudents("Mathematics", "Sophie", 1019),
        createStudents("Computer Science", "Tom", 1020),
        createStudents("Engineering", "Uma", 1021)
    };


    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        insert(&ht, students[i]);
    }


    visualize(ht);

    free(ht.elems);
    return 0;
}
