#include "pch.hpp"

#include "../includes/and_or_neural_network_training_configurations.hpp"

using namespace QLogicaeSimNapseCore;

namespace QLogicaeSimNapseCoreTest
{
    class TrainingConfigurationsFixture : public ::testing::Test
    {
    protected:
        AndOrNeuralNetworkTrainingConfigurations cfg;
    };

    class TrainingConfigurationsParamTest :
        public ::testing::TestWithParam<std::tuple<std::string, size_t, double, double, std::vector<double>>> {
    };

    TEST(TrainingConfigurationsNormalTest, DefaultAndAssign)
    {
        AndOrNeuralNetworkTrainingConfigurations cfg;

        EXPECT_TRUE(cfg.name.empty());
        EXPECT_EQ(cfg.maximum_learning_epoch, 100);
        EXPECT_TRUE(cfg.inputs.empty());
        EXPECT_TRUE(cfg.outputs.empty());
        EXPECT_DOUBLE_EQ(cfg.bias, 0.0);
        EXPECT_DOUBLE_EQ(cfg.learning_rate, 2.0);
        EXPECT_EQ(cfg.weights.size(), 2);

        cfg.name = "TestNet";
        cfg.maximum_learning_epoch = 50;
        cfg.inputs = { {1,0},{0,1} };
        cfg.outputs = { 1,0 };
        cfg.weights = { 0.1,0.2 };
        cfg.bias = 0.5;
        cfg.learning_rate = 0.01;

        EXPECT_EQ(cfg.name, "TestNet");
        EXPECT_EQ(cfg.maximum_learning_epoch, 50);
        EXPECT_EQ(cfg.inputs.size(), 2);
        EXPECT_EQ(cfg.outputs[0], 1);
        EXPECT_DOUBLE_EQ(cfg.weights[1], 0.2);
    }

    TEST_F(TrainingConfigurationsFixture, ModifyAndCheck)
    {
        cfg.name = "ModifiedNet";
        cfg.bias = 1.0;
        cfg.weights = { 0.3,0.4 };

        EXPECT_EQ(cfg.name, "ModifiedNet");
        EXPECT_DOUBLE_EQ(cfg.bias, 1.0);
        EXPECT_DOUBLE_EQ(cfg.weights[1], 0.4);
    }

    TEST_P(TrainingConfigurationsParamTest, SetAndVerify)
    {
        auto param = GetParam();
        std::string name = std::get<0>(param);
        size_t max_epoch = std::get<1>(param);
        double bias = std::get<2>(param);
        double learning_rate = std::get<3>(param);
        std::vector<double> weights = std::get<4>(param);

        AndOrNeuralNetworkTrainingConfigurations cfg;
        cfg.name = name;
        cfg.maximum_learning_epoch = max_epoch;
        cfg.bias = bias;
        cfg.learning_rate = learning_rate;
        cfg.weights = weights;

        EXPECT_EQ(cfg.name, name);
        EXPECT_EQ(cfg.maximum_learning_epoch, max_epoch);
        EXPECT_DOUBLE_EQ(cfg.bias, bias);
        EXPECT_DOUBLE_EQ(cfg.learning_rate, learning_rate);
        EXPECT_EQ(cfg.weights, weights);
    }

    INSTANTIATE_TEST_CASE_P(
        TrainingConfigurationsVariations,
        TrainingConfigurationsParamTest,
        ::testing::Values(
            std::make_tuple("NetA", 100, 0.0, 2.0, std::vector<double>{0.0, 0.0}),
            std::make_tuple("NetB", 50, 0.5, 0.1, std::vector<double>{0.1, 0.2})
        )
    );
}
