#include "pch.h"
#include "../../source/core.hpp"


TEST(Vector3Test, Magnitude) {
	auto expected = sqrt(12);
	auto v = furia::Vector3(2, -2, -2);
	auto magnitude = v.magnitude();
	EXPECT_NEAR(magnitude, expected, 1e-10);
}

TEST(Vector3Test, scalarProduct) {
	auto v1 = furia::Vector3(3, 1, 2);
	auto v2 = furia::Vector3(0, 2, -1);
	auto expected = 0;
	auto res = v1.scalarProduct(v2);
	EXPECT_NEAR(expected, res, 1e-10);
}





