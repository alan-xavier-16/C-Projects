#include <iostream>

#include "Student.h"
#include "Course.h"
#include "StudentCard.h"
#include "Curriculum.h"

void describe_course(const Course *course)
{
    // TODO: Implement (call the describe() of the course)
    std::cout << "Course ID: " << course->id() << std::endl;
    std::cout << "Course Type: " << course->type() << std::endl;
    course->describe();
}

int main()
{

    // When we create a university, we first create study programs.
    // Each study program defines its own courses internally.
    std::unique_ptr<Curriculum> CSE = std::make_unique<Curriculum>();

    // After we have study programs, we can enroll students.
    // Students only make sense if they also have a study program.
    // The students don't own the study programs or the courses,
    // they only "observe" them.
    Student Eve("Eve", "12345", CSE);

    // For every student, we can issue a student card.
    StudentCard eves_card(Eve);
    eves_card.print();

    // Eve wants to register for a course. But first, checks which courses
    // are available. Afterwards, she lists her courses.
    CSE->print_courses();
    describe_course(CSE->request("IN1503"));
    Eve.register_for("IN1503");
    Eve.list_courses();

    // Eve now wants a course that is not offered. What happens?
    Eve.register_for("Magic4dummies");
    Eve.list_courses();
}