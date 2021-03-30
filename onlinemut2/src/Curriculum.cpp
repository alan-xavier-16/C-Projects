#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Course.h"
#include "Curriculum.h"
#include "Lecture.h"
#include "Practical.h"

// TODO: Implement the constructor
Curriculum::Curriculum()
{
  _available_courses.push_back(std::make_unique<Lecture>("IN1085", "22-03-2021"));
  _available_courses.push_back(std::make_unique<Practical>("PR1016", 8));

  std::cout << "University now offers: " << std::endl;
  print_courses();
}

// TODO: Implement print_courses()
void Curriculum::print_courses()
{
  std::cout << "Available Courses (ID, Type): " << std::endl;
  for (const auto &course : _available_courses)
  {
    std::cout
        << course->id() << ", "
        << course->type() << ", "
        << std::endl;
  }
}

// TODO: Implement request(std::string id)
const Course *Curriculum::request(std::string id) const
{
  for (const auto &course : _available_courses)
  {
    if (course->id() == id)
    {
      return course.get();
    }
  }
  // Course not found, throw an exception which should be handled outside
  throw(std::runtime_error("Course with id " + id + " not found in available courses."));
}