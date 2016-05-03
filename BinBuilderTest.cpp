#include "gmock/gmock.h"
#include "Wheel.h"
#include "BinBuilder.h"

using namespace testing;

class ABinBuilder : public Test, public BinBuilder
{
public:
    ABinBuilder()
        : wheel(std::make_shared<Wheel>()) {}

    wheel_ptr wheel;
};

// TODO: Best way to test builder?
TEST_F(ABinBuilder, GeneratesStraightBets) {
    generateStraightBets(wheel);
}