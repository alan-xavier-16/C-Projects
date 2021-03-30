#include <iostream>
#include <string>

#include "Practical.h"

// TODO: Implement constructor and describe()
Practical::Practical(std::string id, std::size_t num_worksheets)
    : Course(id, CourseType::Practical),
      _num_worksheets(num_worksheets)
{
  std::cout << "Constructing the practical " << _id << std::endl;
}

void Practical::describe() const
{
  std::cout << "Number of Worksheets: " << _num_worksheets << std::endl;
}