#include "pch.hpp"

#include "../includes/and_or_neural_network.hpp"

using namespace QLogicaeSimNapseCore;

namespace QLogicaeSimNapseCoreTest
{
    class AndOrNeuralNetworkTest : public ::testing::Test
    {
    protected:
        AndOrNeuralNetwork& network = AND_OR_NEURAL_NETWORK;
    };

    class AndOrNeuralNetworkParameterizedTest :
        public AndOrNeuralNetworkTest,
        public ::testing::WithParamInterface<int>
    {
    };

    struct TrainingConfigTestData
    {
        std::string model_name;
        double learning_rate;
        size_t epochs;
    };

    class AndOrNeuralNetworkTrainParameterizedTest :
        public AndOrNeuralNetworkTest,
        public ::testing::WithParamInterface<TrainingConfigTestData>
    {
    };

    class AndOrNeuralNetworkExtremeTest : public ::testing::Test
    {
    protected:
        void SetUp() override
        {

            
        }

        AndOrNeuralNetwork& network = AND_OR_NEURAL_NETWORK;
    };

    class AndOrNeuralNetworkExtremeAsyncTest : public ::testing::Test
    {
    protected:
        void SetUp() override
        {
            
        }

        AndOrNeuralNetwork& network = AND_OR_NEURAL_NETWORK;
    };

    TEST_F(AndOrNeuralNetworkTest, Should_SetupSuccessfully_When_CalledSynchronously)
    {
        bool result = network.setup();
        ASSERT_TRUE(result);
    }

    TEST_F(AndOrNeuralNetworkTest, Should_SetupSuccessfully_When_CalledAsyncWithFuture)
    {
        std::future<bool> future_result = network.setup_async();
        ASSERT_TRUE(future_result.get());
    }

    TEST_F(AndOrNeuralNetworkTest, Should_SetupSuccessfully_When_CalledAsyncWithCallback)
    {
        std::atomic<bool> callback_called = false;
        network.setup_async(
            [&callback_called](const bool& result)
            {
                ASSERT_TRUE(result);
                callback_called = true;
            });
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        ASSERT_TRUE(callback_called);
    }

    TEST_F(AndOrNeuralNetworkTest, Should_TrainSuccessfully_When_ValidConfigurations)
    {
        AndOrNeuralNetworkTrainingConfigurations configurations;
        configurations.name = "TestModel";
        configurations.maximum_learning_epoch = 1;
        configurations.inputs = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
        configurations.outputs = { 0, 1, 1, 1 };
        configurations.weights = { 0.5, 0.5 };
        configurations.bias = 0.0;
        configurations.learning_rate = 0.1;
        configurations.callback = [](AndOrNeuralNetworkTrainingEpochResults const&) {};

        AndOrNeuralNetworkTrainingResults results = network.train(configurations);
        ASSERT_EQ(results.epoch_results.size(), 1);
    }

    TEST_F(AndOrNeuralNetworkTest, Should_TrainSuccessfully_When_AsyncFuture)
    {
        AndOrNeuralNetworkTrainingConfigurations configurations;
        configurations.name = "AsyncModel";
        configurations.maximum_learning_epoch = 1;
        configurations.inputs = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
        configurations.outputs = { 0, 1, 1, 1 };
        configurations.weights = { 0.5, 0.5 };
        configurations.bias = 0.0;
        configurations.learning_rate = 0.1;
        configurations.callback = [](AndOrNeuralNetworkTrainingEpochResults const&) {};

        std::future<AndOrNeuralNetworkTrainingResults> future_results =
            network.train_async(configurations);

        AndOrNeuralNetworkTrainingResults results = future_results.get();
        ASSERT_EQ(results.epoch_results.size(), 1);
    }

    TEST_F(AndOrNeuralNetworkTest, Should_PredictSuccessfully_When_ModelExists)
    {
        AndOrNeuralNetworkPredictionConfigurations configurations;
        configurations.name = "TestModel";
        configurations.inputs = { 1, 1 };

        AndOrNeuralNetworkPredictionResults results =
            network.predict(configurations);
        ASSERT_GE(results.value, 0);
        ASSERT_LE(results.value, 1);
    }

    TEST_F(AndOrNeuralNetworkTest, Should_ReturnBadStatus_When_PredictWithUnknownModel)
    {
        AndOrNeuralNetworkPredictionConfigurations configurations;
        configurations.name = "UnknownModel";
        configurations.inputs = { 1, 1 };

        QLogicaeCore::Result<AndOrNeuralNetworkPredictionResults> result;
        network.predict(result, configurations);
        ASSERT_FALSE(result.is_status_safe());
    }

