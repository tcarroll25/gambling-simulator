#ifndef BIN_BUILDER_H
#define BIN_BUILDER_H

#include <memory>
#include "Wheel.h"
#include "Outcome.h"

const int STRAIGHT_ODDS = 35;
const int SPLIT_ODDS = 17;
const int STREET_ODDS = 11;
const int CORNER_ODDS = 8;
const int LINE_ODDS = 5;
const int DOZEN_ODDS = 2;
const int COLUMN_ODDS = 2;
const int EVEN_ODDS = 1;

const int ROULETTE_BOARD_ROWS = 12;
const int ROULETTE_BOARD_COLUMNS = 3;

const int EVEN_MONEY_LOW = 19;

class BinBuilder
{
public:

    BinBuilder() = default;

    void buildBins(wheel_ptr _wheel)
    {
        wheel = _wheel;
        if (wheel)
            generateBets(wheel);
    }

protected:

    void generateBets(wheel_ptr _wheel)
    {
        generateStraightBets(_wheel);
        generateSplitBets(_wheel);
        generateStreetBets(_wheel);
        generateCornerBets(_wheel);
        generateLineBets(_wheel);
        generateDozenBets(_wheel);
        generateColumnBets(_wheel);
        generateEvenMoneyBets(_wheel);
    }

    void generateStraightBets(wheel_ptr _wheel)
    {
        std::stringstream str;
        
        for (int i = 0; i < ROULETTE_WHEEL_SIZE - 1; ++i) {
            str.str("");
            str << "straight-" << i;
            auto outcome = std::make_shared<Outcome>(str.str(), STRAIGHT_ODDS);
            _wheel->addOutcomeByBinIndex(i, outcome);
        }

        auto outcome = std::make_shared<Outcome>("straight-00", STRAIGHT_ODDS);
        _wheel->addOutcomeByBinIndex(ROULETTE_WHEEL_SIZE - 1, outcome);
    }

    void generateSplitBets(wheel_ptr _wheel)
    {
        std::stringstream str;

        for (int i = 0; i < ROULETTE_BOARD_ROWS; ++i) {
            str.str("");
            int n = 3*i + 1;
            str << "split-" << n << "-" << n + 1;
            auto outcome = std::make_shared<Outcome>(str.str(), SPLIT_ODDS);
            _wheel->addOutcomeByBinIndex(n, outcome);
            _wheel->addOutcomeByBinIndex(n + 1, outcome);

            str.str("");
            n = 3*i + 2;
            str << "split-" << n << "-" << n + 1;
            outcome = std::make_shared<Outcome>(str.str(), SPLIT_ODDS);
            _wheel->addOutcomeByBinIndex(n, outcome);
            _wheel->addOutcomeByBinIndex(n + 1, outcome);
        }

        for (int i = 1; i < 34; ++i) {
            str.str("");
            str << "split-" << i << "-" << i + 3;
            auto outcome = std::make_shared<Outcome>(str.str(), SPLIT_ODDS);
            _wheel->addOutcomeByBinIndex(i, outcome);
            _wheel->addOutcomeByBinIndex(i + 3, outcome);
        }
        
    }

    void generateStreetBets(wheel_ptr _wheel)
    {
        std::stringstream str;

        for (int i = 0; i < ROULETTE_BOARD_ROWS; ++i) {
            str.str("");
            int n = 3*i + 1;
            str << "street-" << n << "-" << n + 1 << "-" << n + 2;
            auto outcome = std::make_shared<Outcome>(str.str(), STREET_ODDS);
            _wheel->addOutcomeByBinIndex(n, outcome);
            _wheel->addOutcomeByBinIndex(n + 1, outcome);
            _wheel->addOutcomeByBinIndex(n + 2, outcome);
        }
    }

