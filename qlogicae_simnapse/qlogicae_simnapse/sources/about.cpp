#include "pch.hpp"

#include "../includes/about.hpp"

namespace QLogicaeSimNapse
{
	About::About(QWidget* parent)
		: QWidget(parent),
			_ui(new Ui::AboutClass)
	{
		_ui->setupUi(this);
	}

	About::~About()
	{
		delete _ui;
	}

	void About::showEvent(QShowEvent* event)
	{
		_ui->label_7->setText(
			QString::fromStdString(
				QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_VERSION
			)
		);
		_ui->label_5->setText(
			QString::fromStdString(
				QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_APPLICATION_ID
			)
		);
		_ui->label_3->setText(
			QString::fromStdString(
				QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_ENVIRONMENT_NAME
			)
		);
	}
}
