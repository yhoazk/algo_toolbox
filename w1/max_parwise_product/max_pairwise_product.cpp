#include <iostream>
#include <vector>

using namespace std;

/* This solution fails in the case:
2
100000 90000
Returns:
1410065408

Also the time complexity is O(n^2) too slow
 */
int maxPairwiseProduct(const std::vector<int>& numbers)
{
  int result = 0;
  int n = numbers.size();

  for(int i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < n; j++)
    {
      if(numbers[i] * numbers[j] > result)
      {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return(result);
}



int main()
{
  int n;
  cin >> n;
  vector<int> numbers(n);

  for (size_t i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }
  int result = maxPairwiseProduct(numbers);
  cout << result << endl;
  return 0;
}
