#include <cstdlib>
#include <iostream>
#include <vector>


using std::vector;
using std::cin;
using std::cout;
using std::endl;

long long maxPairwiseProduct(const vector<int>& numbers)
{
  long long result = 0;
  int n = numbers.size();

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = i+1; j < n; j++)
    {
      if(((long long)(numbers[i])) * numbers[j] > result)
      {
        result = ((long long) numbers[i]) * numbers[j];
      }
    }
  }
  return result;
}

long long maxPairwiseProductFast(const vector<int>& numbers)
{
  int n = numbers.size();
  long long max_Val_1 = -1;
  long long max_Val_2 = -1;


  for (size_t i = 0; i < n; i++)
  {
    if(numbers[i] > max_Val_2)
    {
      max_Val_2 = numbers[i];
      if(max_Val_2 > max_Val_1)
      {
        /*swap */
        max_Val_1 ^= max_Val_2;
        max_Val_2 ^= max_Val_1;
        max_Val_1 ^= max_Val_2;

      }
    }
  }

  std::cout << max_Val_1 << std::endl;
  std::cout << max_Val_2 << std::endl;
  return (max_Val_1 * max_Val_2);
}


int main(int argc, char const *argv[])
{
  //return maxPairwiseProductFast({1,2,3,4,5,6,7,7,7,5});
  while (true)
  {
    int n = rand() % 10000 + 2;
    cout << n << "\n";
    std::vector<int> a;
    for (size_t i = 0; i < n; i++) {
      a.push_back(rand() % 100000);
    }
    for (size_t i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    cout << "\n";
    long long res1 = maxPairwiseProduct(a);
    long long res2 = maxPairwiseProductFast(a);

    if(res1 != res2)
    {
      cout << "wrong aswer: " << res1 << ' ' << res2 << '\n';
      break;
    }
    else
    {
      cout << "ok\n";
    }
  }
  int n;
  cin >> n;
  std::vector<int> numbers(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }
  long long result = maxPairwiseProductFast(numbers);
  std::cout << result << std::endl;
  return 0;
}
