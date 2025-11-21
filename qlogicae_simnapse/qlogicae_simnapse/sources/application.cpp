#include "pch.hpp"

#include "../includes/application.hpp"

namespace QLogicaeSimNapse
{
    Application::Application(QWidget* parent)
        : QMainWindow(parent)
    {
        _ui.setupUi(this);

        _setup_window_screen();
        _setup_assets();
        _setup_widgets();
    }

    Application::~Application()
    {
        delete _splash_widget;
        delete _loading_widget;
        delete _main_menu_widget;
    }

    void Application::_setup_window_screen()
    {
        /*
        this->setWindowIcon(
            QIcon(
                QString::fromStdString(
                    QLogicaeRulexCore::UTILITIES.APPLICATION_LOGO
                )
            )
        );
        this->setWindowTitle(
            QString::fromStdString(
                QLogicaeCore::APPLICATION.get_qlogicae_name()
            )
        );
        _change_screen_type(
            QLogicaeRulexCore::UTILITIES.APPLICATION_SETTINGS_CACHE_SCREEN_TYPE
        );
        */
    }

    void Application::_setup_assets()
    {
        /*
        int font_id = QFontDatabase::addApplicationFont(
            QString::fromStdString(QLogicaeRulexCore::UTILITIES.APPLICATION_DEFAULT_QT_FONT_REFERENCE)
        );
        if (font_id != -1)
        {
            QStringList families = QFontDatabase::applicationFontFamilies(font_id);
            if (!families.isEmpty())
            {
                QString fontName = families.at(0);
                QString style = QString::fromStdString(
                    QLogicaeRulexCore::UTILITIES.APPLICATION_DEFAULT_QWIDGET_STYLE
                ).arg(fontName);

                qApp->setStyleSheet(style);
            }
        }
        */
    }

    void Application::_setup_widgets()
    {
        /*
        _splash_widget = new Splash();
        _loading_widget = new Loading();
        _mainmenu_widget = new MainMenu();

        _ui.stackedWidget->addWidget(_splash_widget);
        _ui.stackedWidget->addWidget(_loading_widget);
        _ui.stackedWidget->addWidget(_mainmenu_widget);

        _ui.stackedWidget->setCurrentWidget(_splash_widget);
        setCentralWidget(_ui.stackedWidget);

        connect(_splash_widget, &Splash::on_animation_complete, this, [this]()
            {
                _ui.stackedWidget->setCurrentWidget(_loading_widget);
            }
        );

        connect(_loading_widget, &Loading::on_loading_complete, this, [this]()
            {
                _ui.stackedWidget->setCurrentWidget(_mainmenu_widget);
            }
        );

        connect(_mainmenu_widget, QOverload<int>::of(&MainMenu::on_screen_changed), this, [this](int index)
            {
                _change_screen_type(index);
            });
        */
    }

    void Application::_change_screen_type(
        uint8_t index
    )
    {
        switch (index)
        {
            case (0): this->showNormal(); break;
            case (1): this->showFullScreen(); break;
            case (2): this->setWindowState(Qt::WindowMinimized); break;
            case (3): this->showMaximized(); break;
            default: this->showNormal(); break;
        }
    }
}
