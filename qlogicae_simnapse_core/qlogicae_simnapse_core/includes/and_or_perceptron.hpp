#pragma once

#include "and_or_neural_network_training_epoch_results.hpp"
#include "and_or_neural_network_training_configurations.hpp"
#include "and_or_neural_network_training_results.hpp"

#include "and_or_neural_network_prediction_configurations.hpp"
#include "and_or_neural_network_prediction_results.hpp"

#include "and_or_perceptron_activator.hpp"

#include "qlogicae_core/includes/time.hpp"
#include "qlogicae_core/includes/result.hpp"
#include "qlogicae_core/includes/logger.hpp"
#include "qlogicae_core/includes/utilities.hpp"

namespace QLogicaeSimNapseCore
{
    class AndOrPerceptron
    {
    public:
        AndOrPerceptron();

        ~AndOrPerceptron();

        AndOrPerceptron(
            const AndOrPerceptron& instance
        ) = default;

        AndOrPerceptron(
            AndOrPerceptron&& instance
        ) noexcept = delete;

        AndOrPerceptron& operator = (
            AndOrPerceptron&& instance
            ) = default;

        AndOrPerceptron& operator = (
            const AndOrPerceptron& instance
            ) = delete;

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

        static AndOrPerceptron& get_instance();

        static void get_instance(
            QLogicaeCore::Result<AndOrPerceptron*>& result
        );

    protected:        
        AndOrNeuralNetworkTrainingConfigurations _configurations;
    };
}

/*


#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Perceptron {
private:
    std::vector<double> weights;
    double bias;
    double learning_rate;

public:
    Perceptron(size_t input_size, double lr = 0.1)
        : weights(input_size, 0.0), bias(0.0), learning_rate(lr) {}

    int activate(const std::vector<int>& inputs) const {
        double sum = bias;
        for(size_t i = 0; i < weights.size(); ++i)
            sum += weights[i] * inputs[i];
        return (sum >= 0) ? 1 : 0;
    }

    void train(const std::vector<std::vector<int>>& X, const std::vector<int>& y, int epochs = 10)
    {
        for(int epoch = 0; epoch < epochs; ++epoch)
        {
            for(size_t i = 0; i < X.size(); ++i)
            {
                int pred = activate(X[i]);
                int error = y[i] - pred;
                for(size_t j = 0; j < weights.size(); ++j)
                {
                    weights[j] += learning_rate * error * X[i][j];
                }
                bias += learning_rate * error;
            }
        }
    }

    void print_truth_table(const std::string& name) const {
        std::cout << name << " Perceptron Truth Table:\n";
        std::vector<std::vector<int>> inputs = {{0,0},{0,1},{1,0},{1,1}};
        for(const auto& inp : inputs)
            std::cout << inp[0] << " " << inp[1] << " -> " << activate(inp) << "\n";
        std::cout << "\n";
    }

    void print_weights() const {
        std::cout << "Weights: ";
        for(auto w : weights) std::cout << w << " ";
        std::cout << "Bias: " << bias << "\n";
    }
};

int main() {
    std::vector<std::vector<int>> inputs = {{0,0},{0,1},{1,0},{1,1}};

    // AND
    std::vector<int> outputs_and = {0,0,0,1};
    Perceptron and_perceptron(2);
    and_perceptron.train(inputs, outputs_and, 10);
    and_perceptron.print_truth_table("AND");
    and_perceptron.print_weights();

    // OR
    std::vector<int> outputs_or = {0,1,1,1};
    Perceptron or_perceptron(2);
    or_perceptron.train(inputs, outputs_or, 10);
    or_perceptron.print_truth_table("OR");
    or_perceptron.print_weights();

    return 0;
}

*/
