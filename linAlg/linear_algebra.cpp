#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

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

/* OPERATOR OVERLOADING (+) */
template <typename T>
std::vector<T> operator+(const std::vector<T> &v_a, const std::vector<T> &v_b)
{
  // Require vectors to be added MUST have same dimensions
  assert(v_a.size() == v_b.size());

  std::vector<T> v_sum(v_a.size());
  for (auto i = 0; i < v_a.size(); i++)
  {
    v_sum[i] = v_a[i] + v_b[i];
  }
  return v_sum;
}

/* OPERATOR OVERLOADING (*) - MATRIX-VECTOR */
template <typename T>
std::vector<T> operator*(const std::vector<std::vector<T>> &M, const std::vector<T> &v)
{
  unsigned int N = v.size();
  // Require matrix-rows and vector to be multiplied MUST have same dimensions
  assert(M[0].size() == N);

  std::vector<T> res(N);
  for (auto row = 0; row < N; row++)
  {
    for (auto col = 0; col < N; col++)
    {
      res[row] += v[row] * M[row][col];
    }
  }
  return res;
}

/* TEST FUNCTION FOR OPERATOR OVERLOADING (*) - MATRIX-VECTOR */
void test_matrix_vector_product()
{
  bool tests_passed = true;

  std::vector<std::vector<double>> M{{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  std::vector<double> v{1.0, 1.0, 1.0};
  std::vector<double> mat_vec = M * v;      // Result of Operation
  std::vector<double> ref{6.0, 15.0, 24.0}; // Reference Solution

  // Test based on a certain tolerance
  double tol = 1e-8;
  for (auto i = 0; i < ref.size(); i++)
  {
    // Check each element is within tolerance
    if (std::abs(mat_vec.at(i) - ref.at(i)) > tol)
    {
      tests_passed = false;
    }
  }

  if (tests_passed)
  {
    std::cout << "Tests passed!" << std::endl;
  }
  else
  {
    std::cout << "Tests failed!" << std::endl;
    std::cout << "Reference Solution: " << std::endl;
    printVec(ref);
    std::cout << "Computed Solution: " << std::endl;
    printVec(mat_vec);
  }
}

int main()
{
  std::vector<std::vector<double>> matrix = {{1., 0., 0.},
                                             {0., 1., 0.},
                                             {0., 0., 1.}};

  std::vector<double> vec_a = {1., 2., 3.};
  std::vector<double> vec_b = {4., 5., 6.};

  // adding two vectors
  auto vec_sum = vec_a + vec_b;
  printVec(vec_sum);

  test_matrix_vector_product();

  return 0;
}