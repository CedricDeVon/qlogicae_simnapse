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
			(QLogicaeCore::ROCKSDB_DATABASE.is_key_found(UTILITIES.DEFAULT_SETTINGS_SCREEN_TYPE_KEY)) ?
				QLogicaeCore::ROCKSDB_DATABASE.get_value<int>(UTILITIES.DEFAULT_SETTINGS_SCREEN_TYPE_KEY) :
				UTILITIES.DEFAULT_SETTINGS_SCREEN_TYPE_VALUE
		);
		
		connect(
			_ui->comboBox_2,
			QOverload<int>::of(&QComboBox::currentIndexChanged),
			this, [this](int index)
			{
				emit on_screen_type_changed(index);

				QLogicaeCore::ROCKSDB_DATABASE.begin_batch();
				QLogicaeCore::ROCKSDB_DATABASE.batch_set_value<int>(
					UTILITIES.DEFAULT_SETTINGS_SCREEN_TYPE_KEY,
					index
				);
				QLogicaeCore::ROCKSDB_DATABASE.batch_execute();
			}
		);
	}
}