    TEST_F(AndOrNeuralNetworkTest, Should_TerminateSuccessfully_When_CalledSynchronously)
    {
        bool result = network.terminate();
        ASSERT_TRUE(result);
    }

    TEST_F(AndOrNeuralNetworkTest, Should_TerminateSuccessfully_When_CalledAsync)
    {
        std::future<bool> future_result = network.terminate_async();
        ASSERT_TRUE(future_result.get());
    }

    INSTANTIATE_TEST_CASE_P(
        EdgeCaseModels,
        AndOrNeuralNetworkParameterizedTest,
        ::testing::Values(0, 1, 10, 100));

    TEST_P(AndOrNeuralNetworkParameterizedTest, Should_HandleMultipleTrainingIterations)
    {
        int iteration_count = GetParam();

        AndOrNeuralNetworkTrainingConfigurations configurations;
        configurations.name = "ParameterizedModel";
        configurations.maximum_learning_epoch = 1;
        configurations.inputs = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
        configurations.outputs = { 0, 1, 1, 1 };
        configurations.weights = { 0.5, 0.5 };
        configurations.bias = 0.0;
        configurations.learning_rate = 0.1;
        configurations.callback = [](AndOrNeuralNetworkTrainingEpochResults const&) {};

        for (int i = 0; i < iteration_count; ++i)
        {
            AndOrNeuralNetworkTrainingResults results = network.train(configurations);
            ASSERT_EQ(results.epoch_results.size(), 1);
        }
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandleMultithreadedTrainingWithoutCrash)
    {
        AndOrNeuralNetworkTrainingConfigurations configurations;
        configurations.name = "ThreadedModel";
        configurations.maximum_learning_epoch = 1;
        configurations.inputs = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
        configurations.outputs = { 0, 1, 1, 1 };
        configurations.weights = { 0.5, 0.5 };
        configurations.bias = 0.0;
        configurations.learning_rate = 0.1;
        configurations.callback = [](AndOrNeuralNetworkTrainingEpochResults const&) {};

        std::vector<std::thread> threads;
        std::atomic<int> success_count = 0;

        for (int i = 0; i < 8; ++i)
        {
            threads.emplace_back([&]()
                {
                    AndOrNeuralNetworkTrainingResults results =
                        network.train(configurations);
                    if (results.epoch_results.size() == 1)
                    {
                        ++success_count;
                    }
                });
        }

        for (auto& thread : threads)
        {
            thread.join();
        }

        ASSERT_EQ(success_count.load(), 8);
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandleHighLoadAsyncTraining)
    {
        AndOrNeuralNetworkTrainingConfigurations configurations;
        configurations.name = "StressModel";
        configurations.maximum_learning_epoch = 1;
        configurations.inputs = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
        configurations.outputs = { 0, 1, 1, 1 };
        configurations.weights = { 0.5, 0.5 };
        configurations.bias = 0.0;
        configurations.learning_rate = 0.1;
        configurations.callback = [](AndOrNeuralNetworkTrainingEpochResults const&) {};

        std::vector<std::future<AndOrNeuralNetworkTrainingResults>> futures;
        futures.reserve(100);

        for (int i = 0; i < 100; ++i)
        {
            futures.emplace_back(network.train_async(configurations));
        }

        for (auto& future : futures)
        {
            AndOrNeuralNetworkTrainingResults results = future.get();
            ASSERT_EQ(results.epoch_results.size(), 1);
        }
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandleHighLoadAsyncPredictions)
    {
        AndOrNeuralNetworkPredictionConfigurations configurations;
        configurations.name = "StressModel";
        configurations.inputs = { 1, 1 };

        std::vector<std::future<AndOrNeuralNetworkPredictionResults>> futures;
        futures.reserve(100);

        for (int i = 0; i < 100; ++i)
        {
            futures.emplace_back(network.predict_async(configurations));
        }

        for (auto& future : futures)
        {
            AndOrNeuralNetworkPredictionResults results = future.get();
            ASSERT_GE(results.value, 0);
            ASSERT_LE(results.value, 1);
        }
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandleMultithreadedAsyncTrainingAndPrediction)
    {
        AndOrNeuralNetworkTrainingConfigurations train_config;
        train_config.name = "ThreadStressModel";
        train_config.maximum_learning_epoch = 1;
        train_config.inputs = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
        train_config.outputs = { 0, 1, 1, 1 };
        train_config.weights = { 0.5, 0.5 };
        train_config.bias = 0.0;
        train_config.learning_rate = 0.1;
        train_config.callback = [](AndOrNeuralNetworkTrainingEpochResults const&) {};

        AndOrNeuralNetworkPredictionConfigurations predict_config;
        predict_config.name = "ThreadStressModel";
        predict_config.inputs = { 1, 1 };

        std::vector<std::future<void>> futures;
        futures.reserve(50);

        for (int i = 0; i < 25; ++i)
        {
            futures.emplace_back(std::async(std::launch::async, [&, i]()
                {
                    AndOrNeuralNetworkTrainingResults results = network.train_async(train_config).get();
                    ASSERT_EQ(results.epoch_results.size(), 1);
                }));

            futures.emplace_back(std::async(std::launch::async, [&, i]()
                {
                    AndOrNeuralNetworkPredictionResults results = network.predict_async(predict_config).get();
                    ASSERT_GE(results.value, 0);
                    ASSERT_LE(results.value, 1);
                }));
        }

        for (auto& future : futures)
        {
            future.get();
        }
    }


