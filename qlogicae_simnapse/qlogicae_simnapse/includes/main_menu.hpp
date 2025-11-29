#pragma once

#include "about.hpp"
#include "settings.hpp"
#include "evaluation.hpp"

#include "ui_main_menu.h"

namespace Ui
{
	class MainMenuClass;
}

namespace QLogicaeSimNapse
{
	class MainMenu : public QWidget
	{
		Q_OBJECT

	public:
		explicit MainMenu(
			QWidget* parent = nullptr
		);

		~MainMenu();

	signals:
		void on_screen_changed(int);

	private:
		Ui::MainMenuClass* _ui;

		About* _about_widget;
		
		Settings* _settings_widget;

		Evaluation* _evaluation_widget;

		QPushButton* _current_active_left_side_button;

		std::string _current_widget_name;

		void _change_widget(
			QPushButton* clicked_button,
			QWidget* widget
		);
	};
}
