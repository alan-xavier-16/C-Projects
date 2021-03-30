#include <iostream>
#include "Course.h"

// CONSTRUCTOR
Course::Course(std::string id, CourseType type) : _id(id), _type(type)
{
  std::cout << "Course created successfully!" << std::endl;
  std::cout << "> Course ID: " << _id << std::endl;
}

// MEMBER FUNCTIONS
std::string Course::get_id() const
{
  return _id;
}