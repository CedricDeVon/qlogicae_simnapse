#include "pch.hpp"

#include "../includes/and_or_perceptron.hpp"

using namespace QLogicaeSimNapseCore;

namespace QLogicaeSimNapseCoreTest
{
    class AndOrPerceptronTest : public ::testing::Test
    {
    protected:
        AndOrPerceptron perceptron;

        AndOrNeuralNetworkTrainingConfigurations valid_configurations()
        {
            return {
                .name = "test_model",
                .maximum_learning_epoch = 2,
                .inputs = {{0,0}, {0,1}, {1,0}, {1,1}},
                .outputs = {0, 1, 1, 1},
                .weights = {0.0, 0.0},
                .bias = 0.0,
                .learning_rate = 1.0,
                .callback = [](const AndOrNeuralNetworkTrainingEpochResults& result) {}
            };
        }

        AndOrNeuralNetworkTrainingConfigurations invalid_configurations()
        {
            return {
                .name = "",
                .maximum_learning_epoch = 0,
                .inputs = {{0}}, 
                .outputs = {0},
                .weights = {0.0}, 
                .bias = 0.0,
                .learning_rate = -1.0,
                .callback = [](const AndOrNeuralNetworkTrainingEpochResults& result) {}
            };
        }

        AndOrNeuralNetworkPredictionConfigurations valid_prediction_config()
        {
            return {
                .name = "pred_model",
                .inputs = {1, 1}
            };
        }

        AndOrNeuralNetworkPredictionConfigurations invalid_prediction_config()
        {
            return {
                .name = "pred_model",
                .inputs = {1} 
            };
        }
    };

    class PerceptronActivatorParamTest :
        public AndOrPerceptronTest,
        public ::testing::WithParamInterface<std::pair<std::vector<int>, int>>
    {
    };

    TEST_F(AndOrPerceptronTest, SetupTerminateNormal)
    {
        EXPECT_TRUE(perceptron.setup());
        EXPECT_TRUE(perceptron.terminate());
    }

    TEST_F(AndOrPerceptronTest, SetupTerminateAsyncFuture)
    {
        auto setup_future = perceptron.setup_async();
        EXPECT_TRUE(setup_future.get());

        auto terminate_future = perceptron.terminate_async();
        EXPECT_TRUE(terminate_future.get());
    }

    TEST_F(AndOrPerceptronTest, TrainPredictNormal)
    {
        auto results = perceptron.train(valid_configurations());
        EXPECT_EQ(results.epoch_results.size(), 2);

        auto prediction = perceptron.predict(valid_prediction_config());
        EXPECT_TRUE(prediction.value == 0 || prediction.value == 1);
    }

    TEST_F(AndOrPerceptronTest, TrainAsyncFuture)
    {
        auto future = perceptron.train_async(valid_configurations());
        auto results = future.get();
        EXPECT_EQ(results.epoch_results.size(), 2);
    }

    TEST_F(AndOrPerceptronTest, PredictAsyncFuture)
    {
        auto future = perceptron.predict_async(valid_prediction_config());
        auto prediction = future.get();
        EXPECT_TRUE(prediction.value == 0 || prediction.value == 1);
    }

    TEST_F(AndOrPerceptronTest, TrainInvalidConfiguration)
    {
        auto results = perceptron.train(invalid_configurations());
        EXPECT_EQ(results.epoch_results.size(), 0);
    }

    TEST_F(AndOrPerceptronTest, PredictInvalidConfiguration)
    {
        auto prediction = perceptron.predict(invalid_prediction_config());
        EXPECT_EQ(prediction.value, 0);
    }

    TEST_F(AndOrPerceptronTest, SingletonReference)
    {
        AndOrPerceptron& instance_ref = AndOrPerceptron::get_instance();
        QLogicaeCore::Result<AndOrPerceptron*> result;
        AndOrPerceptron::get_instance(result);

        EXPECT_EQ(&instance_ref, result.get_value());
    }

    TEST_F(AndOrPerceptronTest, AsyncCallbacks)
    {
        bool setup_done = false;
        perceptron.setup_async([&setup_done](const bool& result) { EXPECT_TRUE(result); });

        bool terminate_done = false;
        perceptron.terminate_async([&terminate_done](const bool& result) { EXPECT_TRUE(result); });

        AndOrNeuralNetworkTrainingResults train_result;
        perceptron.train_async([&train_result](const AndOrNeuralNetworkTrainingResults& r) { EXPECT_EQ(r.epoch_results.size(), 2); },
            valid_configurations()
        );

        AndOrNeuralNetworkPredictionResults pred_result;
        perceptron.predict_async([&pred_result](const AndOrNeuralNetworkPredictionResults& r) { EXPECT_TRUE(r.value == 0 || r.value == 1); },
            valid_prediction_config()
        );
    }
}