//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <stdint.h>
class SimpleProtocol {
public:
    // Đóng gói dữ liệu
    static std::vector<uint8_t> pack(const std::string& data) {
        std::vector<uint8_t> packet;
        packet.push_back(0xAA); // Start byte
        packet.push_back(data.length()); // Data length

        uint8_t checksum = 0;
        for (char c : data) {
            packet.push_back(c);
            checksum += c;
        }

        packet.push_back(checksum); // Checksum
        return packet;
    }

    // Giải mã dữ liệu
    static bool unpack(const std::vector<uint8_t>& packet, std::string& out) {
        if (packet.size() < 3 || packet[0] != 0xAA) return false;

        uint8_t length = packet[1];
        if (packet.size() != length + 3) return false;

        uint8_t checksum = 0;
        out = "";
        for (size_t i = 2; i < 2 + length; ++i) {
            out += packet[i];
            checksum += packet[i];
        }

        return checksum == packet.back();
    }
};

class MCU {
private:
    static std::vector<uint8_t> bus; // Bus giả lập dùng chung giữa các MCU
public:
    void sendData(const std::string& data) {
        std::vector<uint8_t> packet = SimpleProtocol::pack(data);
        bus = packet; // Giả lập việc truyền dữ liệu qua bus
    }

    bool receiveData(std::string& out) {
        return SimpleProtocol::unpack(bus, out);
    }

};

std::vector<uint8_t> MCU::bus = {}; // Khởi tạo biến tĩnh bus