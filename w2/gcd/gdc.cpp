#include <iostream>

size_t naive_gdc(size_t a, size_t b){
  auto m = a + b;
  size_t gdc = 0;

  for(int i = 1; i < m; ++i){
    if(((a%i) == 0) && ((b%i) == 0)){
      gdc = i;
    }
  }
  return gdc;
}


/* recursive GDC applying the Euclidean Algorithm */
size_t fast_gdc(size_t a, size_t b){
  if(b == 0){
    return a;
  } else {
    fast_gdc(b, a%b);
  }
}


int main(int argc, char const *argv[]) {
  std::cout << "Start" << std::endl;
  std::cout << naive_gdc(73918848,61653264) << "\n";
  std::cout << "Done" << std::endl;
  std::cout << fast_gdc(18,35) << "\n";
  std::cout << fast_gdc(28851538,1183019) << "\n";
  std::cout << fast_gdc(1386,1176) << "\n";
  return 0;
}
