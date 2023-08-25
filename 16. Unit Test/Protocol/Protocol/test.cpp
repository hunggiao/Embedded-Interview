#include "pch.h"
#include "gtest/gtest.h"

// Test case for SimpleProtocol::pack and SimpleProtocol::unpack
TEST(SimpleProtocolTest, PackUnpackTest) {
    std::string inputData = "Hello, World!";
    std::vector<uint8_t> packedData = SimpleProtocol::pack(inputData);

    std::string outputData;
    bool unpacked = SimpleProtocol::unpack(packedData, outputData);

    EXPECT_TRUE(unpacked);
    EXPECT_EQ(inputData, outputData);
}

// Test case for MCU::sendData and MCU::receiveData
TEST(MCUTest, SendReceiveTest) {
    MCU mcu;
    std::string inputData = "Test data";

    mcu.sendData(inputData);

    std::string outputData;
    bool received = mcu.receiveData(outputData);

    EXPECT_TRUE(received);
    EXPECT_EQ(inputData, outputData);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
