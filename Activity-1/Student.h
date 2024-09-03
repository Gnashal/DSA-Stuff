#ifndef STUDENT_H
#define STUDENT_H


#include <string.h>
typedef char String[20];

typedef struct 
{
    String fname;
    String lname;
} Name;

typedef enum {
    FEMALE, MALE
}Sex;

typedef enum {
    BSIT, BSCS, BSIS, BSCE
} Program;

typedef struct 
{
    int studID;
    Name studName;
    Sex sex;
    Program program;

} Student;

Name createName(String fname, String lname) {
    Name newName;
    strcpy(newName.fname, fname);
    strcpy(newName.lname, lname);
    return newName;
}

Student createStudent(int id, Name name, Sex sex, Program program) {
    Student s;
    s.studID = id;
    s.studName = name;
    s.sex = sex;
    s.program = program;

    return s;
}

const char* getSexString(Sex sex) {
    switch (sex) {
        case MALE: return "Male";
        case FEMALE: return "Female";
        default: return "Unknown";
    }
}

const char* getProgramString(Program program) {
    switch (program) {
        case BSIT: return "BSIT";
        case BSCS: return "BSCS";
        case BSIS: return "BSIS";
        case BSCE: return "BSCE";
        default: return "Unknown";
    }
}



#endif