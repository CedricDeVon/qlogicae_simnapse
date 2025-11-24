#include "pch.hpp"

#include "../includes/and_or_neural_network_training_epoch_results.hpp"

using namespace QLogicaeSimNapseCore;

namespace QLogicaeSimNapseCoreTest
{
    class TrainingEpochFixture : public ::testing::Test
    {
    protected:
        AndOrNeuralNetworkTrainingEpochResults epoch;
    };

    class TrainingEpochParamTest :
        public ::testing::TestWithParam<std::tuple<size_t, double, std::vector<int>, std::vector<int>, std::vector<double>>> {
    };

    TEST(TrainingEpochResultsNormalTest, DefaultAndAssign)
    {
        AndOrNeuralNetworkTrainingEpochResults epoch;
        EXPECT_EQ(epoch.current_epoch, 0);
        EXPECT_DOUBLE_EQ(epoch.bias, 0.0);
        EXPECT_EQ(epoch.predictions.size(), 4);
        EXPECT_EQ(epoch.errors.size(), 4);
        EXPECT_EQ(epoch.weights.size(), 2);

        epoch.current_epoch = 3;
        epoch.bias = 0.5;
        epoch.predictions = { 1,0,1,0 };
        epoch.errors = { 0,1,0,1 };
        epoch.weights = { 0.1,0.2 };

        EXPECT_EQ(epoch.current_epoch, 3);
        EXPECT_EQ(epoch.predictions[2], 1);
        EXPECT_DOUBLE_EQ(epoch.weights[1], 0.2);
    }

    TEST_F(TrainingEpochFixture, ModifyAndCheck)
    {
        epoch.current_epoch = 2;
        epoch.bias = -0.25;
        epoch.predictions[0] = 1;
        epoch.errors[1] = -1;
        epoch.weights[0] = 0.3;

        EXPECT_EQ(epoch.current_epoch, 2);
        EXPECT_DOUBLE_EQ(epoch.bias, -0.25);
        EXPECT_EQ(epoch.predictions[0], 1);
        EXPECT_EQ(epoch.errors[1], -1);
        EXPECT_DOUBLE_EQ(epoch.weights[0], 0.3);
    }

    TEST_P(TrainingEpochParamTest, SetAndVerify)
    {
        auto [current_epoch, bias, predictions, errors, weights] = GetParam();
        AndOrNeuralNetworkTrainingEpochResults epoch;
        epoch.current_epoch = current_epoch;
        epoch.bias = bias;
        epoch.predictions = predictions;
        epoch.errors = errors;
        epoch.weights = weights;

        EXPECT_EQ(epoch.current_epoch, current_epoch);
        EXPECT_DOUBLE_EQ(epoch.bias, bias);
        EXPECT_EQ(epoch.predictions, predictions);
        EXPECT_EQ(epoch.errors, errors);
        EXPECT_EQ(epoch.weights, weights);
    }

    INSTANTIATE_TEST_CASE_P(
        EpochVariations,
        TrainingEpochParamTest,
        ::testing::Values(
            std::make_tuple(1, 0.5, std::vector<int>{1, 0, 1, 0}, std::vector<int>{0, 1, 0, 1}, std::vector<double>{0.1, 0.2}),
            std::make_tuple(0, 0.0, std::vector<int>{0, 0, 0, 0}, std::vector<int>{0, 0, 0, 0}, std::vector<double>{0.0, 0.0})
        )
    );
}