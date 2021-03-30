#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Course.h"

class Student
{
private:
    std::string _name;
    const std::string _reg_num;
    std::vector<Course> _courses;

    // FRIEND - StudentCard needs access to Student members
    friend class StudentCard;

public:
    // CONSTRUCTOR
    Student(std::string, std::string);

    // MEMBER FUNCTIONS
    void register_for(Course);

    void list_courses();
};

#endif // STUDENT_H