#define CATCH_CONFIG_MAIN
#include "../../catch/catch.hpp"
#include "../lab2.1/VectorFunctions.h"

using namespace std;

SCENARIO("Test with empty vector")
{
	vector<float> initalVector(0);
	vector<float> expectedVector(0);
	TransformVectorWithVariant2(initalVector);
	REQUIRE(initalVector == expectedVector);
}

SCENARIO("Test with one element")
{
	vector<float> initalVector = { 2 };
	vector<float> expectedVector = { 4 };
	TransformVectorWithVariant2(initalVector);
	REQUIRE(initalVector == expectedVector);
}

SCENARIO("Test with simple vector")
{
	vector<float> initalVector = { -1, 10, 5 };
	vector<float> expectedVector = { 1, -10, -5 };
	TransformVectorWithVariant2(initalVector);
	REQUIRE(initalVector == expectedVector);
}

SCENARIO("Test sorting numbers")
{
	vector<float> initalVector = { 20, -10, 5 };
	SortVector(initalVector);
	vector<float> expectedVector = { -10, 5, 20 };
	REQUIRE(initalVector == expectedVector);
}