#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

// CONSTRUCTOR
Student::Student(std::string name, std::string reg_num) : _name(name), _reg_num(reg_num) {}

// MEMBER FUNCTIONS
void Student::register_for(Course course)
{
  _courses.push_back(course);
  std::cout << "Successfully registered for: " << course.get_id() << std::endl;
}

void Student::list_courses()
{
  std::cout << "Student " << _name << " has registered for: " << std::endl;
  for (const auto &course : _courses)
  {
    std::cout << "> " << course.get_id() << std::endl;
  }
}