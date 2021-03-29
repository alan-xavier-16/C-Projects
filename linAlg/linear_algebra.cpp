#include <iostream>
#include <vector>
#include <cassert>

/* PRINT VECTOR */
template <typename T>
void printVec(std::vector<T> &v)
{
  std::cout << "[";
  for (const auto &elem : v)
  {
    std::cout << " " << elem << " ";
  }
  std::cout << "]" << std::endl;
}

/* PRINT MATRIX */
template <typename T>
void printMat(std::vector<std::vector<T>> &M)
{
  std::cout << "[" << std::endl;
  for (const auto &row : M)
  {
    printVec(row);
  }
  std::cout << "]" << std::endl;
}

/* VECTOR-MATRIX or MATRIX-VECTOR PRODUCT */
template <typename T>
std::vector<T> vecMatProd(std::vector<std::vector<T>> &M, std::vector<T> &v, const int &N)
{
  std::cout << "Select operation" << std::endl;
  std::cout << "(0) Vector-Matrix: m = vT * A" << std::endl;
  std::cout << "(1) Matrix-Vector: m = A * v" << std::endl;
  int option;
  std::cin >> option;

  std::vector<T> res(N, 0);

  for (auto row = 0; row < N; row++)
  {
    for (auto col = 0; col < N; col++)
    {
      (option == 0) ? res[row] += M[row][col] * v[col] : res[col] += M[row][col] * v[col];
    }
  }

  printVec(res);
  return res;
}

int main()
{
  return 0;
}