    TEST_F(AndOrNeuralNetworkTest, Should_HandleEmptyTrainingConfigurations)
    {
        AndOrNeuralNetworkTrainingConfigurations empty_config;
        empty_config.name = "";
        empty_config.maximum_learning_epoch = 0;
        empty_config.inputs = {};
        empty_config.outputs = {};
        empty_config.weights = {};
        empty_config.learning_rate = 0.0;
        empty_config.callback = [](AndOrNeuralNetworkTrainingEpochResults const&) {};

        AndOrNeuralNetworkTrainingResults results =
            network.train(empty_config);

        ASSERT_TRUE(results.epoch_results.empty());
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandleInvalidTrainingConfigurations)
    {
        AndOrNeuralNetworkTrainingConfigurations invalid_config;
        invalid_config.name = "InvalidModel";
        invalid_config.maximum_learning_epoch = 0;
        invalid_config.inputs = { {0, 1} };
        invalid_config.outputs = { 1 };
        invalid_config.weights = { 0.5 };
        invalid_config.learning_rate = -1.0;
        invalid_config.callback = [](AndOrNeuralNetworkTrainingEpochResults const&) {};

        AndOrNeuralNetworkTrainingResults results =
            network.train(invalid_config);

        ASSERT_TRUE(results.epoch_results.empty());
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandleEmptyPredictionConfigurations)
    {
        AndOrNeuralNetworkPredictionConfigurations empty_config;
        empty_config.name = "";
        empty_config.inputs = {};

        AndOrNeuralNetworkPredictionResults results =
            network.predict(empty_config);

        ASSERT_EQ(results.value, 0);
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandlePredictionWithNonexistentModel)
    {
        AndOrNeuralNetworkPredictionConfigurations non_existent_model;
        non_existent_model.name = "NoSuchModel";
        non_existent_model.inputs = { 0, 1 };

        QLogicaeCore::Result<AndOrNeuralNetworkPredictionResults> result;
        network.predict(result, non_existent_model);

        ASSERT_FALSE(result.is_status_safe());
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandleAsyncTrainingWithInvalidConfigurations)
    {
        AndOrNeuralNetworkTrainingConfigurations invalid_config;
        invalid_config.name = "InvalidAsync";
        invalid_config.maximum_learning_epoch = 0;
        invalid_config.inputs = {};
        invalid_config.outputs = {};
        invalid_config.weights = {};
        invalid_config.learning_rate = 0.0;
        invalid_config.callback = [](AndOrNeuralNetworkTrainingEpochResults const&) {};

        std::future<AndOrNeuralNetworkTrainingResults> future =
            network.train_async(invalid_config);

        AndOrNeuralNetworkTrainingResults results = future.get();
        ASSERT_TRUE(results.epoch_results.empty());
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandleAsyncPredictionWithNonexistentModel)
    {
        AndOrNeuralNetworkPredictionConfigurations invalid_config;
        invalid_config.name = "InvalidPredictAsync";
        invalid_config.inputs = { 1, 0 };

        std::future<AndOrNeuralNetworkPredictionResults> future =
            network.predict_async(invalid_config);

        AndOrNeuralNetworkPredictionResults results = future.get();
        ASSERT_EQ(results.value, 0);
    }

    INSTANTIATE_TEST_CASE_P(
        TrainConfigTests,
        AndOrNeuralNetworkTrainParameterizedTest,
        ::testing::Values(
            TrainingConfigTestData{ "AND_Model", 0.1, 1 },
            TrainingConfigTestData{ "OR_Model", 0.5, 2 },
            TrainingConfigTestData{ "XOR_Model", 0.01, 5 },
            TrainingConfigTestData{ "Empty_Model", 0.1, 0 }
        )
    );

