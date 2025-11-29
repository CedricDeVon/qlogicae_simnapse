#pragma once

#include "ui_about.h"

#include "qlogicae_core/includes/all.hpp"

namespace Ui
{
	class AboutClass;
}

namespace QLogicaeSimNapse
{
	class About : public QWidget
	{
		Q_OBJECT

	public:
		explicit About(
			QWidget* parent = nullptr
		);
		
		~About();

	protected:
		void showEvent(
			QShowEvent* event
		) override;

	private:
		Ui::AboutClass* _ui;
	};
}
