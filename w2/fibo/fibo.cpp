#include <iostream>


// Here as we are precharging a and b the state goes 1 step ahead
// that is why we are returning a instead of C, A stores the last
// state at the end of the for cycle
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


/* Helper function to find the Pisano sequence for the exercise 5 */

long long fib_mod(long long n, long long m){
  long long a=0,b=1,c=0;

    std::cout << "F: " << a << " m: " << a % m << '\n';
    std::cout << "F: " << b << " m: " << b % m << '\n';
  for(long long i = 0; i < n; i++){
    c = a + b;
    a=b; b=c;
    std::cout << "i:" << i << " F: " << c << " m: " << c%m  << '\n';
  }
}



int main(int argc, char const *argv[]) {
    long long  n, m;
    std::cin >> n >> m;
    //std::cout << fib_seq(n) << " :: " << fib_req(n) << std::endl;
    std::cout << fib_mod(n, m) << std::endl;

  return 0;
}
