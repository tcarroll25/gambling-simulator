#include "gmock/gmock.h"
#include "Outcome.h"

using namespace testing;

class AnOutcome : public Test
{
public:
    AnOutcome()
        : outcome("TestBet", 10) {}

    Outcome outcome;
};

TEST_F(AnOutcome, IsEquivalentToSameOutcome) {
    Outcome _outcome("TestBet", 10);
    ASSERT_TRUE(outcome == _outcome);
}

TEST_F(AnOutcome, IsNotEquivalentToDifferentOutcome) {
    Outcome _outcome("Fail", 10);
    ASSERT_FALSE(outcome == _outcome);
}

TEST_F(AnOutcome, CalculatesWinnings) {
    ASSERT_THAT(outcome.winAmount(10), Eq(100));
}