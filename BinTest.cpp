#include "gmock/gmock.h"
#include "Bin.h"
#include "Outcome.h"

using namespace testing;

class ABin : public Test
{
public:
    Bin bin;
    Bin bin2;
};


TEST_F(ABin, CanStoreAnOutcome) {
    auto out1 = std::make_shared<Outcome>("test", 1);
    bin.addOutcome(out1);
    ASSERT_TRUE(bin.size() == 1);
}

TEST_F(ABin, CanShareOutcomesInDifferentBins) {
    auto out1 = std::make_shared<Outcome>("test1", 1);
    auto out2 = std::make_shared<Outcome>("test2", 2);
    auto out3 = std::make_shared<Outcome>("test3", 3);

    bin.addOutcome(out1);
    bin2.addOutcome(out1);
    bin2.addOutcome(out2);
    bin2.addOutcome(out3);

    ASSERT_TRUE(bin.size() == 1 && bin2.size() == 3);
}