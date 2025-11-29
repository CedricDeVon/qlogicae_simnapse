#pragma once

#include "ui_loading.h"

namespace Ui
{
	class LoadingClass;
}

namespace QLogicaeSimNapse
{
	class Loading : public QWidget
	{
		Q_OBJECT

	public:
		explicit Loading(
			QWidget* parent = nullptr
		);
		
		~Loading();

	signals:
		void on_loading_complete();

	protected:
		void showEvent(QShowEvent* event) override;

	private slots:
		void update_loading_label();
		
		void update_progress_bar();

	private:
		Ui::LoadingClass* _ui;

		QTimer* _dot_timer;
		
		QTimer* _progress_timer;

		uint8_t _current_dot_count;

		void _setup_widgets();
	};
}
