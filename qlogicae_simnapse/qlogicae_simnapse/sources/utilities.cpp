#include "pch.hpp"

#include "../includes/utilities.hpp"

namespace QLogicaeSimNapse
{
    Utilities::Utilities()
    {

    }

    Utilities::~Utilities()
    {

    }

    bool Utilities::setup()
    {
        try
        {
            QLogicaeCore::Result<void> result;

            setup(result);

            return result.is_status_safe();
        }
        catch (const std::exception& exception)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "QLogicaeCore::Utilities::setup()",
                exception.what()
            );

            return false;
        }
    }

    void Utilities::setup(
        QLogicaeCore::Result<void>& result
    )
    {        
        DEFAULT_SETTINGS_SCREEN_TYPE_KEY =
            "settings__screen_type";

        DEFAULT_SETTINGS_SCREEN_TYPE_VALUE =
            3;

        DEFAULT_EVALUATION_CURRENT_EPOCH =
            1;

        DEFAULT_EVALUATION_FINAL_EPOCH =
            10;

        DEFAULT_EVALUATION_SLIDER_VALUE =
            1;

        DEFAULT_EVALUATION_ERROR_RATE =
            "0.00";

        DEFAULT_EVALUATION_TABLE =
        {
            { "0", "0", "0", "0", "0", "0" },
            { "1", "0", "0", "0", "0", "0" },
            { "0", "1", "0", "0", "0", "0" },
            { "1", "1", "0", "0", "0", "0" }
        };

        

        result.set_to_good_status_without_value();
    }

    std::future<bool> Utilities::setup_async()
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

    void Utilities::setup_async(
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

    void Utilities::setup_async(
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

                setup(result);

                promise.set_value();
            }
        );

        result.set_to_good_status_with_value(
            std::move(future)
        );
    }

    void Utilities::setup_async(
        const std::function<void(QLogicaeCore::Result<void>& result)>& callback
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, callback]() mutable
            {
                QLogicaeCore::Result<void> result;

                setup(result);

                callback(
                    result
                );
            }
        );
    }


    bool Utilities::terminate()
    {
        try
        {
            QLogicaeCore::Result<void> result;

            terminate(result);

            return result.is_status_safe();
        }
        catch (const std::exception& exception)
        {
            QLogicaeCore::LOGGER.handle_exception_async(
                "QLogicaeCore::Utilities::terminate()",
                exception.what()
            );

            return false;
        }
    }

    void Utilities::terminate(
        QLogicaeCore::Result<void>& result
    )
    {
        result.set_to_good_status_without_value();
    }

    std::future<bool> Utilities::terminate_async()
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

    void Utilities::terminate_async(
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

    void Utilities::terminate_async(
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

                terminate(result);

                promise.set_value();
            }
        );

        result.set_to_good_status_with_value(
            std::move(future)
        );
    }

    void Utilities::terminate_async(
        const std::function<void(QLogicaeCore::Result<void>& result)>& callback
    )
    {
        boost::asio::post(
            QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
            [this, callback]() mutable
            {
                QLogicaeCore::Result<void> result;

                terminate(result);

                callback(
                    result
                );
            }
        );
    }

    Utilities& Utilities::get_instance()
    {
        static Utilities instance;

        return instance;
    }

    void Utilities::get_instance(
        QLogicaeCore::Result<Utilities*>& results
    )
    {
        results.set_to_good_status_with_value(
            &get_instance()
        );
    }
}
