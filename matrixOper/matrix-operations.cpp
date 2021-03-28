#include <iostream>
#include <vector>

std::vector<int> createVec()
{
  std::vector<int> v;
  int elem;

  std::cout << "Enter an element for the vector [ (-1) to exit ]: " << std::endl;
  std::cin >> elem;

  while (elem != -1)
  {
    v.push_back(elem);
    std::cin >> elem;
  }

  return v;
}

std::vector<std::vector<int>> createMat(const int &N)
{
  // Initialize Matrix with N rows
  std::vector<std::vector<int>> M(N);
  std::cout << "Enter NxN elements for the matrix [ N = " << N << " ]" << std::endl;

  for (auto row = 0; row < N; row++)
  {
    for (auto col = 0; col < N; col++)
    {
      int elem;
      std::cin >> elem;
      M[row].push_back(elem);
    }
  }

  return M;
}

void printVec(std::vector<int> &v)
{
  std::cout << "[";
  for (const auto elem : v)
  {
    std::cout << " " << elem << " ";
  }
  std::cout << "]" << std::endl;
}

void printMat(std::vector<std::vector<int>> &M)
{
  std::cout << "[" << std::endl;
  for (const auto row : M)
  {
    std::cout << " [";
    for (const auto elem : row)
    {
      std::cout << " " << elem << " ";
    }
    std::cout << "] " << std::endl;
  }
  std::cout << "]" << std::endl;
}

std::vector<int> dotProd(std::vector<std::vector<int>> &M, std::vector<int> &v, const int &N)
{
  std::cout << "Vector m = v * A is:" << std::endl;
  std::vector<int> res(N, 0);

  for (auto row = 0; row < N; row++)
  {
    for (auto col = 0; col < N; col++)
    {
      res[row] += M[row][col] * v[col];
    }
  }

  printVec(res);
  return res;
}

int main()
{
  // Create vector from User Input
  std::vector<int> v = createVec();
  printVec(v);

  const int N = v.size();
  // Create matrix from User Input
  std::vector<std::vector<int>> M = createMat(N);
  printMat(M);

  dotProd(M, v, N);

  return 0;
}