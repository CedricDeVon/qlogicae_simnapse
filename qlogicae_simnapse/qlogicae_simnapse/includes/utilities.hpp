#pragma once

#include "assembly.hpp"

#include "qlogicae_simnapse_core/includes/and_or_neural_network.hpp"
#include "qlogicae_simnapse_core/includes/and_or_neural_network_configurations.hpp"
#include "qlogicae_simnapse_core/includes/and_or_neural_network_training_results.hpp"
#include "qlogicae_simnapse_core/includes/and_or_neural_network_prediction_results.hpp"

#include "qlogicae_core/includes/result.hpp"
#include "qlogicae_core/includes/utilities.hpp"
#include "qlogicae_core/includes/rocksdb_database.hpp"
#include "qlogicae_core/includes/application_utilities.hpp"

namespace QLogicaeSimNapse
{
    class Utilities
    {
    public:       
        int DEFAULT_EVALUATION_CURRENT_EPOCH;

        int DEFAULT_EVALUATION_FINAL_EPOCH;

        int DEFAULT_EVALUATION_SLIDER_VALUE;

        std::string DEFAULT_SETTINGS_SCREEN_TYPE_KEY;

        int DEFAULT_SETTINGS_SCREEN_TYPE_VALUE;

        std::string DEFAULT_EVALUATION_ERROR_RATE;

        std::vector<std::vector<std::string>> DEFAULT_EVALUATION_TABLE;

        QLogicaeSimNapseCore::AndOrNeuralNetworkTrainingConfigurations NEURAL_NETWORK_TRAINING_CONFIGURATIONS;

        QLogicaeSimNapseCore::AndOrNeuralNetworkTrainingResults NEURAL_NETWORK_TRAINING_RESULTS;

        QLogicaeSimNapseCore::AndOrNeuralNetworkPredictionResults NEURAL_NETWORK_PREDICTION_RESULTS;

        std::string DEFAULT_EVALUATION_NAME;

        QString DEFAULT_WINDOW_ICON_RESOURCE_LINK;

        QString DEFAULT_FONT_RESOURCE_LINK;

        QString DEFAULT_WIDGET_STYLE;

        QString DEFAULT_PUSH_BUTTON_WIDGET_STYLE_NORMAL;

        QString DEFAULT_PUSH_BUTTON_WIDGET_STYLE_CLICKED;

        std::vector<std::vector<int>> DEFAULT_EVALUATION_INPUTS;

        std::vector<int> DEFAULT_EVALUATION_OUTPUTS;

        std::vector<double> DEFAULT_EVALUATION_WEIGHTS;

        double DEFAULT_EVALUATION_BIAS;

        double DEFAULT_EVALUATION_LEARNING_RATE;

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


        static Utilities& get_instance();

        static void get_instance(
            QLogicaeCore::Result<Utilities*>& result
        );

    protected:
        Utilities();

        ~Utilities();

        Utilities(
            const Utilities& instance
        ) = default;

        Utilities(
            Utilities&& instance
        ) noexcept = delete;

        Utilities& operator = (
            Utilities&& instance
            ) = default;

        Utilities& operator = (
            const Utilities& instance
            ) = delete;
    };
    
    inline static Utilities& UTILITIES =
        Utilities::get_instance();
}
