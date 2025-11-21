#pragma once

#include "ui_settings.h"

namespace Ui
{
	class SettingsClass;
}

namespace QLogicaeSimNapse
{
	class Settings : public QWidget
	{
		Q_OBJECT

	public:
		explicit Settings(QWidget* parent = nullptr);
		~Settings();

	signals:
		void on_screen_type_changed(int);

	private:
		Ui::SettingsClass* _ui;

		void _setup_widgets();
	};
}
