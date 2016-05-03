#include "gmock/gmock.h"
#include "Wheel.h"
#include "BinBuilder.h"

using namespace testing;

class AWheel : public Test
{
public:
    Wheel wheel;
};


TEST_F(AWheel, CanAddOutcomesToBins) {
    auto out1 = std::make_shared<Outcome>("test1", 1);
    auto out2 = std::make_shared<Outcome>("test2", 2);
    auto out3 = std::make_shared<Outcome>("test3", 3);

    wheel.addOutcomeByBinIndex(0, out1);
    wheel.addOutcomeByBinIndex(1, out2);
    wheel.addOutcomeByBinIndex(1, out3);

    ASSERT_TRUE(wheel.sizeOfBinByIndex(0) == 1 &&
                wheel.sizeOfBinByIndex(1) == 2);
}

TEST_F(AWheel, CanSpinAndReturnTheBin) {
    for (int i = 0; i < ROULETTE_WHEEL_SIZE; ++i) {
        auto out = std::make_shared<Outcome>("test", 10);
        wheel.addOutcomeByBinIndex(i, out);
    }
    auto bin = wheel.spin();
    ASSERT_TRUE(bin.size() == 1);
}

TEST_F(AWheel, CanGetBinByIndex) {
    auto out = std::make_shared<Outcome>("test", 1);
    wheel.addOutcomeByBinIndex(0, out);

    auto bin = wheel.getBinByIndex(0);
    ASSERT_TRUE(bin.size() == 1);
}

TEST(Wheel, GetsBuiltByABinBuilder) {
    wheel_ptr _wheel(new Wheel());
    BinBuilder builder;
    builder.buildBins(_wheel);
}