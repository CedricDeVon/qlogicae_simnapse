#include "pch.hpp"

#include "../includes/main_menu.hpp"

namespace QLogicaeSimNapse
{
	MainMenu::MainMenu(QWidget* parent)
			: QWidget(parent),
		_ui(new Ui::MainMenuClass)
	{
		_ui->setupUi(this);

		_evaluation_widget = new Evaluation();
		_settings_widget = new Settings();
		_about_widget = new About();

		_ui->stackedWidget->addWidget(_evaluation_widget);
		_ui->stackedWidget->addWidget(_settings_widget);
		_ui->stackedWidget->addWidget(_about_widget);

		_ui->stackedWidget->setCurrentWidget(_evaluation_widget);

		_current_active_left_side_button = _ui->pushButton_8;
		_ui->label_2->setText(_evaluation_widget->windowTitle());

		connect(_ui->pushButton_8, &QPushButton::clicked, this, [this]()
			{
				_change_widget(_ui->pushButton_8, _evaluation_widget);
			}
		);

		connect(_ui->pushButton_7, &QPushButton::clicked, this, [this]()
			{
				_change_widget(_ui->pushButton_7, _settings_widget);
			}
		);

		connect(_ui->pushButton_4, &QPushButton::clicked, this, [this]()
			{
				_change_widget(_ui->pushButton_4, _about_widget);
			}
		);

		connect(_settings_widget, QOverload<int>::of(
			&Settings::on_screen_type_changed), this, [this](int index)
			{
				emit on_screen_changed(index);
			}
		);
	}

	MainMenu::~MainMenu()
	{
		delete _ui;
		delete _about_widget;
		delete _settings_widget;
		delete _evaluation_widget;
	}

	void MainMenu::_change_widget(
		QPushButton* clicked_button,
		QWidget* widget
	)
	{
		if (_current_active_left_side_button != clicked_button)
		{
			_current_active_left_side_button->setStyleSheet(
				UTILITIES.DEFAULT_PUSH_BUTTON_WIDGET_STYLE_NORMAL
			);
			
			clicked_button->setStyleSheet(
				UTILITIES.DEFAULT_PUSH_BUTTON_WIDGET_STYLE_CLICKED
			);

			_current_active_left_side_button = clicked_button;
			_ui->stackedWidget->setCurrentWidget(widget);
			_ui->label_2->setText(widget->windowTitle());
		}
	}
}
