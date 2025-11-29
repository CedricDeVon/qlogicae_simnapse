#include "pch.hpp"

#include "../includes/settings.hpp"
#include "../includes/utilities.hpp"

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
			UTILITIES.DEFAULT_SETTINGS_SCREEN_TYPE_VALUE
		);
		
		connect(
			_ui->comboBox_2,
			QOverload<int>::of(&QComboBox::currentIndexChanged),
			this, [this](int index)
			{
				emit on_screen_type_changed(index);
			}
		);
	}
}
