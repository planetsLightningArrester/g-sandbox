#include "sum/sum.hpp"

int main (int argc, char const *argv[]) {
  
  try {
    std::cout << sum(argc - 1, argv + 1) << std::endl;
  } catch (MissingArgument mce) {
    std::cout << std::endl << "[ERROR] Caught MissingArgument" << std::endl;
    std::cout << mce.what() << std::endl << std::endl;
  } catch (ArgumentIsNotANumber mce) {
    std::cout << std::endl << "[ERROR] Caught ArgumentIsNotANumber" << std::endl;
    std::cout << mce.what() << std::endl << std::endl;
  }

  return 0;

}
