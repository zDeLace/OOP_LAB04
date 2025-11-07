#pragma once
#include "figure.h"
#include <vector>
#include <memory>
#include <cmath>

template<Scalar T>
class Pentagon : public Figure<T> {
public:
    using point_t = Point<T>;
private:
    std::vector<std::unique_ptr<point_t>> pts;
public:
    Pentagon() { pts.resize(5); for (int i=0;i<5;++i) pts[i] = std::make_unique<point_t>(); }
    Pentagon(const std::initializer_list<point_t>& l) {
        pts.resize(5);
        int i=0;
        for (auto&p:l) { pts[i++] = std::make_unique<point_t>(p); if(i>=5) break; }
        for (;i<5;++i) pts[i] = std::make_unique<point_t>();
    }

    typename Figure<T>::point_t center() const override {
        T sx=0, sy=0;
        for (auto &p : pts) { sx += p->x; sy += p->y; }
        return { sx / T(5), sy / T(5) };
    }

    operator double() const override {
        double area = 0.0;
        for (size_t i=0;i<5;++i) {
            auto &p1 = *pts[i];
            auto &p2 = *pts[(i+1)%5];
            area += double(p1.x) * double(p2.y) - double(p2.x) * double(p1.y);
        }
        return std::abs(area) / 2.0;
    }

    void print(std::ostream& os) const override {
        os << "Pentagon: ";
        for (size_t i=0;i<5;++i) os << *pts[i] << (i+1<5? " ":"");
        os << " Area=" << double(*this) << " Center=" << center();
    }

    void read(std::istream& is) override {
        for (size_t i=0;i<5;++i) is >> *pts[i];
    }

    bool equals(const Figure<T>& other) const override {
        auto p = dynamic_cast<const Pentagon<T>*>(&other);
        if (!p) return false;
        for (size_t i=0;i<5;++i) {
            if (pts[i]->x != p->pts[i]->x) return false;
            if (pts[i]->y != p->pts[i]->y) return false;
        }
        return true;
    }
};
