#ifndef STUDENTCARD_H
#define STUDENTCARD_Η

#include <iostream>
#include <string>

#include "Student.h"

class StudentCard
{
private:
    std::string _student_name;

public:
    //CONSTRUCTOR
    StudentCard(Student);

    // MEMBER FUNCTIONS
    void print();
};

#endif