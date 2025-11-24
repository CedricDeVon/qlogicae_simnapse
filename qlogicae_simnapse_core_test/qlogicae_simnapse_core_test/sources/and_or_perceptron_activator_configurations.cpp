#include "pch.hpp"

#include "../includes/and_or_perceptron_activator_configurations.hpp"

using namespace QLogicaeSimNapseCore;

namespace QLogicaeSimNapseCoreTest
{
    class PerceptronActivatorFixture : public ::testing::Test
    {
    protected:
        AndOrPerceptronActivatorConfigurations cfg;
    };

    class PerceptronActivatorParamTest :
        public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<double>, double>> {
    };

    TEST(AndOrPerceptronActivatorConfigurationsNormalTest, DefaultAndAssign)
    {
        AndOrPerceptronActivatorConfigurations cfg;
        EXPECT_TRUE(cfg.inputs.empty());
        EXPECT_TRUE(cfg.weights.empty());
        EXPECT_DOUBLE_EQ(cfg.bias, 0.0);

        cfg.inputs = { 1, 0 };
        cfg.weights = { 0.5, -0.3 };
        cfg.bias = 1.25;

        EXPECT_EQ(cfg.inputs[0], 1);
        EXPECT_DOUBLE_EQ(cfg.weights[1], -0.3);
        EXPECT_DOUBLE_EQ(cfg.bias, 1.25);
    }

    TEST_F(PerceptronActivatorFixture, AssignAndVerify)
    {
        cfg.inputs = { 0, 1 };
        cfg.weights = { 0.1, 0.2 };
        cfg.bias = 0.5;

        EXPECT_EQ(cfg.inputs[1], 1);
        EXPECT_DOUBLE_EQ(cfg.weights[0], 0.1);
        EXPECT_DOUBLE_EQ(cfg.bias, 0.5);
    }

    TEST_P(PerceptronActivatorParamTest, SetAndCheckValues)
    {
        auto [inputs, weights, bias] = GetParam();
        AndOrPerceptronActivatorConfigurations cfg;
        cfg.inputs = inputs;
        cfg.weights = weights;
        cfg.bias = bias;

        EXPECT_EQ(cfg.inputs, inputs);
        EXPECT_EQ(cfg.weights, weights);
        EXPECT_DOUBLE_EQ(cfg.bias, bias);
    }

    INSTANTIATE_TEST_CASE_P(
        PerceptronActivatorVariations,
        PerceptronActivatorParamTest,
        ::testing::Values(
            std::make_tuple(std::vector<int>{1, 0}, std::vector<double>{0.5, -0.3}, 1.25),
            std::make_tuple(std::vector<int>{0, 1}, std::vector<double>{0.1, 0.2}, 0.5),
            std::make_tuple(std::vector<int>{}, std::vector<double>{}, 0.0)
        )
    );
}
