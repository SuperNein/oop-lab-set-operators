#include "matrix.hpp"

bool Matrix2x2::operator==(const Matrix2x2& other) const {
    return data[0][0] == other.data[0][0]
        && data[0][1] == other.data[0][1]
        && data[1][0] == other.data[1][0]
        && data[1][1] == other.data[1][1];
}

std::ostream& operator<<(std::ostream& os, const Matrix2x2& m) {
    os << "[[" << m.data[0][0] << ", " << m.data[0][1] << "], "
        << "[" << m.data[1][0] << ", " << m.data[1][1] << "]]";

    return os;
}
