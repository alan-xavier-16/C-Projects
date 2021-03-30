#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Curriculum.h"

Student::Student(std::string name, std::string id, const std::unique_ptr<Curriculum> &study_program)
    : _name(name), _registration_num(id), _study_program(study_program.get())
{
    std::cout << "Hi! My name is " << _name
              << " and my registration number is "
              << _registration_num << "." << std::endl;
}

void Student::register_for(std::string id)
{
    try
    {
        // Try requesting the course from the curriculum and add it to the list
        _courses.push_back(_study_program->request(id));
        std::cout << "Registered for: "
                  << id
                  << " successfully!" << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cout << "It looks like the program coordinators did not like your request:" << std::endl;
        std::cout << e.what() << std::endl;
    }
}

void Student::list_courses()
{
    std::cout << _name << " is taking these courses this semester: ";
    for (const auto &course : _courses)
    {
        // TODO: course will now be a pointer, so you also need to dereference it (using ->)
        std::cout << course->id() << " ";
    }
    std::cout << std::endl;
}