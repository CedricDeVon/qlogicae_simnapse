#include "pch.hpp"

#include "../includes/xor_multi_layered_perceptron_activator.hpp"

namespace QLogicaeSimNapseCore
{
	XORMultiLayeredPerceptronActivator::XORMultiLayeredPerceptronActivator()
	{

	}

	XORMultiLayeredPerceptronActivator::~XORMultiLayeredPerceptronActivator()
	{

	}

    bool XORMultiLayeredPerceptronActivator::setup()
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
                "QLogicaeSimNapseCore::XORMultiLayeredPerceptronActivator::setup()",
                exception.what()
            );

            return false;
        }
    }

    void XORMultiLayeredPerceptronActivator::setup(
        QLogicaeCore::Result<void>& result
    )
    {
        result.set_to_good_status_without_value();
    }

    std::future<bool> XORMultiLayeredPerceptronActivator::setup_async()
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

    void XORMultiLayeredPerceptronActivator::setup_async(
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

    void XORMultiLayeredPerceptronActivator::setup_async(
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

    void XORMultiLayeredPerceptronActivator::setup_async(
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




    double XORMultiLayeredPerceptronActivator::get_sigmoid_activation(
        const double& x
    )
    {
        try
        {
            QLogicaeCore::Result<double> result;

            get_sigmoid_activation(
                result,
                x
            );

            return result.get_value();
        }
        catch (const std::exception& exception)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "QLogicaeSimNapseCore::XORMultiLayeredPerceptronActivator::get_sigmoid_activation()",
                exception.what()
            );

            return false;
        }
    }

    void XORMultiLayeredPerceptronActivator::get_sigmoid_activation(
        QLogicaeCore::Result<double>& result,
        const double& x
    )
    {
        result.set_to_good_status_with_value(
            1.0 / (1.0 + std::exp(-x))
        );
    }

    std::future<double> XORMultiLayeredPerceptronActivator::get_sigmoid_activation_async(
        const double& x
    )
    {
        std::promise<double> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, x,
            promise = std::move(promise)]() mutable
            {
                promise.set_value(
                    get_sigmoid_activation(
                        x
                    )
                );
            }
        );

        return future;
    }

    void XORMultiLayeredPerceptronActivator::get_sigmoid_activation_async(
        QLogicaeCore::Result<std::future<double>>& result,
        const double& x
    )
    {
        std::promise<double> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, x,
            promise = std::move(promise)]() mutable
            {
                QLogicaeCore::Result<double> result;

                get_sigmoid_activation(
                    result,
                    x
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

    void XORMultiLayeredPerceptronActivator::get_sigmoid_activation_async(
        const std::function<void(const double& result)>& callback,
        const double& x
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, x, callback]() mutable
            {
                callback(
                    get_sigmoid_activation(
                        x
                    )
                );
            }
        );
    }

    void XORMultiLayeredPerceptronActivator::get_sigmoid_activation_async(
        const std::function<void(QLogicaeCore::Result<double>& result)>& callback,
        const double& x
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, x, callback]() mutable
            {
                QLogicaeCore::Result<double> result;

                get_sigmoid_activation(
                    result,
                    x
                );

                callback(
                    result
                );
            }
        );
    }

    double XORMultiLayeredPerceptronActivator::get_sigmoid_derivative(
        const double& x
    )
    {
        try
        {
            QLogicaeCore::Result<double> result;

            get_sigmoid_derivative(
                result,
                x
            );

            return result.get_value();
        }
        catch (const std::exception& exception)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "QLogicaeSimNapseCore::XORMultiLayeredPerceptronActivator::get_sigmoid_derivative()",
                exception.what()
            );

            return false;
        }
    }

    void XORMultiLayeredPerceptronActivator::get_sigmoid_derivative(
        QLogicaeCore::Result<double>& result,
        const double& x
    )
    {
        result.set_to_good_status_with_value(
            x * (1 - x)
        );
    }

    std::future<double> XORMultiLayeredPerceptronActivator::get_sigmoid_derivative_async(
        const double& x
    )
    {
        std::promise<double> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, x,
            promise = std::move(promise)]() mutable
            {
                promise.set_value(
                    get_sigmoid_derivative(
                        x
                    )
                );
            }
        );

        return future;
    }

    void XORMultiLayeredPerceptronActivator::get_sigmoid_derivative_async(
        QLogicaeCore::Result<std::future<double>>& result,
        const double& x
    )
    {
        std::promise<double> promise;
        auto future = promise.get_future();

        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, x,
            promise = std::move(promise)]() mutable
            {
                QLogicaeCore::Result<double> result;

                get_sigmoid_derivative(
                    result,
                    x
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

    void XORMultiLayeredPerceptronActivator::get_sigmoid_derivative_async(
        const std::function<void(const double& result)>& callback,
        const double& x
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, x, callback]() mutable
            {
                callback(
                    get_sigmoid_derivative(
                        x
                    )
                );
            }
        );
    }

    void XORMultiLayeredPerceptronActivator::get_sigmoid_derivative_async(
        const std::function<void(QLogicaeCore::Result<double>& result)>& callback,
        const double& x
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, x, callback]() mutable
            {
                QLogicaeCore::Result<double> result;

                get_sigmoid_derivative(
                    result,
                    x
                );

                callback(
                    result
                );
            }
        );
    }

    bool XORMultiLayeredPerceptronActivator::terminate()
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
                "QLogicaeSimNapseCore::XORMultiLayeredPerceptronActivator::terminate()",
                exception.what()
            );

            return false;
        }
    }

    void XORMultiLayeredPerceptronActivator::terminate(
        QLogicaeCore::Result<void>& result
    )
    {
        result.set_to_good_status_without_value();
    }

    std::future<bool> XORMultiLayeredPerceptronActivator::terminate_async()
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

    void XORMultiLayeredPerceptronActivator::terminate_async(
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

    void XORMultiLayeredPerceptronActivator::terminate_async(
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

    void XORMultiLayeredPerceptronActivator::terminate_async(
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
}
