#include <iostream>
#include <vector>

using namespace std;


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
