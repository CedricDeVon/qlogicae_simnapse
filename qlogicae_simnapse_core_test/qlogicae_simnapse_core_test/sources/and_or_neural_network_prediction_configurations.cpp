#include "pch.hpp"

#include "../includes/and_or_neural_network_prediction_configurations.hpp"

using namespace QLogicaeSimNapseCore;

namespace QLogicaeSimNapseCoreTest
{
    class PredictionConfigurationsFixture : public ::testing::Test
    {
    protected:
        AndOrNeuralNetworkPredictionConfigurations cfg;
    };

    class PredictionConfigurationsParamTest :
        public ::testing::TestWithParam<std::tuple<std::string, std::vector<int>>> {
    };

    TEST(PredictionConfigurationsNormalTest, DefaultAndAssign)
    {
        AndOrNeuralNetworkPredictionConfigurations cfg;
        EXPECT_TRUE(cfg.name.empty());
        EXPECT_TRUE(cfg.inputs.empty());

        cfg.name = "PredNet";
        cfg.inputs = { 1,0 };

        EXPECT_EQ(cfg.name, "PredNet");
        EXPECT_EQ(cfg.inputs[0], 1);
        EXPECT_EQ(cfg.inputs[1], 0);
    }

    TEST_F(PredictionConfigurationsFixture, ModifyAndCheck)
    {
        cfg.name = "ModifiedPred";
        cfg.inputs = { 0,1 };

        EXPECT_EQ(cfg.name, "ModifiedPred");
        EXPECT_EQ(cfg.inputs[1], 1);
    }

    TEST_P(PredictionConfigurationsParamTest, SetAndVerify)
    {
        auto param = GetParam();
        std::string name = std::get<0>(param);
        std::vector<int> inputs = std::get<1>(param);

        AndOrNeuralNetworkPredictionConfigurations cfg;
        cfg.name = name;
        cfg.inputs = inputs;

        EXPECT_EQ(cfg.name, name);
        EXPECT_EQ(cfg.inputs, inputs);
    }

    INSTANTIATE_TEST_CASE_P(
        PredictionConfigurationsVariations,
        PredictionConfigurationsParamTest,
        ::testing::Values(
            std::make_tuple("", std::vector<int>{}),
            std::make_tuple("Net1", std::vector<int>{1, 0}),
            std::make_tuple("Net2", std::vector<int>{0, 1, 1})
        )
    );
}
