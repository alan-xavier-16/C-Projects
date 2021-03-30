#ifndef COURSE_H
#define COURSE_H

#include <string>

enum class CourseType
{
    Lecture,
    Seminar,
    Practical,
};

class Course
{
private:
    std::string _id;
    CourseType _type;

public:
    // CONSTRUCTOR
    Course(std::string, CourseType);

    // MEMBER FUNCTIONS
    std::string get_id() const;
};

#endif // COURSE_Η