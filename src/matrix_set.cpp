#include "matrix_set.hpp"

#include <utility>

using std::size_t;

Matrix2x2Set::~Matrix2x2Set() {
    delete[] data_;
}

void Matrix2x2Set::swap(Matrix2x2Set& other) noexcept {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

void swap(Matrix2x2Set& s1, Matrix2x2Set& s2) noexcept {
    s1.swap(s2);
}

Matrix2x2Set::Matrix2x2Set(const Matrix2x2Set& other)
    : data_(other.capacity_ > 0 ? new Matrix2x2[other.capacity_]{} : nullptr),
      size_(other.size_),
      capacity_(other.capacity_) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

Matrix2x2Set::Matrix2x2Set(Matrix2x2Set&& other) noexcept {
    swap(other);
}

Matrix2x2Set& Matrix2x2Set::operator=(const Matrix2x2Set& other) {
    if (this != &other) {
        Matrix2x2Set tmp(other);
        swap(tmp);
    }
    return *this;
}

Matrix2x2Set& Matrix2x2Set::operator=(Matrix2x2Set&& other) noexcept {
    if (this != &other) {
        swap(other);
    }
    return *this;
}
