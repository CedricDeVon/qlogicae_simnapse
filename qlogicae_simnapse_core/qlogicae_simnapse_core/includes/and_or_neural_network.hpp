#pragma once

#include "and_or_perceptron.hpp"
#include "and_or_perceptron_activator.hpp"
#include "and_or_neural_network_configurations.hpp"
#include "and_or_neural_network_training_results.hpp"
#include "and_or_neural_network_prediction_results.hpp"
#include "and_or_perceptron_activator_configurations.hpp"
#include "and_or_neural_network_training_epoch_results.hpp"
#include "and_or_neural_network_training_configurations.hpp"
#include "and_or_neural_network_prediction_configurations.hpp"

#include "qlogicae_core/includes/result.hpp"
#include "qlogicae_core/includes/logger.hpp"
#include "qlogicae_core/includes/utilities.hpp"

namespace QLogicaeSimNapseCore
{
    class AndOrNeuralNetwork
    {
    public:
        bool setup();

        void setup(
            QLogicaeCore::Result<void>& result
        );

        std::future<bool> setup_async();

        void setup_async(
            const std::function<void(const bool& result)>& callback
        );

        void setup_async(
            QLogicaeCore::Result<std::future<void>>& result
        );

        void setup_async(
            const std::function<void(QLogicaeCore::Result<void>& result)>& callback
        );



        AndOrNeuralNetworkTrainingResults train(
            const AndOrNeuralNetworkTrainingConfigurations& configurations
        );

        void train(
            QLogicaeCore::Result<AndOrNeuralNetworkTrainingResults>& result,
            const AndOrNeuralNetworkTrainingConfigurations& configurations
        );

        std::future<AndOrNeuralNetworkTrainingResults> train_async(
            const AndOrNeuralNetworkTrainingConfigurations& configurations
        );

        void train_async(
            const std::function<void(const AndOrNeuralNetworkTrainingResults& result)>& callback,
            const AndOrNeuralNetworkTrainingConfigurations& configurations
        );

        void train_async(
            QLogicaeCore::Result<std::future<AndOrNeuralNetworkTrainingResults>>& result,
            const AndOrNeuralNetworkTrainingConfigurations& configurations
        );

        void train_async(
            const std::function<void(QLogicaeCore::Result<AndOrNeuralNetworkTrainingResults>& result)>& callback,
            const AndOrNeuralNetworkTrainingConfigurations& configurations
        );



        AndOrNeuralNetworkPredictionResults predict(
            const AndOrNeuralNetworkPredictionConfigurations& configurations
        );

        void predict(
            QLogicaeCore::Result<AndOrNeuralNetworkPredictionResults>& result,
            const AndOrNeuralNetworkPredictionConfigurations& configurations
        );

        std::future<AndOrNeuralNetworkPredictionResults> predict_async(
            const AndOrNeuralNetworkPredictionConfigurations& configurations
        );

        void predict_async(
            const std::function<void(const AndOrNeuralNetworkPredictionResults& result)>& callback,
            const AndOrNeuralNetworkPredictionConfigurations& configurations
        );

        void predict_async(
            QLogicaeCore::Result<std::future<AndOrNeuralNetworkPredictionResults>>& result,
            const AndOrNeuralNetworkPredictionConfigurations& configurations
        );

        void predict_async(
            const std::function<void(QLogicaeCore::Result<AndOrNeuralNetworkPredictionResults>& result)>& callback,
            const AndOrNeuralNetworkPredictionConfigurations& configurations
        );



        bool terminate();

        void terminate(
            QLogicaeCore::Result<void>& result
        );

        std::future<bool> terminate_async();

        void terminate_async(
            const std::function<void(const bool& result)>& callback
        );

        void terminate_async(
            QLogicaeCore::Result<std::future<void>>& result
        );

        void terminate_async(
            const std::function<void(QLogicaeCore::Result<void>& result)>& callback
        );

        static AndOrNeuralNetwork& get_instance();

        static void get_instance(
            QLogicaeCore::Result<AndOrNeuralNetwork*>& result
        );

    protected:
        AndOrNeuralNetwork();

        ~AndOrNeuralNetwork();

        AndOrNeuralNetwork(
            const AndOrNeuralNetwork& instance
        ) = default;

        AndOrNeuralNetwork(
            AndOrNeuralNetwork&& instance
        ) noexcept = delete;

        AndOrNeuralNetwork& operator = (
            AndOrNeuralNetwork&& instance
            ) = default;

        AndOrNeuralNetwork& operator = (
            const AndOrNeuralNetwork& instance
            ) = delete;
    };

    inline static AndOrNeuralNetwork& XOR_NEURAL_NETWORK =
        AndOrNeuralNetwork::get_instance();
}
