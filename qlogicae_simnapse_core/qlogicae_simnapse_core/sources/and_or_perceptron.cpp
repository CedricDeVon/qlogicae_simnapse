#include "pch.hpp"

#include "../includes/and_or_perceptron.hpp"

namespace QLogicaeSimNapseCore
{
    AndOrPerceptron::AndOrPerceptron()
    {

    }

    AndOrPerceptron::~AndOrPerceptron()
    {

    }

    bool AndOrPerceptron::setup()
    {
        try
        {
            QLogicaeCore::Result<void> result;

            setup(
                result
            );

            return result.is_status_safe();
        }
        catch (const std::exception& exception)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "QLogicaeSimNapseCore::AndOrPerceptron::setup()",
                exception.what()
            );

            return false;
        }
    }

    void AndOrPerceptron::setup(
        QLogicaeCore::Result<void>& result
    )
    {
        result.set_to_good_status_without_value();
    }

    std::future<bool> AndOrPerceptron::setup_async()
    {
        std::promise<bool> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this,
            promise = std::move(promise)]() mutable
            {
                promise.set_value(
                    setup()
                );
            }
        );

        return future;
    }

    void AndOrPerceptron::setup_async(
        QLogicaeCore::Result<std::future<void>>& result
    )
    {
        std::promise<void> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this,
            promise = std::move(promise)]() mutable
            {
                QLogicaeCore::Result<void> result;

                setup(
                    result
                );

                promise.set_value();
            }
        );

        result.set_to_good_status_with_value(
            std::move(future)
        );
    }

    void AndOrPerceptron::setup_async(
        const std::function<void(const bool& result)>& callback
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, callback]() mutable
            {
                callback(
                    setup()
                );
            }
        );
    }

    void AndOrPerceptron::setup_async(
        const std::function<void(QLogicaeCore::Result<void>& result)>& callback
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, callback]() mutable
            {
                QLogicaeCore::Result<void> result;

                setup(
                    result
                );

                callback(
                    result
                );
            }
        );
    }

    AndOrNeuralNetworkTrainingResults AndOrPerceptron::train(
        const AndOrNeuralNetworkTrainingConfigurations& configurations
    )
    {
        QLogicaeCore::Result<AndOrNeuralNetworkTrainingResults> result;
        
        try
        {
            if (configurations.name.empty() ||
                configurations.maximum_learning_epoch == 0 ||
                configurations.inputs.size() != 4 ||
                configurations.outputs.size() != 4 ||
                configurations.weights.size() != 2 ||
                configurations.learning_rate <= 0.0
            )
            {
                return result.get_value();
            }

            train(
                result,
                configurations
            );

            return result.get_value();
        }
        catch (const std::exception& exception)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "QLogicaeSimNapseCore::AndOrPerceptron::train()",
                exception.what()
            );

            return result.get_value();
        }
    }

    void AndOrPerceptron::train(
        QLogicaeCore::Result<AndOrNeuralNetworkTrainingResults>& result,
        const AndOrNeuralNetworkTrainingConfigurations& configurations
    )
    {
        _configurations = configurations;

        AndOrNeuralNetworkTrainingResults& training_results =
            result.get_value();

        size_t
            input_index,
            model_weight_index,
            current_learning_epoch,
            configurations_maximum_learning_epoch =
                _configurations.maximum_learning_epoch;

        int
            prediction,
            error;

        double
            weight,
            bias,
            configurations_model_learning_rate =
                _configurations.learning_rate;

        training_results.epoch_results =
            std::vector<AndOrNeuralNetworkTrainingEpochResults>(
                _configurations.maximum_learning_epoch
            );
        training_results.timestamp_started =
            QLogicaeCore::TIME.now();

        AndOrNeuralNetworkTrainingEpochResults& epoch_results =
            training_results.epoch_results[0];

        for (current_learning_epoch = 0;
            current_learning_epoch < configurations_maximum_learning_epoch;
            ++current_learning_epoch
            )
        {
            epoch_results =
                training_results.epoch_results[current_learning_epoch];
            epoch_results.current_epoch = current_learning_epoch + 1;
            epoch_results.timestamp_started = QLogicaeCore::TIME.now();

            for (input_index = 0;
                input_index < 4;
                ++input_index
                )
            {
                prediction = AND_OR_PERCEPTRON_ACTIVATOR.get_activation(
                    {
                        .inputs = _configurations.inputs[input_index],
                        .weights = _configurations.weights,
                        .bias = _configurations.bias
                    }
                );

                epoch_results.predictions[input_index] = prediction;

                error = _configurations.outputs[input_index] - prediction;
                epoch_results.errors[input_index] = error;

                for (model_weight_index = 0;
                    model_weight_index < 2;
                    ++model_weight_index
                    )
                {
                    weight = _configurations.weights[model_weight_index] +
                        (configurations_model_learning_rate *
                        error * _configurations.inputs[input_index][model_weight_index]);

                    _configurations.weights[model_weight_index] =
                        epoch_results.weights[model_weight_index] =
                            weight;
                }

                bias = _configurations.bias +
                    (configurations_model_learning_rate *
                    error);

                _configurations.bias =
                    epoch_results.bias =
                        bias;
            }

            epoch_results.timestamp_ended =
                QLogicaeCore::TIME.now();

            _configurations.callback(
                epoch_results
            );
        }

        training_results.timestamp_ended =
            QLogicaeCore::TIME.now();

        result.set_status_to_good();
    }

    std::future<AndOrNeuralNetworkTrainingResults> AndOrPerceptron::train_async(
        const AndOrNeuralNetworkTrainingConfigurations& configurations
    )
    {
        std::promise<AndOrNeuralNetworkTrainingResults> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations,
            promise = std::move(promise)]() mutable
            {
                promise.set_value(
                    train(
                        configurations
                    )
                );
            }
        );

        return future;
    }

    void AndOrPerceptron::train_async(
        const std::function<void(const AndOrNeuralNetworkTrainingResults& result)>& callback,
        const AndOrNeuralNetworkTrainingConfigurations& configurations
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations, callback]() mutable
            {
                callback(
                    train(
                        configurations
                    )
                );
            }
        );
    }

    void AndOrPerceptron::train_async(
        QLogicaeCore::Result<std::future<AndOrNeuralNetworkTrainingResults>>& result,
        const AndOrNeuralNetworkTrainingConfigurations& configurations
    )
    {
        std::promise<AndOrNeuralNetworkTrainingResults> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations,
            promise = std::move(promise)]() mutable
            {
                QLogicaeCore::Result<AndOrNeuralNetworkTrainingResults> result;

                train(
                    result,
                    configurations
                );

                promise.set_value(
                    result.get_value()
                );
            }
        );

        result.set_to_good_status_with_value(
            std::move(future)
        );
    }

    void AndOrPerceptron::train_async(
        const std::function<void(QLogicaeCore::Result<AndOrNeuralNetworkTrainingResults>& result)>& callback,
        const AndOrNeuralNetworkTrainingConfigurations& configurations
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations, callback]() mutable
            {
                QLogicaeCore::Result<AndOrNeuralNetworkTrainingResults> result;

                train(
                    result,
                    configurations
                );

                callback(
                    result
                );
            }
        );
    }





    AndOrNeuralNetworkPredictionResults AndOrPerceptron::predict(
        const AndOrNeuralNetworkPredictionConfigurations& configurations
    )
    {
        QLogicaeCore::Result<AndOrNeuralNetworkPredictionResults> result;
        
        try
        {
            if (configurations.inputs.size() != 2)
            {
                return result.get_value();
            }

            predict(
                result,
                configurations
            );

            return result.get_value();
        }
        catch (const std::exception& exception)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "QLogicaeSimNapseCore::AndOrPerceptron::predict()",
                exception.what()
            );

            return result.get_value();
        }
    }

    void AndOrPerceptron::predict(
        QLogicaeCore::Result<AndOrNeuralNetworkPredictionResults>& result,
        const AndOrNeuralNetworkPredictionConfigurations& configurations
    )
    {
        AndOrNeuralNetworkPredictionResults& prediction_results = result.get_value();
        
        prediction_results.timestamp_started = QLogicaeCore::TIME.now();
        prediction_results.value = AND_OR_PERCEPTRON_ACTIVATOR.get_activation(
            {
                .inputs = configurations.inputs,
                .weights = _configurations.weights,
                .bias = _configurations.bias
            }
        );
        prediction_results.timestamp_started = QLogicaeCore::TIME.now();

        result.set_to_good_status_with_value(
            prediction_results
        );
    }

    std::future<AndOrNeuralNetworkPredictionResults> AndOrPerceptron::predict_async(
        const AndOrNeuralNetworkPredictionConfigurations& configurations
    )
    {
        std::promise<AndOrNeuralNetworkPredictionResults> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations,
            promise = std::move(promise)]() mutable
            {
                promise.set_value(
                    predict(
                        configurations
                    )
                );
            }
        );

        return future;
    }

    void AndOrPerceptron::predict_async(
        const std::function<void(const AndOrNeuralNetworkPredictionResults& result)>& callback,
        const AndOrNeuralNetworkPredictionConfigurations& configurations
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations, callback]() mutable
            {
                callback(
                    predict(
                        configurations
                    )
                );
            }
        );
    }

    void AndOrPerceptron::predict_async(
        QLogicaeCore::Result<std::future<AndOrNeuralNetworkPredictionResults>>& result,
        const AndOrNeuralNetworkPredictionConfigurations& configurations
    )
    {
        std::promise<AndOrNeuralNetworkPredictionResults> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations,
            promise = std::move(promise)]() mutable
            {
                QLogicaeCore::Result<AndOrNeuralNetworkPredictionResults> result;

                predict(
                    result,
                    configurations
                );

                promise.set_value(
                    result.get_value()
                );
            }
        );

        result.set_to_good_status_with_value(
            std::move(future)
        );
    }

    void AndOrPerceptron::predict_async(
        const std::function<void(QLogicaeCore::Result<AndOrNeuralNetworkPredictionResults>& result)>& callback,
        const AndOrNeuralNetworkPredictionConfigurations& configurations
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations, callback]() mutable
            {
                QLogicaeCore::Result<AndOrNeuralNetworkPredictionResults> result;

                predict(
                    result,
                    configurations
                );

                callback(
                    result
                );
            }
        );
    }

    bool AndOrPerceptron::terminate()
    {
        try
        {
            QLogicaeCore::Result<void> result;

            terminate(
                result
            );

            return result.is_status_safe();
        }
        catch (const std::exception& exception)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "QLogicaeSimNapseCore::AndOrPerceptron::terminate()",
                exception.what()
            );

            return false;
        }
    }

    void AndOrPerceptron::terminate(
        QLogicaeCore::Result<void>& result
    )
    {
        result.set_to_good_status_without_value();
    }

    std::future<bool> AndOrPerceptron::terminate_async()
    {
        std::promise<bool> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this,
            promise = std::move(promise)]() mutable
            {
                promise.set_value(
                    terminate()
                );
            }
        );

        return future;
    }

    void AndOrPerceptron::terminate_async(
        QLogicaeCore::Result<std::future<void>>& result
    )
    {
        std::promise<void> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this,
            promise = std::move(promise)]() mutable
            {
                QLogicaeCore::Result<void> result;

                terminate(
                    result
                );

                promise.set_value();
            }
        );

        result.set_to_good_status_with_value(
            std::move(future)
        );
    }

    void AndOrPerceptron::terminate_async(
        const std::function<void(const bool& result)>& callback
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, callback]() mutable
            {
                callback(
                    terminate()
                );
            }
        );
    }

    void AndOrPerceptron::terminate_async(
        const std::function<void(QLogicaeCore::Result<void>& result)>& callback
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, callback]() mutable
            {
                QLogicaeCore::Result<void> result;

                terminate(
                    result
                );

                callback(
                    result
                );
            }
        );
    }

    AndOrPerceptron& AndOrPerceptron::get_instance()
    {
        static AndOrPerceptron instance;

        return instance;
    }

    void AndOrPerceptron::get_instance(
        QLogicaeCore::Result<AndOrPerceptron*>& result
    )
    {        
        static AndOrPerceptron instance;

        result.set_to_good_status_with_value(
            &get_instance()
        );
    }
}
