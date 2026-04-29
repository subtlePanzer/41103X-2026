/// @file
/// @brief 2-dimensional vector datatypes.
#pragma once

/// @brief Integral vector
typedef struct ivector2 {
public:
        /// @brief The x-component of the vector.
        int x;
        /// @brief The y-component of the vector.
        int y;

        /// @brief Constructor.
        /// @param x The x-component of the vector.
        /// @param y The y-component of the vector.
        ivector2(int x=0, int y=0);

        ivector2& operator=(const ivector2& a);
        ivector2 operator+(const ivector2& a) const;
        ivector2 operator-(const ivector2& a) const;
        ivector2 operator*(const int& a) const;
        ivector2 operator/(const int& a) const;
        bool operator==(const ivector2& a) const;
} ivector2;

/// @brief Floating point vector.
typedef struct fvector2 {
public:
        float x;
        float y;
} fvector2;

/// @brief Double-precision floating point vectors.
typedef struct dvector2 {
public:
        double x;
        double y;
} dvector2;
