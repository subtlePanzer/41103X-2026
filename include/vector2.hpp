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
        ivector2(int x = 0, int y = 0);

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
        /// @brief The x-component of the vector.
        float x;
        /// @brief The y-component of the vector.
        float y;

        /// @brief Constructor.
        /// @param x The x-component of the vector.
        /// @param y The y-component of the vector.
        fvector2(float x = 0, float y = 0);

        fvector2& operator=(const fvector2& a);
        fvector2 operator+(const fvector2& a) const;
        fvector2 operator-(const fvector2& a) const;
        fvector2 operator*(const float& a) const;
        fvector2 operator/(const float& a) const;
        bool operator==(const fvector2& a) const;
} fvector2;

/// @brief Double-precision floating point vectors.
typedef struct dvector2 {
public:
        /// @brief The x-component of the vector.
        double x;
        /// @brief The y-component of the vector.
        double y;

        /// @brief Constructor.
        /// @param x The x-component of the vector.
        /// @param y The y-component of the vector.
        dvector2(double x = 0, double y = 0);

        dvector2& operator=(const dvector2& a);
        dvector2 operator+(const dvector2& a) const;
        dvector2 operator-(const dvector2& a) const;
        dvector2 operator*(const double& a) const;
        dvector2 operator/(const double& a) const;
        bool operator==(const dvector2& a) const;
} dvector2;
