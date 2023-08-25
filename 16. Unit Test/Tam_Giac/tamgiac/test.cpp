#include "pch.h"
#include "tamgiac.hpp"

TEST(determineTriangleTypeTest, TamGiacCan) {
	double x1 = -1, y1 = 1;
	double x2 = 1, y2 = 3;
	double x3 = 2, y3= 0;
	string result = determineTriangleType(x1, y1, x2, y2, x3, y3);
	EXPECT_EQ(result, "Tam giac can");
}


TEST(determineTriangleTypeTest, TamGiacThuong) {
	double x1 = -1, y1 = 1;
	double x2 = 2, y2 = 4;
	double x3 = 6, y3 = 0;
	string result = determineTriangleType(x1, y1, x2, y2, x3, y3);
	EXPECT_EQ(result, "Tam giac thuong");
}

TEST(determineTriangleTypeTest, TamGiacDeu) {
	double x1 = 0, y1 = 0;
	double x2 = 3, y2 = sqrt(3);
	double x3 = 3, y3 = -sqrt(3);
	string result = determineTriangleType(x1, y1, x2, y2, x3, y3);
	EXPECT_EQ(result, "Tam giac deu");
}

TEST(determineTriangleTypeTest, TamGiacVuong) {
	double x1 = 1, y1 = 1;
	double x2 = 1, y2 = 4;
	double x3 = 5, y3 = 1;
	string result = determineTriangleType(x1, y1, x2, y2, x3, y3);
	EXPECT_EQ(result, "Tam giac vuong");
}