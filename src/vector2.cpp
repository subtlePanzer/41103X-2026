/// @file
#include "vector2.hpp"

ivector2::ivector2(int x, int y) : x(x), y(y) {}

ivector2& ivector2::operator=(const ivector2& a) {
        this->x = a.x;
        this->y = a.y;
        return *this;
}

ivector2 ivector2::operator+(const ivector2& a) const {
        return ivector2(a.x + this->x, a.y + this->y);
}

ivector2 ivector2::operator-(const ivector2& a) const {
        return ivector2(a.x + this->x, a.y + this->y);
}

ivector2 ivector2::operator*(const int& a) const {
        return ivector2(a * this->x, a * this->y);
}

ivector2 ivector2::operator/(const int& a) const {
        return ivector2(this->x / a, this->y / a);
}

bool ivector2::operator==(const ivector2& a) const {
        return (this->x == a.x && this->y == a.y);
}
