#ifndef FRACTION_H_
#define FRACTION_H_
#include <numeric>
#include <stdexcept>
// A fraction with a numerator and a denominator.
// Both the numerator and denominator should be int,
// and denominator should NOT be 0.
// Reduction to lowest terms will be performed automatically.
class Fraction {
  Fraction friend operator+(const Fraction&, const Fraction&);
  Fraction friend operator-(const Fraction&, const Fraction&);
  Fraction friend operator*(const Fraction&, const Fraction&);
  Fraction friend operator/(const Fraction&, const Fraction&);

  bool friend operator<(const Fraction&, const Fraction&);
  bool friend operator>(const Fraction&, const Fraction&);
  bool friend operator<=(const Fraction&, const Fraction&);
  bool friend operator>=(const Fraction&, const Fraction&);
  bool friend operator==(const Fraction&, const Fraction&);
  bool friend operator!=(const Fraction&, const Fraction&);

 private:
  int numerator_;
  int denominator_;
  // simplify the fraction to lowest terms
  void toLowest();

 public:
  // Both the numerator and denominator should be int,
  // A denominator of 0 will be converted to 1.
  Fraction(int numerator, int denominator);

  operator double() const { return 1.0 * numerator_ / denominator_; }
};

Fraction::Fraction(int numerator, int denominator)
    : numerator_(numerator), denominator_(denominator) {
  // invalid denominator, throw error
  if (denominator_ == 0) {
    throw std::invalid_argument(
        "The denominator for class \"Fraction\" cannot be 0.");
  }
  toLowest();
}

void Fraction::toLowest() {
  int gcdn = std::gcd(numerator_, denominator_);
  numerator_ /= gcdn;
  denominator_ /= gcdn;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
  Fraction ret(
      lhs.numerator_ * rhs.denominator_ + rhs.numerator_ * lhs.denominator_,
      lhs.denominator_ * rhs.denominator_);
  ret.toLowest();
  return ret;
}
Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
  Fraction ret(
      lhs.numerator_ * rhs.denominator_ - rhs.numerator_ * lhs.denominator_,
      lhs.denominator_ * rhs.denominator_);
  ret.toLowest();
  return ret;
}
Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
  Fraction ret(lhs.numerator_ * rhs.numerator_,
               lhs.denominator_ * rhs.denominator_);
  ret.toLowest();
  return ret;
}

// the rhs of fraction cannot be 0.
Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
  if (rhs.numerator_ == 0)
    throw std::invalid_argument(
        "The rhs of \"operator/\" for the class \"Fraction\" cannot be 0.");
  Fraction ret(lhs.numerator_ * rhs.denominator_,
               lhs.denominator_ * rhs.numerator_);
  ret.toLowest();
  return ret;
}

bool operator<(const Fraction& lhs, const Fraction& rhs) {
  return (lhs - rhs).numerator_ < 0;
}

bool operator>(const Fraction& lhs, const Fraction& rhs) {
  return (lhs - rhs).numerator_ > 0;
}

bool operator<=(const Fraction& lhs, const Fraction& rhs) {
  return (lhs - rhs).numerator_ <= 0;
}

bool operator>=(const Fraction& lhs, const Fraction& rhs) {
  return (lhs - rhs).numerator_ >= 0;
}

bool operator==(const Fraction& lhs, const Fraction& rhs) {
  return (lhs - rhs).numerator_ == 0;
}

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
  return (lhs - rhs).numerator_ != 0;
}

#endif  // FRACTION_H_