#pragma once
#include "point.h"
#include <memory>
#include <ostream>

template<Scalar T>
class Figure {
public:
    using point_t = Point<T>;
    virtual point_t center() const = 0;
    virtual operator double() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual bool equals(const Figure<T>& other) const = 0;
    virtual ~Figure() = default;
};

template<Scalar T>
inline std::ostream& operator<<(std::ostream& os, const Figure<T>& f) {
    f.print(os);
    return os;
}

template<Scalar T>
inline std::istream& operator>>(std::istream& is, Figure<T>& f) {
    f.read(is);
    return is;
}
