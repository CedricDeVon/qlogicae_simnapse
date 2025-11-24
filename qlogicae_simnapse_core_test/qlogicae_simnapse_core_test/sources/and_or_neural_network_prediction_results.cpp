#include "pch.hpp"

#include "../includes/and_or_neural_network_prediction_results.hpp"

using namespace QLogicaeSimNapseCore;

namespace QLogicaeSimNapseCoreTest
{
    class PredictionResultsFixture : public ::testing::Test
    {
    protected:
        AndOrNeuralNetworkPredictionResults pred;
    };

    class PredictionResultsParamTest :
        public ::testing::TestWithParam<std::tuple<int, double, double>> {
    };

    TEST(PredictionResultsNormalTest, DefaultAndAssign)
    {
        AndOrNeuralNetworkPredictionResults pred;
        EXPECT_EQ(pred.value, 0);
        EXPECT_DOUBLE_EQ(pred.timestamp_started, 0.0);
        EXPECT_DOUBLE_EQ(pred.timestamp_ended, 0.0);

        pred.value = 1;
        pred.timestamp_started = 0.5;
        pred.timestamp_ended = 1.5;

        EXPECT_EQ(pred.value, 1);
        EXPECT_DOUBLE_EQ(pred.timestamp_started, 0.5);
        EXPECT_DOUBLE_EQ(pred.timestamp_ended, 1.5);
    }

    TEST_F(PredictionResultsFixture, ModifyAndCheck)
    {
        pred.value = 2;
        pred.timestamp_started = 1.0;
        pred.timestamp_ended = 2.0;

        EXPECT_EQ(pred.value, 2);
        EXPECT_DOUBLE_EQ(pred.timestamp_started, 1.0);
        EXPECT_DOUBLE_EQ(pred.timestamp_ended, 2.0);
    }

    TEST_P(PredictionResultsParamTest, SetAndVerify)
    {
        auto param = GetParam();
        int value = std::get<0>(param);
        double ts_start = std::get<1>(param);
        double ts_end = std::get<2>(param);

        AndOrNeuralNetworkPredictionResults pred;
        pred.value = value;
        pred.timestamp_started = ts_start;
        pred.timestamp_ended = ts_end;

        EXPECT_EQ(pred.value, value);
        EXPECT_DOUBLE_EQ(pred.timestamp_started, ts_start);
        EXPECT_DOUBLE_EQ(pred.timestamp_ended, ts_end);
    }

    INSTANTIATE_TEST_CASE_P(
        PredictionResultsVariations,
        PredictionResultsParamTest,
        ::testing::Values(
            std::make_tuple(0, 0.0, 0.0),
            std::make_tuple(1, 0.5, 1.5),
            std::make_tuple(2, 1.0, 2.0)
        )
    );
}
