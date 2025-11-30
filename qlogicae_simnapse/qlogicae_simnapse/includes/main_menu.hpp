#pragma once

#include "ui_main_menu.h"

#include "about.hpp"
#include "settings.hpp"
#include "utilities.hpp"
#include "evaluation.hpp"

namespace Ui
{
	class MainMenuClass;
}

namespace QLogicaeSimNapse
{
	class MainMenu :
		public QWidget
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
		About* _about_widget;
		
		Ui::MainMenuClass* _ui;
		
		Settings* _settings_widget;

		Evaluation* _evaluation_widget;

		std::string _current_widget_name;

		QPushButton* _current_active_left_side_button;


		void _change_widget(
			QPushButton* clicked_button,
			QWidget* widget
		);
	};
}
