#include "pch.h"
#include "tamgiac.hpp"

string determineTriangleType(double x1, double y1, double x2, double y2, double x3, double y3) {
    double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    if (side1 == side2 && side2 == side3) {
        return "Tam giac deu";
    }
    else if (side1 == side2 || side2 == side3 || side3 == side1) {
        return "Tam giac can";
    }
    else if (side1 * side1 + side2 * side2 == side3 * side3 || side2 * side2 + side3 * side3 == side1 * side1 || side3 * side3 + side1 * side1 == side2 * side2) {
        return "Tam giac vuong";
    }
    else {
        return "Tam giac thuong";
    }
}
