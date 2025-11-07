#include <gtest/gtest.h>
#include "../include/trapezoid.h"
#include "../include/rhombus.h"
#include "../include/pentagon.h"
#include "../include/array.h"
#include <memory>

using T = double;
using fig = Figure<T>;
using fig_ptr = std::shared_ptr<fig>;
using Arr = Array<fig_ptr>;

TEST(TrapezoidTests, AreaCenterEquality) {
    Trapezoid<T> t({{0,0},{4,0},{3,2},{1,2}});
    EXPECT_NEAR(double(t), 6.0, 1e-6);
    auto c = t.center();
    EXPECT_DOUBLE_EQ(c.x, 2.0);
    EXPECT_DOUBLE_EQ(c.y, 1.0);

    Trapezoid<T> t2({{0,0},{4,0},{3,2},{1,2}});
    EXPECT_TRUE(t.equals(t2));
}

TEST(RhombusTests, AreaCenter) {
    Rhombus<T> r({{0,0},{1,2},{2,0},{1,-2}});
    double area = double(r);
    EXPECT_GT(area, 0.0);
    auto c = r.center();
    EXPECT_DOUBLE_EQ(c.x, 1.0);
    EXPECT_DOUBLE_EQ(c.y, 0.0);
}

TEST(PentagonTests, AreaCenter) {
    Pentagon<T> p({{0,0},{1,2},{2,2},{3,1},{1.5,-1}});
    double area = double(p);
    EXPECT_GT(area, 0.0);
    auto c = p.center();
    EXPECT_NEAR(c.x, (0+1+2+3+1.5)/5.0, 1e-9);
}

TEST(ArrayTests, PushRemoveTotal) {
    Arr a;
    a.push(std::make_shared<Trapezoid<T>>(Trapezoid<T>({{0,0},{4,0},{3,2},{1,2}})));
    a.push(std::make_shared<Rhombus<T>>(Rhombus<T>({{0,0},{1,2},{2,0},{1,-2}})));
    EXPECT_EQ(a.size(), 2u);
    double total = a.totalArea();
    EXPECT_GT(total, 0.0);

    a.remove(0);
    EXPECT_EQ(a.size(), 1u);
}
