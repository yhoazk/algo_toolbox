#include <iostream>

int fact_req(int n)
{
  if (n == 0) {
    return 1;
  }
  else
  {
    return (n * fact_req(n-1));
  }
}


int fact_seq(int n)
{
  int r = 1;
  for (size_t i = 1; i <= n; i++) {
    r*=i;
  }
  return r;
}

int main(int argc, char const *argv[]) {
  /* code */
  int n;
  std::cin >> n;
  std::cout << fact_req(n) << " :: " << fact_seq(n) << std::endl;
  return 0;
}
