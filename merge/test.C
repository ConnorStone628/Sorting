#include "merge.hh"
#include <vector>
#include <iostream>

int main(){

  std::vector<double> X;

  for (int i = 10; i >= 0; --i){
    X.push_back(i);
  }

  for (int i = 0; i < X.size(); ++i){
    std::cout << X[i] << ", ";
  }
  std::cout << std::endl;

  merge<double> M(&X);

  M.Sort();

  for (int i = 0; i < X.size(); ++i){
    std::cout << X[i] << ", ";
  }
  std::cout << std::endl;
  
  
  return 0;
}