    void generateCornerBets(wheel_ptr _wheel)
    {
        std::stringstream str;
        
        for (int i = 0; i < ROULETTE_BOARD_ROWS - 1; ++i) {
            str.str("");
            int n = 3*i + 1;
            str << "corner-" << n << "-" << n + 1 << "-" << n + 3 << "-" << n + 4;
            auto outcome = std::make_shared<Outcome>(str.str(), CORNER_ODDS);
            _wheel->addOutcomeByBinIndex(n, outcome);
            _wheel->addOutcomeByBinIndex(n + 1, outcome);
            _wheel->addOutcomeByBinIndex(n + 3, outcome);
            _wheel->addOutcomeByBinIndex(n + 4, outcome);

            str.str("");
            n = 3*i + 2; 
            str << "corner-" << n << "-" << n + 1 << "-" << n + 3 << "-" << n + 4;
            outcome = std::make_shared<Outcome>(str.str(), CORNER_ODDS);
            _wheel->addOutcomeByBinIndex(n, outcome);
            _wheel->addOutcomeByBinIndex(n + 1, outcome);
            _wheel->addOutcomeByBinIndex(n + 3, outcome);
            _wheel->addOutcomeByBinIndex(n + 4, outcome);
        }
    }

    void generateLineBets(wheel_ptr _wheel)
    {
        std::stringstream str;

        for (int i = 0; i < ROULETTE_BOARD_ROWS - 1; ++i) {
            str.str("");
            int n = 3*i + 1;
            str << "line-" << n << "-" << n + 1 << "-" << n + 2 << "-" << n + 3
                << "-" << n + 4 << "-" << n + 5;
            auto outcome = std::make_shared<Outcome>(str.str(), LINE_ODDS);
            _wheel->addOutcomeByBinIndex(n, outcome);
            _wheel->addOutcomeByBinIndex(n + 1, outcome);
            _wheel->addOutcomeByBinIndex(n + 3, outcome);
            _wheel->addOutcomeByBinIndex(n + 4, outcome);
            _wheel->addOutcomeByBinIndex(n + 5, outcome);
        }
    }

    void generateDozenBets(wheel_ptr _wheel)
    {
        std::stringstream str;

        for (int dozen = 0; dozen < ROULETTE_BOARD_COLUMNS; ++dozen) {
            str.str("");
            str << "dozen-" << dozen + 1;
            auto outcome = std::make_shared<Outcome>(str.str(), DOZEN_ODDS);

            for (int i = 0; i < ROULETTE_BOARD_ROWS; ++i) {
                _wheel->addOutcomeByBinIndex(12*dozen + i + 1, outcome);
            }
        }
    }

    void generateColumnBets(wheel_ptr _wheel)
    {
        std::stringstream str;

        for (int column = 0; column < ROULETTE_BOARD_COLUMNS; ++column) {
            str.str("");
            str << "column-" << column + 1;
            auto outcome = std::make_shared<Outcome>(str.str(), COLUMN_ODDS);

            for (int i = 0; i < ROULETTE_BOARD_ROWS; ++i) {
                _wheel->addOutcomeByBinIndex(3*i + column + 1, outcome);
            }
        }
    }

    void generateEvenMoneyBets(wheel_ptr _wheel)
    {
        std::stringstream str;
        auto red = std::make_shared<Outcome>("red", EVEN_ODDS);
        auto black = std::make_shared<Outcome>("black", EVEN_ODDS);
        auto even = std::make_shared<Outcome>("even", EVEN_ODDS);
        auto odd = std::make_shared<Outcome>("odd", EVEN_ODDS);
        auto high = std::make_shared<Outcome>("high", EVEN_ODDS);
        auto low = std::make_shared<Outcome>("low", EVEN_ODDS);

        for (int i = 1; i < ROULETTE_WHEEL_SIZE - 1; ++i) {
            (i < EVEN_MONEY_LOW) ? _wheel->addOutcomeByBinIndex(i, low) : _wheel->addOutcomeByBinIndex(i, high);
            (i % 2 == 0) ? _wheel->addOutcomeByBinIndex(i, even) : _wheel->addOutcomeByBinIndex(i, odd);
            (isBinIndexRed(i)) ? _wheel->addOutcomeByBinIndex(i, red) : _wheel->addOutcomeByBinIndex(i, black);
        }
    }

    bool isBinIndexRed(const int index)
    {
        return (index == 1 || index == 3 || index == 5 || index == 7 || index == 9 || index == 12 ||
                index == 14 || index == 16 || index == 18 || index == 19 || index == 21 || index == 23 ||
                index == 25 || index == 27 || index == 30 || index == 32 || index == 34 || index == 36);
    }

private:
    wheel_ptr wheel;
};

#endif