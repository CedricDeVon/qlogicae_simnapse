#include "pch.hpp"

#include "main.hpp"

int main(int argc, char** argv)
{       
    QLogicaeSimNapseCore::AndOrNeuralNetworkTrainingConfigurations and_training_configurations =
    {
        .name = "&&",
        .maximum_learning_epoch = 100,
        .inputs = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } },
        .outputs = { 0, 0, 0, 1 },
        .weights = { 0.0, 0.0 },
        .bias = 0.0,
        .learning_rate = 1.5,
        .callback = [](const QLogicaeSimNapseCore::AndOrNeuralNetworkTrainingEpochResults& result)
        {
            std::cout << "AND: current_epoch: " << result.current_epoch << "\n";
            std::cout << "timestamp_started: " << result.timestamp_started << "\n";
            std::cout << "timestamp_ended: " << result.timestamp_ended << "\n";
            std::cout << "bias: ";
            std::cout << result.bias << " ";
            std::cout << "\n";
            std::cout << "predictions: ";
            for (size_t i = 0; i < result.predictions.size(); ++i)
            {
                std::cout << result.predictions[i] << " ";
            }
            std::cout << "\n";
            std::cout << "errors: ";
            for (size_t i = 0; i < result.errors.size(); ++i)
            {
                std::cout << result.errors[i] << " ";
            }
            std::cout << "\n";
            std::cout << "model_weights: ";
            for (size_t i = 0; i < result.weights.size(); ++i)
            {
                std::cout << result.weights[i] << " ";
            }            
            std::cout << "\n\n";
        }
    };
    QLogicaeSimNapseCore::AndOrNeuralNetworkTrainingConfigurations or_training_configurations =
    {
        .name = "||",
        .maximum_learning_epoch = 100,
        .inputs = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } },
        .outputs = { 0, 1, 1, 1 },
        .weights = { 0.0, 0.0 },
        .bias = 0.0,
        .learning_rate = 1.5,
        .callback = [](const QLogicaeSimNapseCore::AndOrNeuralNetworkTrainingEpochResults& result)
        {
            std::cout << "OR: current_epoch: " << result.current_epoch << "\n";
            std::cout << "timestamp_started: " << result.timestamp_started << "\n";
            std::cout << "timestamp_ended: " << result.timestamp_ended << "\n";
            std::cout << "bias: ";
            std::cout << result.bias << " ";
            std::cout << "\n";
            std::cout << "predictions: ";
            for (size_t i = 0; i < result.predictions.size(); ++i)
            {
                std::cout << result.predictions[i] << " ";
            }
            std::cout << "\n";
            std::cout << "errors: ";
            for (size_t i = 0; i < result.errors.size(); ++i)
            {
                std::cout << result.errors[i] << " ";
            }
            std::cout << "\n";
            std::cout << "model_weights: ";
            for (size_t i = 0; i < result.weights.size(); ++i)
            {
                std::cout << result.weights[i] << " ";
            }
            std::cout << "\n\n";
        }
    };

    QLogicaeSimNapseCore::AND_OR_NEURAL_NETWORK.train(
            and_training_configurations
        );
    
    QLogicaeSimNapseCore::AND_OR_NEURAL_NETWORK.train(
            or_training_configurations
        );

    std::vector<std::string> models = { "||", "&&" };
    std::vector<std::vector<int>> inputs = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };

    for (size_t i = 0; i < models.size(); ++i)
    {
        for (size_t j = 0; j < inputs.size(); ++j)
        {
            QLogicaeSimNapseCore::AndOrNeuralNetworkPredictionConfigurations prediction_configurations =
            {
                .name = models[i],
                .inputs = inputs[j]
            };
            QLogicaeSimNapseCore::AndOrNeuralNetworkPredictionResults prediction_results =
                QLogicaeSimNapseCore::AND_OR_NEURAL_NETWORK.predict(
                    prediction_configurations
                );
            std::cout << inputs[j][0] << " " << models[i] << " " << inputs[j][1] << " = " << prediction_results.value << "\n";
        }        
    }
    
    bool exit_code;
    std::cin >> exit_code;

    return 0;
}

namespace QLogicaeSimNapseSandbox
{

}
