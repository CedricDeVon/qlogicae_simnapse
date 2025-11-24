#include "pch.hpp"

#include "../includes/and_or_neural_network_training_results.hpp"

using namespace QLogicaeSimNapseCore;

namespace QLogicaeSimNapseCoreTest
{
    class TrainingResultsFixture : public ::testing::Test
    {
    protected:
        AndOrNeuralNetworkTrainingResults results;
    };

    class TrainingResultsParamTest :
        public ::testing::TestWithParam<std::tuple<double, double, size_t>> {
    };

    TEST(AndOrNeuralNetworkTrainingResultsNormalTest, DefaultAndAssign)
    {
        AndOrNeuralNetworkTrainingResults results;

        EXPECT_TRUE(results.epoch_results.empty());
        EXPECT_DOUBLE_EQ(results.timestamp_started, 0.0);
        EXPECT_DOUBLE_EQ(results.timestamp_ended, 0.0);

        results.timestamp_started = 1.1;
        results.timestamp_ended = 2.2;
        results.epoch_results.push_back(AndOrNeuralNetworkTrainingEpochResults{ 1,0.5,{1,0,1,0},{0,1,0,1},{0.1,0.2},0.0,0.1 });

        EXPECT_EQ(results.epoch_results.size(), 1);
        EXPECT_EQ(results.epoch_results[0].current_epoch, 1);
        EXPECT_DOUBLE_EQ(results.timestamp_started, 1.1);
        EXPECT_DOUBLE_EQ(results.timestamp_ended, 2.2);
    }

    TEST_F(TrainingResultsFixture, ModifyAndCheck)
    {
        AndOrNeuralNetworkTrainingEpochResults epoch;
        epoch.current_epoch = 2;
        results.epoch_results.push_back(epoch);

        results.timestamp_started = 0.5;
        results.timestamp_ended = 1.5;

        EXPECT_EQ(results.epoch_results[0].current_epoch, 2);
        EXPECT_DOUBLE_EQ(results.timestamp_started, 0.5);
        EXPECT_DOUBLE_EQ(results.timestamp_ended, 1.5);
    }

    TEST_P(TrainingResultsParamTest, SetAndVerify)
    {
        auto param = GetParam();
        double ts_start = std::get<0>(param);
        double ts_end = std::get<1>(param);
        size_t epoch_count = std::get<2>(param);

        AndOrNeuralNetworkTrainingResults results;
        results.timestamp_started = ts_start;
        results.timestamp_ended = ts_end;
        results.epoch_results.resize(epoch_count);

        EXPECT_DOUBLE_EQ(results.timestamp_started, ts_start);
        EXPECT_DOUBLE_EQ(results.timestamp_ended, ts_end);
        EXPECT_EQ(results.epoch_results.size(), epoch_count);
    }

    INSTANTIATE_TEST_CASE_P(
        TrainingResultsVariations,
        TrainingResultsParamTest,
        ::testing::Values(
            std::make_tuple(0.0, 0.0, 0),
            std::make_tuple(1.0, 2.0, 3),
            std::make_tuple(5.5, 10.5, 5)
        )
    );
}
