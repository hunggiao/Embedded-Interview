//
// pch.hpp
//

#pragma once

#include "gtest/gtest.h"


enum Direction {
    CLOCKWISE,
    COUNTERCLOCKWISE
};

class DCMotor {
private:
    double voltage;
    double maxCurrent;
    double speed;           // Speed in RPM
    Direction direction;
    bool isRunning;

public:
    DCMotor(double v, double current)
        : voltage(v), maxCurrent(current), speed(0), direction(CLOCKWISE), isRunning(false) {}

    void setSpeed(double s) {
        if (s >= 0 && s <= 5000) { // Assuming 5000RPM is the max speed for this example
            speed = s;
        }
        else {
            std::cerr << "Invalid speed set. Keeping previous value.\n";
        }
    }

    double getSpeed() const {
        return speed;
    }

    void setDirection(Direction d) {
        direction = d;
    }

    Direction getDirection() const {
        return direction;
    }

    void start() {
        if (!isRunning) {
            isRunning = true;
            // Insert logic to physically start the motor using hardware interfaces
            std::cout << "DC Motor started at " << speed << " RPM.\n";
        }
    }

    void stop() {
        if (isRunning) {
            isRunning = false;
            speed = 0;
            // Insert logic to physically stop the motor using hardware interfaces
            std::cout << "DC Motor stopped.\n";
        }
    }

    bool runningStatus() const {
        return isRunning;
    }
};

class FeedbackSystem {
private:
    bool overloadDetected;
    bool overheatDetected;

public:
    FeedbackSystem() : overloadDetected(false), overheatDetected(false) {}

    void detectOverload(double current) {
        if (current > 1.5) { // Assuming 1.5A as overload current for this example
            overloadDetected = true;
        }
        else {
            overloadDetected = false;
        }
    }

    void detectOverheat(double temperature) {
        if (temperature > 80) { // Assuming 80C as overheat temperature for this example
            overheatDetected = true;
        }
        else {
            overheatDetected = false;
        }
    }

    bool isOverloaded() const {
        return overloadDetected;
    }

    bool isOverheated() const {
        return overheatDetected;
    }
};

class DCMotorController {
private:
    DCMotor motor;
    FeedbackSystem feedback;

public:
    DCMotorController(double voltage, double maxCurrent)
        : motor(voltage, maxCurrent) {}

    void controlMotor(double currentFeedback, double temperatureFeedback) {
        feedback.detectOverload(currentFeedback);
        feedback.detectOverheat(temperatureFeedback);

        if (feedback.isOverloaded() || feedback.isOverheated()) {
            std::cerr << "Issue detected. Stopping the motor...\n";
            motor.stop();
        }
        else {
            motor.start();
        }
    }

    void setMotorDirection(Direction dir) {
        motor.setDirection(dir);
    }

    void setMotorSpeed(double s) {
        motor.setSpeed(s);
    }
};
