#include "pch.hpp"

#include "../includes/and_or_perceptron_activator.hpp"

using namespace QLogicaeSimNapseCore;

namespace QLogicaeSimNapseCoreTest
{
    class ActivatorFixture : public ::testing::Test
    {
    protected:
        AndOrPerceptronActivator& activator = AndOrPerceptronActivator::get_instance();
        AndOrPerceptronActivatorConfigurations cfg1{ {1,0},{0.5,0.5},0.1 };
        AndOrPerceptronActivatorConfigurations cfg2{ {0,1},{-0.3,0.7},0.0 };
    };

    class ActivatorParamTest :
        public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<double>, double>> {
    };

    TEST(AndOrPerceptronActivatorNormalTest, SetupTerminate)
    {
        AndOrPerceptronActivator& activator = AndOrPerceptronActivator::get_instance();
        EXPECT_TRUE(activator.setup());
        EXPECT_TRUE(activator.terminate());
    }

    TEST(AndOrPerceptronActivatorNormalTest, GetInstanceWithResult)
    {
        QLogicaeCore::Result<AndOrPerceptronActivator*> result;
        AndOrPerceptronActivator::get_instance(result);
        EXPECT_EQ(result.get_value(), &AndOrPerceptronActivator::get_instance());
    }

    TEST_F(ActivatorFixture, GetActivationSync)
    {
        int result1 = activator.get_activation(cfg1);
        int result2 = activator.get_activation(cfg2);
        EXPECT_TRUE(result1 == 0 || result1 == 1);
        EXPECT_TRUE(result2 == 0 || result2 == 1);
    }

    TEST_F(ActivatorFixture, AsyncSetupTerminate)
    {
        auto fut_setup = activator.setup_async();
        EXPECT_TRUE(fut_setup.get());
        auto fut_terminate = activator.terminate_async();
        EXPECT_TRUE(fut_terminate.get());
    }

    TEST_F(ActivatorFixture, GetActivationAsync)
    {
        auto fut1 = activator.get_activation_async(cfg1);
        auto fut2 = activator.get_activation_async(cfg2);
        int result1 = fut1.get();
        int result2 = fut2.get();
        EXPECT_TRUE(result1 == 0 || result1 == 1);
        EXPECT_TRUE(result2 == 0 || result2 == 1);
    }

    TEST_P(ActivatorParamTest, Activation)
    {
        auto param = GetParam();
        std::vector<int> inputs = std::get<0>(param);
        std::vector<double> weights = std::get<1>(param);
        double bias = std::get<2>(param);

        AndOrPerceptronActivatorConfigurations cfg{ inputs, weights, bias };
        AndOrPerceptronActivator& activator = AndOrPerceptronActivator::get_instance();
        int result = activator.get_activation(cfg);
        EXPECT_TRUE(result == 0 || result == 1);
    }

    INSTANTIATE_TEST_CASE_P(
        ActivatorVariations,
        ActivatorParamTest,
        ::testing::Values(
            std::make_tuple(std::vector<int>{1, 0}, std::vector<double>{0.5, -0.3}, 0.0),
            std::make_tuple(std::vector<int>{0, 1}, std::vector<double>{0.1, 0.2}, 0.5),
            std::make_tuple(std::vector<int>{1, 1}, std::vector<double>{1.0, 1.0}, -0.5)
        )
    );

}
