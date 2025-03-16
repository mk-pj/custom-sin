#include "func.h"

int main() {
  int n = 1000;
  for (int i = 1; i <= 10; i++) {
    fmt::println("{:^10}|{:^20}|{:^25}|{:^20}|{:^30}",
                    "x", "sin_h", "c_sin", "error", "terms: " + std::to_string(i));
    std::string rad_title{std::to_string(i) + "rad_data.csv"};
    rad_comparison(n, i, 6 * M_PI, rad_title);

    fmt::print("\n{:=^80}\n\n", "");

    fmt::println("{:^10}|{:^20}|{:^25}|{:^20}|{:^30}",
                    "x", "sin_h", "c_sin", "error", "terms: " + std::to_string(i));
    std::string deg_title{std::to_string(i) + "deg_data.csv"};
    deg_comparison(n, i, 1080, deg_title);
    printf("\n");
  }
  return 0;
}
