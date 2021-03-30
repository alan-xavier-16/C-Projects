#include "StudentCard.h"

// CONSTRUCTOR
StudentCard::StudentCard(Student student) : _student_name(student._name)
{
  std::cout << "Student Card issued successfully!" << std::endl;
  std::cout << "Welcome to University: " << _student_name << std::endl;
}

// MEMBER FUNCTIONS
void StudentCard::print()
{
  std::cout << "Student Card issued for: " << _student_name << std::endl;
}