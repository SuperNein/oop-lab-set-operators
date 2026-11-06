#include "matrix.hpp"

#include <cstddef>
#include <iosfwd>

class Matrix2x2Set {
public:
    Matrix2x2Set() = default;
    ~Matrix2x2Set();

    Matrix2x2Set(const Matrix2x2Set&);
    Matrix2x2Set(Matrix2x2Set&&) noexcept;

    Matrix2x2Set& operator=(const Matrix2x2Set&);
    Matrix2x2Set& operator=(Matrix2x2Set&&) noexcept;

    void swap(Matrix2x2Set& other) noexcept;
    friend void swap(Matrix2x2Set& s1, Matrix2x2Set& s2) noexcept;

    bool add(const Matrix2x2& item);
    bool remove(const Matrix2x2& item);

    bool contains(const Matrix2x2& item) const;
    bool operator()(const Matrix2x2& item) const;

    std::size_t size() const noexcept;
    std::size_t capacity() const noexcept;
    bool empty() const noexcept;

    Matrix2x2Set& operator+=(const Matrix2x2&);
    Matrix2x2Set& operator-=(const Matrix2x2&);

    Matrix2x2Set operator|(const Matrix2x2Set&) const;
    Matrix2x2Set operator&(const Matrix2x2Set&) const;
    Matrix2x2Set operator-(const Matrix2x2Set&) const;

    bool operator==(const Matrix2x2Set&) const;
    bool operator!=(const Matrix2x2Set&) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix2x2Set& set);

private:
    Matrix2x2* data_{nullptr};
    std::size_t size_{0};
    std::size_t capacity_{0};
};