    TEST_P(AndOrNeuralNetworkTrainParameterizedTest, Should_TrainSuccessfully_When_MultipleConfigs)
    {
        TrainingConfigTestData config_data = GetParam();

        AndOrNeuralNetworkTrainingConfigurations configurations;
        configurations.name = config_data.model_name;
        configurations.learning_rate = config_data.learning_rate;
        configurations.maximum_learning_epoch = config_data.epochs;
        configurations.inputs = { {0,0},{0,1},{1,0},{1,1} };
        configurations.outputs = { 0,1,1,1 };
        configurations.weights = { 0.5,0.5 };
        configurations.bias = 0.0;
        configurations.callback = [](const AndOrNeuralNetworkTrainingEpochResults&) {};

        AndOrNeuralNetworkTrainingResults results = network.train(configurations);

        EXPECT_EQ(results.epoch_results.size(), config_data.epochs);
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandleHighEpochStress_When_LargeIterations)
    {
        AndOrNeuralNetworkTrainingConfigurations configurations;
        configurations.name = "Stress_Model";
        configurations.learning_rate = 0.01;
        configurations.maximum_learning_epoch = 1000;
        configurations.inputs = { {0,0},{0,1},{1,0},{1,1} };
        configurations.outputs = { 0,1,1,1 };
        configurations.weights = { 0.5,0.5 };
        configurations.bias = 0.0;
        configurations.callback = [](const AndOrNeuralNetworkTrainingEpochResults&) {};

        auto start_time = std::chrono::steady_clock::now();
        AndOrNeuralNetworkTrainingResults results = network.train(configurations);
        auto end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = end_time - start_time;

        EXPECT_EQ(results.epoch_results.size(), 1000);
        EXPECT_LT(elapsed.count(), 2.0);
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandleConcurrentTrainPredict_When_MultiThreaded)
    {
        AndOrNeuralNetworkTrainingConfigurations train_config1;
        train_config1.name = "Thread_Model1";
        train_config1.learning_rate = 0.1;
        train_config1.maximum_learning_epoch = 50;
        train_config1.inputs = { {0,0},{0,1},{1,0},{1,1} };
        train_config1.outputs = { 0,1,1,1 };
        train_config1.weights = { 0.5,0.5 };
        train_config1.bias = 0.0;
        train_config1.callback = [](const AndOrNeuralNetworkTrainingEpochResults&) {};

        AndOrNeuralNetworkTrainingConfigurations train_config2 = train_config1;
        train_config2.name = "Thread_Model2";

        AndOrNeuralNetworkPredictionConfigurations predict_config;
        predict_config.name = "Thread_Model1";
        predict_config.inputs = { 1,1 };

        std::thread thread_train1([&]()
            {
                network.train(train_config1);
            });

        std::thread thread_train2([&]()
            {
                network.train(train_config2);
            });

        std::thread thread_predict([&]()
            {
                AndOrNeuralNetworkPredictionResults results = network.predict(predict_config);
                EXPECT_TRUE(results.value == 0 || results.value == 1);
            });

        thread_train1.join();
        thread_train2.join();
        thread_predict.join();
    }

    TEST_F(AndOrNeuralNetworkTest, Should_HandleAsyncTrainPredict_When_Futures)
    {
        AndOrNeuralNetworkTrainingConfigurations configurations;
        configurations.name = "Async_Model";
        configurations.learning_rate = 0.1;
        configurations.maximum_learning_epoch = 10;
        configurations.inputs = { {0,0},{0,1},{1,0},{1,1} };
        configurations.outputs = { 0,1,1,1 };
        configurations.weights = { 0.5,0.5 };
        configurations.bias = 0.0;
        configurations.callback = [](const AndOrNeuralNetworkTrainingEpochResults&) {};

        std::future<AndOrNeuralNetworkTrainingResults> future_train =
            network.train_async(configurations);

        AndOrNeuralNetworkTrainingResults train_results = future_train.get();
        EXPECT_EQ(train_results.epoch_results.size(), 10);

        AndOrNeuralNetworkPredictionConfigurations predict_config;
        predict_config.name = "Async_Model";
        predict_config.inputs = { 1,0 };

        std::future<AndOrNeuralNetworkPredictionResults> future_predict =
            network.predict_async(predict_config);

        AndOrNeuralNetworkPredictionResults predict_results = future_predict.get();
        EXPECT_TRUE(predict_results.value == 0 || predict_results.value == 1);
    }   
}
