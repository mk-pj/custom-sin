#include "func.h"

double custom_sin(double x, const int term_count, const bool is_deg) {
  if (is_deg)
    x *= M_PI / 180;

  double norm_x = x - _2PI * trunc(x / _2PI);

  if (norm_x < 0)
    norm_x += _2PI;

  bool is_negative = false;

  if (norm_x > THIRD_QUARTER_END) {
    norm_x = _2PI - norm_x;
    is_negative = true;
  } else if (norm_x > SECOND_QUARTER_END) {
    norm_x = norm_x - M_PI;
    is_negative = true;
  } else if (norm_x > FIRST_QUARTER_END) {
    norm_x = M_PI - norm_x;
  }

  double sin_x = 0.0;
  double term = norm_x;

  for (int i = 1, sign = 1; i <= term_count; ++i, sign *= -1) {
    sin_x += sign * term;
    term *= norm_x * norm_x / ((2 * i) * (2 * i + 1));
  }

  if (is_negative)
    sin_x *= -1;

  return sin_x;
}

void rad_comparison(
    const int n,
    const int term_count,
    const double upper_bound,
    const std::string &title
) {
  double x = -upper_bound;
  double step = 2 * upper_bound / (n - 1);
  vector<double> X, Y, Y_calc;

  X.reserve(n);
  Y.reserve(n);
  Y_calc.reserve(n);

  for (int _ = 0; _ < n; ++_) {
    double sin_h = sin(x);
    double cust_sin = custom_sin(x, term_count);
    double error = fabs(sin_h - cust_sin);
    X.push_back(x);
    Y.push_back(sin_h);
    Y_calc.push_back(cust_sin);
    fmt::println("{:=^80}", "");
    fmt::println("{:^10.2f}|{:^20.10f}|{:^25.10f}|{:^30.10f}", x, sin_h, cust_sin, error);
    x += step;
  }

  std::stringstream ss;
  for (int i = 0; i < X.size(); ++i) {
    double error = fabs(Y_calc[i] - Y[i]);
    ss << X[i] << ',' << Y_calc[i] << ',' << Y[i] << ',' << error << '\n';
  }

  std::filesystem::create_directory("../data_output/");
  std::fstream rad("../data_output/" + title, std::ios::out | std::ios::trunc);
  if (!rad) {
    std::cerr << "Failed to write to the file\n";
    return;
  }
  rad << ss.str();
  rad.close();
}

void deg_comparison(
    const int n,
    const int term_count,
    const double upper_bound,
    const std::string &title
) {
  double x = -upper_bound;
  double step = 2 * upper_bound / (n - 1);
  vector<double> X, Y, Y_calc;

  X.reserve(n);
  Y.reserve(n);
  Y_calc.reserve(n);

  for (int _ = 0; _ < n; ++_) {
    double rad = x * M_PI / 180;
    double sin_h = sin(rad);
    double cust_sin = custom_sin(x, term_count, true);
    double error = fabs(sin_h - cust_sin);
    X.push_back(rad);
    Y.push_back(sin_h);
    Y_calc.push_back(cust_sin);
    fmt::println("{:=^80}", "");
    fmt::println("{:^10.0f}|{:^20.10f}|{:^25.10f}|{:^30.10f}", x, sin_h, cust_sin, error);
    x += step;
  }

  std::stringstream ss;
  for (int i = 0; i < X.size(); ++i) {
    double error = fabs(Y_calc[i] - Y[i]);
    ss << X[i] << ',' << Y_calc[i] << ',' << Y[i] << ',' << error << '\n';
  }

  std::filesystem::create_directory("../data_output/");
  std::fstream rad("../data_output/" + title, std::ios::out | std::ios::trunc);
  if (!rad) {
    std::cerr << "Failed to write to the file\n";
    return;
  }
  rad << ss.str();
  rad.close();
}
