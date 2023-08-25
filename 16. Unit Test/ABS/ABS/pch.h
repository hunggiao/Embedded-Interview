//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
class Wheel {
private:
    double speed;  // Tốc độ quay của bánh xe (đơn vị: vòng/phút)
public:
    Wheel() : speed(0.0) {}
    void setSpeed(double s) { speed = s; }
    double getSpeed() const { return speed; }
};

class Car {
private:
    Wheel wheel;
    double weight;  // Khối lượng của xe (đơn vị: kg)
    double passengerWeight;  // Tổng khối lượng của tất cả hành khách (đơn vị: kg)
public:
    Car() : weight(1000.0), passengerWeight(0.0) {}
    Wheel& getWheel() { return wheel; }
    void setWeight(double w) { weight = w; }
    double getWeight() const { return weight; }
    void addPassenger(double w) { passengerWeight += w; }
    double getTotalWeight() const { return weight + passengerWeight; }
};

class ABS {
private:
    Car& car;
    const double threshold = 10.0;  // Ngưỡng tốc độ quay để xem xét việc điều chỉnh lực phanh
public:
    ABS(Car& c) : car(c) {}
    void applyBrakes() {
        double wheelSpeed = car.getWheel().getSpeed();
        double carWeight = car.getTotalWeight();

        if (wheelSpeed < threshold) {
            std::cout << "Warning: Wheel is locking up! Adjusting brake force based on car weight: " << carWeight << " kg." << std::endl;
            // Logic để điều chỉnh lực phanh dựa trên khối lượng của xe sẽ ở đây
        }
        else {
            std::cout << "Brakes applied normally." << std::endl;
        }
    }
};