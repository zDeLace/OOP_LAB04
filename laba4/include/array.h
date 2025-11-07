#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

template<typename Ptr>
class Array {
private:
    std::vector<Ptr> data;
public:
    Array() = default;
    Array(const Array& other) = default;
    Array(Array&& other) noexcept = default;
    Array& operator=(const Array& other) = default;
    Array& operator=(Array&& other) noexcept = default;

    void push(const Ptr& p) { data.push_back(p); }
    void push(Ptr&& p) { data.push_back(std::move(p)); }

    void remove(size_t index) {
        if (index >= data.size()) throw std::out_of_range("Index out of range");
        data.erase(data.begin() + static_cast<std::ptrdiff_t>(index));
    }

    double totalArea() const {
        double sum = 0.0;
        for (auto const& p : data) sum += double(*p);
        return sum;
    }

    void printAll(std::ostream& os) const {
        for (size_t i=0;i<data.size();++i) {
            os << i << ": ";
            data[i]->print(os);
            os << "\n";
        }
    }

    size_t size() const { return data.size(); }
    const Ptr& at(size_t idx) const { return data.at(idx); }
};
