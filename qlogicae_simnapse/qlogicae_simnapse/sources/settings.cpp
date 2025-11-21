#include "pch.hpp"

#include "../includes/settings.hpp"

namespace QLogicaeSimNapse
{
	Settings::Settings(QWidget* parent)
		: QWidget(parent),
		_ui(new Ui::SettingsClass)
	{
		_ui->setupUi(this);

		_setup_widgets();
	}

	Settings::~Settings()
	{
		delete _ui;
	}

	void Settings::_setup_widgets()
	{
		_ui->comboBox_2->setCurrentIndex(
			1 // QLogicaeRulexCore::UTILITIES.APPLICATION_SETTINGS_CACHE_SCREEN_TYPE
		);
		
		connect(
			_ui->comboBox_2,
			QOverload<int>::of(&QComboBox::currentIndexChanged),
			this, [this](int index)
			{
				emit on_screen_type_changed(index);

				/*
				QLogicaeRulexCore::UTILITIES.APPLICATION_SETTINGS_CACHE.set_value_async<int>(
					QLogicaeRulexCore::UTILITIES.APPLICATION_SETTINGS_CACHE_SCREEN_TYPE_KEY, index
				);
				*/
			}
		);
	}
}
