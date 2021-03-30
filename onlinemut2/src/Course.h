#ifndef COURSE_H
#define COURSE_H

#include <string>

enum class CourseType
{
    Lecture,
    Seminar,
    Practical
};

class Course
{
protected:
    std::string _id;
    CourseType _type;

public:
    Course(std::string, CourseType);

    std::string id() const;

    std::string type() const;

    // TODO: Add describe()
    virtual void describe() const = 0;

    // TODO: Declare the destructor as virtual (why?)
    virtual ~Course() = default;
};

#endif // COURSE_Η