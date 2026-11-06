#pragma once

#include <iosfwd>

struct Matrix2x2 {
    double data[2][2]{};

    Matrix2x2() = default;
    Matrix2x2(double a, double b, double c, double d) 
        : data{{a, b}, {c, d}} {}

    ~Matrix2x2() = default;

    Matrix2x2(const Matrix2x2&) = default;
    Matrix2x2& operator=(const Matrix2x2&) = default;

    Matrix2x2(Matrix2x2&&) = default;
    Matrix2x2& operator=(Matrix2x2&&) = default;

    bool operator==(const Matrix2x2& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix2x2& m);
};
