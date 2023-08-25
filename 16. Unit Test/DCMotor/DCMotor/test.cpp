#include "pch.h"
#include <gtest/gtest.h>

// Test DCMotor class methods
TEST(DCMotorTest, SpeedBounds) {
    DCMotor motor(12.0, 1.5);
    motor.setSpeed(1000);
    EXPECT_EQ(motor.getSpeed(), 1000);

    motor.setSpeed(6000);
    EXPECT_EQ(motor.getSpeed(), 1000); // Speed should remain unchanged
}

TEST(DCMotorTest, Direction) {
    DCMotor motor(12.0, 1.5);
    motor.setDirection(COUNTERCLOCKWISE);
    EXPECT_EQ(motor.getDirection(), COUNTERCLOCKWISE);
}

// Test FeedbackSystem class methods
TEST(FeedbackSystemTest, OverloadDetection) {
    FeedbackSystem feedback;
    feedback.detectOverload(1.0);
    EXPECT_FALSE(feedback.isOverloaded());

    feedback.detectOverload(1.6);
    EXPECT_TRUE(feedback.isOverloaded());
}

TEST(FeedbackSystemTest, OverheatDetection) {
    FeedbackSystem feedback;
    feedback.detectOverheat(70);
    EXPECT_FALSE(feedback.isOverheated());

    feedback.detectOverheat(85);
    EXPECT_TRUE(feedback.isOverheated());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
