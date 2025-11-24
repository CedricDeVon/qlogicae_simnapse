#include "pch.hpp"

#include "../includes/and_or_neural_network.hpp"

namespace QLogicaeSimNapseCore
{
    AndOrNeuralNetwork::AndOrNeuralNetwork()
    {

    }

    AndOrNeuralNetwork::~AndOrNeuralNetwork()
    {

    }

    bool AndOrNeuralNetwork::setup()
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
                "QLogicaeSimNapseCore::AndOrNeuralNetwork::setup()",
                exception.what()
            );

            return false;
        }
    }

    void AndOrNeuralNetwork::setup(
        QLogicaeCore::Result<void>& result
    )
    {
        result.set_to_good_status_without_value();
    }

    std::future<bool> AndOrNeuralNetwork::setup_async()
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

    void AndOrNeuralNetwork::setup_async(
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

    void AndOrNeuralNetwork::setup_async(
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

    void AndOrNeuralNetwork::setup_async(
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


    AndOrNeuralNetworkTrainingResults AndOrNeuralNetwork::train(
        const AndOrNeuralNetworkTrainingConfigurations& configurations
    )
    {
        QLogicaeCore::Result<AndOrNeuralNetworkTrainingResults> result;
        
        try
        {
            train(
                result,
                configurations
            );

            return result.get_value();
        }
        catch (const std::exception& exception)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "QLogicaeSimNapseCore::AndOrNeuralNetwork::train()",
                exception.what()
            );

            return result.get_value();
        }
    }

    void AndOrNeuralNetwork::train(
        QLogicaeCore::Result<AndOrNeuralNetworkTrainingResults>& result,
        const AndOrNeuralNetworkTrainingConfigurations& configurations
    )
    {        
        std::string configurations_model_name =
            configurations.name;

        if (!_models.contains(configurations_model_name))
        {
            _models[configurations_model_name] = AndOrPerceptron();
        }

        result.set_to_good_status_with_value(
            _models[configurations_model_name].train(
                configurations
            )
        );
    }

    std::future<AndOrNeuralNetworkTrainingResults> AndOrNeuralNetwork::train_async(
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

    void AndOrNeuralNetwork::train_async(
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

    void AndOrNeuralNetwork::train_async(
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

    void AndOrNeuralNetwork::train_async(
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





    AndOrNeuralNetworkPredictionResults AndOrNeuralNetwork::predict(
        const AndOrNeuralNetworkPredictionConfigurations& configurations
    )
    {
        QLogicaeCore::Result<AndOrNeuralNetworkPredictionResults> result;
        
        try
        {
            predict(
                result,
                configurations
            );

            return result.get_value();
        }
        catch (const std::exception& exception)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "QLogicaeSimNapseCore::AndOrNeuralNetwork::predict()",
                exception.what()
            );

            return result.get_value();
        }
    }

    void AndOrNeuralNetwork::predict(
        QLogicaeCore::Result<AndOrNeuralNetworkPredictionResults>& result,
        const AndOrNeuralNetworkPredictionConfigurations& configurations
    )
    {
        std::string configurations_model_name =
            configurations.name;

        if (!_models.contains(configurations_model_name))
        {
            return result.set_to_bad_status_without_value();
        }

        result.set_to_good_status_with_value(
            _models[configurations_model_name].predict(
                configurations
            )
        );
    }

    std::future<AndOrNeuralNetworkPredictionResults> AndOrNeuralNetwork::predict_async(
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

    void AndOrNeuralNetwork::predict_async(
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

    void AndOrNeuralNetwork::predict_async(
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

    void AndOrNeuralNetwork::predict_async(
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

    bool AndOrNeuralNetwork::terminate()
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
                "QLogicaeSimNapseCore::AndOrNeuralNetwork::terminate()",
                exception.what()
            );

            return false;
        }
    }

    void AndOrNeuralNetwork::terminate(
        QLogicaeCore::Result<void>& result
    )
    {
        result.set_to_good_status_without_value();
    }

    std::future<bool> AndOrNeuralNetwork::terminate_async()
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

    void AndOrNeuralNetwork::terminate_async(
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

    void AndOrNeuralNetwork::terminate_async(
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

    void AndOrNeuralNetwork::terminate_async(
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

    AndOrNeuralNetwork& AndOrNeuralNetwork::get_instance()
    {
        static AndOrNeuralNetwork instance;

        return instance;
    }

    void AndOrNeuralNetwork::get_instance(
        QLogicaeCore::Result<AndOrNeuralNetwork*>& result
    )
    {
        static AndOrNeuralNetwork instance;

        result.set_to_good_status_with_value(
            &instance
        );
    }
}
