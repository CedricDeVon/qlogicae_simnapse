#include "pch.hpp"

#include "../includes/evaluation.hpp"

namespace QLogicaeSimNapse
{
	Evaluation::Evaluation(QWidget* parent)
		: QWidget(parent),
		_ui(new Ui::EvaluationClass)
	{
		_ui->setupUi(this);

		_setup_widgets();
	}

	void Evaluation::_setup_widgets()
	{
		int i, j;
		size_t
			row_size = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE.size(),
			column_size = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE[0].size();
		for (i = 0; i < row_size; ++i)
		{
			for (j = 0; j < column_size; ++j)
			{
				auto item = _ui->tableWidget->item(
					i, j
				);
				item->setText(
					QString::fromStdString(
						QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE[i][j]
					)
				);
				
				_ui->tableWidget->setItem(
					i, j,
					item
				);
			}
		}

		connect(
			_ui->horizontalSlider, // Slider
			&QSlider::valueChanged,
			this,
			[this](int value)
			{
				_ui->spinBox_2->setValue(
					value
				);
			}
		);

		connect(
			_ui->pushButton_10, // Learn
			&QPushButton::clicked,
			this,
			[this]()
			{
				
			}
		);

		connect(
			_ui->pushButton_11, // Reset
			&QPushButton::clicked,
			this,
			[this]()
			{
				_ui->spinBox_2->setValue(
					QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_CURRENT_EPOCH
				);
				_ui->spinBox->setValue(
					QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_FINAL_EPOCH
				);
				_ui->horizontalSlider->setValue(
					QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_SLIDER_VALUE
				);
				_ui->label_16->setText(
					QString::fromStdString(
						QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_ERROR_RATE
					)
				);
				
				int i, j;
				size_t
					row_size = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE.size(),
					column_size = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE[0].size();
				for (i = 0; i < row_size; ++i)
				{
					for (j = 0; j < column_size; ++j)
					{
						auto item = _ui->tableWidget->item(
							i, j
						);
						item->setText(
							QString::fromStdString(
								QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE[i][j]
							)
						);
						_ui->tableWidget->setItem(
							i, j,
							item
						);
					}
				}

			}
		);

	}

	Evaluation::~Evaluation()
	{
		delete _ui;
	}

	void Evaluation::_on_input_changed()
	{

	}

	void Evaluation::showEvent(QShowEvent* event)
	{

	}
}
