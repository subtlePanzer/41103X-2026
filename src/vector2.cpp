/// @file
/// @brief 2-dimensional vector datatypes.
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


fvector2::fvector2(float x, float y) : x(x), y(y) {}

fvector2& fvector2::operator=(const fvector2& a) {
        this->x = a.x;
        this->y = a.y;
        return *this;
}

fvector2 fvector2::operator+(const fvector2& a) const {
        return fvector2(a.x + this->x, a.y + this->y);
}

fvector2 fvector2::operator-(const fvector2& a) const {
        return fvector2(a.x + this->x, a.y + this->y);
}

fvector2 fvector2::operator*(const float& a) const {
        return fvector2(a * this->x, a * this->y);
}

fvector2 fvector2::operator/(const float& a) const {
        return fvector2(this->x / a, this->y / a);
}

bool fvector2::operator==(const fvector2& a) const {
        return (this->x == a.x && this->y == a.y);
}

dvector2::dvector2(double x, double y) : x(x), y(y) {}

dvector2& dvector2::operator=(const dvector2& a) {
        this->x = a.x;
        this->y = a.y;
        return *this;
}

dvector2 dvector2::operator+(const dvector2& a) const {
        return dvector2(a.x + this->x, a.y + this->y);
}

dvector2 dvector2::operator-(const dvector2& a) const {
        return dvector2(a.x + this->x, a.y + this->y);
}

dvector2 dvector2::operator*(const double& a) const {
        return dvector2(a * this->x, a * this->y);
}

dvector2 dvector2::operator/(const double& a) const {
        return dvector2(this->x / a, this->y / a);
}

bool dvector2::operator==(const dvector2& a) const {
        return (this->x == a.x && this->y == a.y);
}
