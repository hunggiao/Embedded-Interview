#include "pch.h"

#include <gtest/gtest.h>



TEST(CarTest, WheelSpeedTest) {
    Car myCar;
    myCar.getWheel().setSpeed(5.0);
    EXPECT_DOUBLE_EQ(myCar.getWheel().getSpeed(), 5.0);
}

TEST(CarTest, PassengerWeightTest) {
    Car myCar;
    myCar.addPassenger(70.0);
    EXPECT_DOUBLE_EQ(myCar.getTotalWeight(), 1070.0);
}

TEST(ABSTest, ApplyBrakesTest) {
    Car myCar;
    ABS absSystem(myCar);

    myCar.getWheel().setSpeed(5.0);
    testing::internal::CaptureStdout();  // Capture output
    absSystem.applyBrakes();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Warning: Wheel is locking up!") != std::string::npos);

    myCar.getWheel().setSpeed(15.0);
    testing::internal::CaptureStdout();  // Capture output
    absSystem.applyBrakes();
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Brakes applied normally.") != std::string::npos);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
