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
            "0";

        DEFAULT_EVALUATION_TABLE =
        {
            { "0", "0", "0", "0", "0" },
            { "1", "0", "0", "0", "0" },
            { "0", "1", "0", "0", "0" },
            { "1", "1", "1", "0", "0" }
        };

        DEFAULT_EVALUATION_NAME =
            "Perceptron";

        DEFAULT_EVALUATION_INPUTS =
        { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };

        DEFAULT_EVALUATION_OUTPUTS =
        { 0, 0, 0, 1 };

        DEFAULT_EVALUATION_WEIGHTS =
        { 0.0, 0.0 };

        DEFAULT_EVALUATION_BIAS =
            0.0;

        DEFAULT_EVALUATION_LEARNING_RATE =
            1.5;

        DEFAULT_WINDOW_ICON_RESOURCE_LINK =
            ":/qlogicae/application/assets/application.ico";

        DEFAULT_FONT_RESOURCE_LINK =
            ":/qlogicae/application/assets/fonts/Inter/static/Inter_18pt-Regular.ttf";

        DEFAULT_WIDGET_STYLE =
            R"(
                QWidget {
                    font-family: "%1";
                }
            )";

        DEFAULT_PUSH_BUTTON_WIDGET_STYLE_NORMAL =
            "QPushButton {"
            "background: #2B2D30;"
            "border-radius: 4px;"
            "}"
            "QPushButton:hover {"
            "background: #4E5157;"
            "}"
            "QPushButton:pressed {"
            "background: #2B2D30;"
            "}";

        DEFAULT_PUSH_BUTTON_WIDGET_STYLE_CLICKED =
            "QPushButton {"
            "background: #3574F0;"
            "border: 2px solid transparent;"
            "border-radius: 4px;"
            "}"
            "QPushButton:hover {"
            "background: #366ACF;"
            "}"
            "QPushButton:pressed {"
            "	background: #375FAD;"
            "}";

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
