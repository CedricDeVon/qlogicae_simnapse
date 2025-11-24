#include "pch.hpp"

#include "../includes/and_or_perceptron_activator.hpp"

namespace QLogicaeSimNapseCore
{
	AndOrPerceptronActivator::AndOrPerceptronActivator()
	{

	}

	AndOrPerceptronActivator::~AndOrPerceptronActivator()
	{

	}

    bool AndOrPerceptronActivator::setup()
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
                "QLogicaeSimNapseCore::AndOrPerceptronActivator::setup()",
                exception.what()
            );

            return false;
        }
    }

    void AndOrPerceptronActivator::setup(
        QLogicaeCore::Result<void>& result
    )
    {
        result.set_to_good_status_without_value();
    }

    std::future<bool> AndOrPerceptronActivator::setup_async()
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

    void AndOrPerceptronActivator::setup_async(
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

    void AndOrPerceptronActivator::setup_async(
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

    void AndOrPerceptronActivator::setup_async(
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




    int AndOrPerceptronActivator::get_activation(
        const AndOrPerceptronActivatorConfigurations& configurations
    )
    {
        QLogicaeCore::Result<int> result;

        try
        {
            if (configurations.inputs.size() != 2 ||
                configurations.weights.size() != 2
            )
            {
                return result.get_value();
            }
            
            get_activation(
                result,
                configurations
            );

            return result.get_value();
        }
        catch (const std::exception& exception)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "QLogicaeSimNapseCore::AndOrPerceptronActivator::get_activation()",
                exception.what()
            );

            return result.get_value();
        }
    }

    void AndOrPerceptronActivator::get_activation(
        QLogicaeCore::Result<int>& result,
        const AndOrPerceptronActivatorConfigurations& configurations
    )
    {
        size_t
            index,
            size = configurations.weights.size();

        double sum = configurations.bias;
        
        for (
            index = 0;
            index < size;
            ++index
        )
        {
            sum +=
                configurations.weights[index] *
                configurations.inputs[index];
        }

        result.set_to_good_status_with_value(
            sum >= 0
        );
    }

    std::future<int> AndOrPerceptronActivator::get_activation_async(
        const AndOrPerceptronActivatorConfigurations& configurations
    )
    {
        std::promise<int> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations,
            promise = std::move(promise)]() mutable
            {
                promise.set_value(
                    get_activation(
                        configurations
                    )
                );
            }
        );

        return future;
    }

    void AndOrPerceptronActivator::get_activation_async(
        QLogicaeCore::Result<std::future<int>>& result,
        const AndOrPerceptronActivatorConfigurations& configurations
    )
    {
        std::promise<int> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations,
            promise = std::move(promise)]() mutable
            {
                QLogicaeCore::Result<int> result;

                get_activation(
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

    void AndOrPerceptronActivator::get_activation_async(
        const std::function<void(const int& result)>& callback,
        const AndOrPerceptronActivatorConfigurations& configurations
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations, callback]() mutable
            {
                callback(
                    get_activation(
                        configurations
                    )
                );
            }
        );
    }

    void AndOrPerceptronActivator::get_activation_async(
        const std::function<void(QLogicaeCore::Result<int>& result)>& callback,
        const AndOrPerceptronActivatorConfigurations& configurations
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, configurations, callback]() mutable
            {
                QLogicaeCore::Result<int> result;

                get_activation(
                    result,
                    configurations
                );

                callback(
                    result
                );
            }
        );
    }


    bool AndOrPerceptronActivator::terminate()
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
                "QLogicaeSimNapseCore::AndOrPerceptronActivator::terminate()",
                exception.what()
            );

            return false;
        }
    }

    void AndOrPerceptronActivator::terminate(
        QLogicaeCore::Result<void>& result
    )
    {
        result.set_to_good_status_without_value();
    }

    std::future<bool> AndOrPerceptronActivator::terminate_async()
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

    void AndOrPerceptronActivator::terminate_async(
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

    void AndOrPerceptronActivator::terminate_async(
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

    void AndOrPerceptronActivator::terminate_async(
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

    AndOrPerceptronActivator& AndOrPerceptronActivator::get_instance()
    {
        static AndOrPerceptronActivator instance;

        return instance;
    }

    void AndOrPerceptronActivator::get_instance(
        QLogicaeCore::Result<AndOrPerceptronActivator*>& result
    )
    {        
        result.set_to_good_status_with_value(
            &get_instance()
        );
    }
}
