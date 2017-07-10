#include <iostream>



int fib_seq(int n)
{
    int a=0,b=1,c;
    for(int i=0; i<n;i++)
    {
      c=a+b;
      a=b;
      b=c;
    }
    return a;
}


int fib_req(int n)
{
  if(2 > n)
  {
    return n;
  }
  else
  {
    return(fib_req(n-1) + fib_req(n-2));
  }
}


int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::cout << fib_seq(n) << " :: " << fib_req(n) << std::endl;
  return 0;
}
