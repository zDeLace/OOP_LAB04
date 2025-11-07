#include "include/point.h"
#include "include/figure.h"
#include "include/trapezoid.h"
#include "include/rhombus.h"
#include "include/pentagon.h"
#include "include/array.h"

#include <iostream>
#include <memory>
#include <limits>

using T = double;
using fig_t = Figure<T>;
using fig_ptr = std::shared_ptr<fig_t>;
using FigArray = Array<fig_ptr>;

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

fig_ptr createFigure(int choice) {
    if (choice == 1) {
        auto p = std::make_shared<Trapezoid<T>>();
        std::cout << "Enter 4 points as x y pairs (order matters):\n";
        std::cin >> *p;
        return p;
    } else if (choice == 2) {
        auto p = std::make_shared<Rhombus<T>>();
        std::cout << "Enter 4 points as x y pairs:\n";
        std::cin >> *p;
        return p;
    } else if (choice == 3) {
        auto p = std::make_shared<Pentagon<T>>();
        std::cout << "Enter 5 points as x y pairs:\n";
        std::cin >> *p;
        return p;
    }
    return nullptr;
}

int main() {
    FigArray arr;
    int cmd = -1;

    while (true) {
        std::cout << "1. Add trapezoid\n";
        std::cout << "2. Add rhombus\n";
        std::cout << "3. Add pentagon\n";
        std::cout << "4. Print all figures\n";
        std::cout << "5. Remove figure by index\n";
        std::cout << "6. Show total area\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";
        if (!(std::cin >> cmd)) { clearInput(); continue; }
        if (cmd == 0) break;

        if (cmd >=1 && cmd <=3) {
            fig_ptr f = createFigure(cmd);
            if (f) {
                arr.push(std::move(f));
                std::cout << "Added\n";
            } else std::cout << "Failed to create figure\n";
            continue;
        }

        switch (cmd) {
            case 4:
                arr.printAll(std::cout);
                break;
            case 5: {
                size_t idx;
                std::cout << "Index to remove: ";
                if (!(std::cin >> idx)) { clearInput(); break; }
                try { arr.remove(idx); std::cout << "Removed\n"; }
                catch (const std::exception& e) { std::cerr << e.what() << "\n"; }
                break;
            }
            case 6:
                std::cout << "Total area: " << arr.totalArea() << "\n";
                break;
            default:
                std::cout << "Unknown command\n";
        }
    }

    return 0;
}
