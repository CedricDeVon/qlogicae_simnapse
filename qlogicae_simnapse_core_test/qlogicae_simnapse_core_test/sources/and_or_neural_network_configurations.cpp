#include "pch.hpp"

#include "../includes/and_or_neural_network_configurations.hpp"

using namespace QLogicaeSimNapseCore;

namespace QLogicaeSimNapseCoreTest
{
    class NeuralNetworkConfigurationsFixture : public ::testing::Test
    {
    protected:
        AndOrNeuralNetworkConfigurations cfg;
    };

    class NeuralNetworkConfigurationsParamTest :
        public ::testing::TestWithParam<int> {
    };

    TEST(NeuralNetworkConfigurationsNormalTest, Default)
    {
        SUCCEED(); 
    }

    TEST_F(NeuralNetworkConfigurationsFixture, EmptyStruct)
    {
        SUCCEED(); 
    }

    TEST_P(NeuralNetworkConfigurationsParamTest, EmptyStruct)
    {
        SUCCEED();
    }

    INSTANTIATE_TEST_CASE_P(
        NeuralNetworkConfigurationsVariations,
        NeuralNetworkConfigurationsParamTest,
        ::testing::Values(0, 1)
    );
}
