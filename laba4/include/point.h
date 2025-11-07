#pragma once
#include <concepts>
#include <iostream>
#include <concepts>

template<typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Point {
public:
    T x, y;
};

template <Scalar T>
std::istream& operator>>(std::istream& is, Point<T>& p) {
    return is >> p.x >> p.y;
}

template <Scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

