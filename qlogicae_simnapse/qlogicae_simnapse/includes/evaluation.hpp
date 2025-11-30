#pragma once

#include "ui_evaluation.h"

#include "utilities.hpp"

namespace Ui
{
	class EvaluationClass;
}

namespace QLogicaeSimNapse
{
	class Evaluation :
		public QWidget
	{
		Q_OBJECT

	public:
		explicit Evaluation(
			QWidget* parent = nullptr
		);
		
		~Evaluation();

	protected:
		void showEvent(
			QShowEvent* event
		) override;

		void _reset();
		
		void _setup_widgets();

		void _train_button_clicked();

		void _reset_button_clicked();
		
		void _spin_box_value_changed(int value);

		void _horizontal_slider_value_changed(int value);

		void _table_widget_item_changed(QTableWidgetItem* item);		

	private:
		Ui::EvaluationClass* _ui;
	};
}
