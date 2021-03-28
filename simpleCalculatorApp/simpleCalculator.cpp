#include <iostream>

/* SUM */
template <typename T>
T sum(T &a, T &b)
{
  std::cout << "Adding: " << a << " + " << b << " = ";
  return a + b;
}

/* SUBTRACT */
template <typename T>
T subtract(T &a, T &b)
{
  std::cout << "Subtracting: " << a << " - " << b << " = ";
  return a - b;
}

/* MULTIPLY */
template <typename T>
T multiply(T &a, T &b)
{
  std::cout << "Multiplying: " << a << " * " << b << " = ";
  return a * b;
}

/* DIVIDE */
template <typename T>
T divide(T &a, T &b)
{
  if (b != 0)
  {
    std::cout << "Dividing: " << a << " / " << b << " = ";
    return a / b;
  }
  else
  {
    std::cout << "b cannot be 0!"
              << " = ";
    return b;
  }
}

/* MEAN */
template <typename T>
T mean(T &a, T &b)
{
  std::cout << "Mean of: " << a << " & " << b << std::endl;
  return sum(a, b) * 0.5;
}

/* MENU */
template <typename T>
void loadMenu(T &a, T &b, unsigned int &option)
{
  while (option != 10)
  {
    std::cout << "A Calculator app!" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "The following operations are provided: " << std::endl;
    std::cout << "(1) Sum (+)" << std::endl;
    std::cout << "(2) Subtract (-)" << std::endl;
    std::cout << "(3) Multiply (*)" << std::endl;
    std::cout << "(4) Divide (/)" << std::endl;
    std::cout << "(5) Mean (:)" << std::endl;
    std::cout << "(10) Exit" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "Enter First Number: " << std::endl;
    std::cin >> a;
    std::cout << "Enter Second Number: " << std::endl;
    std::cin >> b;
    std::cout << "-----------------" << std::endl;
    std::cout << "Please select an operation: " << std::endl;
    std::cin >> option;
    std::cout << "-----------------" << std::endl;

    switch (option)
    {
    case 1:
      std::cout << sum(a, b) << std::endl;
      break;
    case 2:
      std::cout << subtract(a, b) << std::endl;
      break;
    case 3:
      std::cout << multiply(a, b) << std::endl;
      break;
    case 4:
      std::cout << divide(a, b) << std::endl;
      break;
    case 5:
      std::cout << mean(a, b) << std::endl;
      break;
    case 10:
      std::cout << "Exiting..." << std::endl;
      break;
    default:
      std::cout << "Incorrect selection, please try again." << std::endl;
      break;
    }
  }
}

int main()
{
  unsigned int option = 0;
  double a = 0, b = 0;

  loadMenu(a, b, option);

  return 0;
}