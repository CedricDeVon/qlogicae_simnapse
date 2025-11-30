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
	
	Evaluation::~Evaluation()
	{
		
	}

	void Evaluation::_setup_widgets()
	{
		_ui->spinBox->setDisabled(true);
		_ui->spinBox_2->setDisabled(true);
		_ui->horizontalSlider->setDisabled(true);
		_ui->tableWidget->setDisabled(true);
		_ui->pushButton_10->setDisabled(true);
		_ui->pushButton_11->setDisabled(true);

		_ui->spinBox_2->setValue(
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_CURRENT_EPOCH
		);

		_ui->spinBox->setValue(
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_FINAL_EPOCH
		);

		_ui->horizontalSlider->setValue(
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_SLIDER_VALUE
		);

		_ui->horizontalSlider->setMaximum(
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_FINAL_EPOCH
		);

		_ui->label_18->setText(
			QString::fromStdString(
				QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_ERROR_RATE
			)
		);

		_ui->label_21->setText(
			QString::fromStdString(
				QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TRAINING_DURATION
			)
		);

		int
			row_index,
			column_index;
		size_t
			row_size =
				QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE_ROW_COUNT,
			column_size =
				QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE_COLUMN_COUNT;
		for (row_index = 0;
			row_index < row_size;
			++row_index
			)
		{
			for (column_index = 0;
				column_index < column_size;
				++column_index
				)
			{
				auto item = _ui->tableWidget->item(
					row_index,
					column_index
				);
				item->setText(
					QString::fromStdString(
						QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE
							[row_index][column_index]
					)
				);
				_ui->tableWidget->setItem(
					row_index,
					column_index,
					item
				);
			}
		}

		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.name =
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_NAME;
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.maximum_learning_epoch =
			static_cast<size_t>(QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_FINAL_EPOCH);
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.inputs =
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_INPUTS;
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.outputs =
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_OUTPUTS;
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.weights =
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_WEIGHTS;
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.bias =
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_BIAS;
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.learning_rate =
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_LEARNING_RATE;
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.callback =
			[this](const QLogicaeSimNapseCore::AndOrNeuralNetworkTrainingEpochResults& result)
			{
				_ui->spinBox_2->setValue(
					static_cast<int>(result.current_epoch)
				);
			};

		connect(
			_ui->horizontalSlider,
			&QSlider::valueChanged,
			this,
			[this](int value)
			{
				_horizontal_slider_value_changed(value);
			}
		);

		connect(
			_ui->tableWidget,
			&QTableWidget::itemChanged,
			this,
			[this](QTableWidgetItem* item)
			{
				_table_widget_item_changed(item);
			}
		);

		connect(
			_ui->spinBox,
			&QSpinBox::valueChanged,
			this,
			[this](int value)
			{
				_spin_box_value_changed(value);
			}
		);

		connect(
			_ui->pushButton_10,
			&QPushButton::clicked,
			this,
			[this]()
			{
				_train_button_clicked();
			}
		);

		connect(
			_ui->pushButton_11,
			&QPushButton::clicked,
			this,
			[this]()
			{
				_reset_button_clicked();
			}
		);

		_ui->spinBox->setDisabled(false);
		_ui->tableWidget->setDisabled(false);
		_ui->pushButton_10->setDisabled(false);
		_ui->pushButton_11->setDisabled(false);
	}

	void Evaluation::_reset()
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

		_ui->horizontalSlider->setMaximum(
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_FINAL_EPOCH
		);

		_ui->label_18->setText(
			QString::fromStdString(
				QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_ERROR_RATE
			)
		);

		_ui->label_21->setText(
			QString::fromStdString(
				QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TRAINING_DURATION
			)
		);

		int
			row_index,
			column_index;
		size_t
			row_size = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE_ROW_COUNT,
			column_size = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE_COLUMN_COUNT;
		for (row_index = 0;
			row_index < row_size;
			++row_index
			)
		{
			for (column_index = 0;
				column_index < column_size;
				++column_index
				)
			{
				auto item = _ui->tableWidget->item(
					row_index,
					column_index
				);
				item->setText(
					QString::fromStdString(
						QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_TABLE
						[row_index][column_index]
					)
				);
				_ui->tableWidget->setItem(
					row_index,
					column_index,
					item
				);
			}
		}

		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.maximum_learning_epoch =
			static_cast<size_t>(QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_FINAL_EPOCH);
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.inputs =
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_INPUTS;
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.outputs =
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_OUTPUTS;
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.weights =
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_WEIGHTS;
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.bias =
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_BIAS;
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.learning_rate =
			QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_LEARNING_RATE;
	}

	void Evaluation::_horizontal_slider_value_changed(int value)
	{
		QLogicaeSimNapseCore::AndOrNeuralNetworkTrainingEpochResults epoch_results =
			QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_RESULTS
				.epoch_results[value - 1];

		_ui->spinBox_2->setValue(
			value
		);

		int row_index;
		double errors = 0;
		for (row_index = 0;
			row_index < 4;
			++row_index
			)
		{
			_ui->tableWidget->item(row_index, 3)->setText(
				QString::fromStdString(
					absl::StrCat(
						epoch_results.predictions[row_index]
					)
				)
			);
			_ui->tableWidget->item(row_index, 4)->setText(
				QString::fromStdString(
					absl::StrCat(
						epoch_results.errors[row_index]
					)
				)
			);
			errors += (epoch_results.errors[row_index] != 0);

			_ui->tableWidget->item(row_index, 5)->setText(
				QString::fromStdString(
					absl::StrCat(
						epoch_results.weights[0]
					)
				)
			);
			_ui->tableWidget->item(row_index, 6)->setText(
				QString::fromStdString(
					absl::StrCat(
						epoch_results.weights[1]
					)
				)
			);
			_ui->tableWidget->item(row_index, 7)->setText(
				QString::fromStdString(
					absl::StrCat(
						epoch_results.bias
					)
				)
			);
		}
		errors = errors / 4 * 100;

		_ui->label_18->setText(
			QString::fromStdString(
				absl::StrCat(
					errors
				)
			)
		);
	}

	void Evaluation::_table_widget_item_changed(QTableWidgetItem* item)
	{
		if (
			(item->column() > 2)
			)
		{
			return;
		}

		if (
			!item->text().size() ||
			item->text().size() > 1
			)
		{
			if (item->column() < 2)
			{
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.inputs
					[item->row()][item->column()] = 0;
			}
			else
			{
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.outputs
					[item->row()] = 0;
			}
			item->setText("0");

			return;
		}

		int value = item->text().toStdString()[0] - '0';
		if (value != 0 && value != 1)
		{
			if (item->column() < 2)
			{
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.inputs
					[item->row()][item->column()] = 0;
			}
			else
			{
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.outputs
					[item->row()] = 0;
			}
			item->setText("0");

			return;
		}

		if (item->column() < 2)
		{
			QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.inputs
				[item->row()][item->column()] = value;
		}
		else
		{
			QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.outputs
				[item->row()] = value;
		}
	}

	void Evaluation::_train_button_clicked()
	{
		_ui->horizontalSlider->setDisabled(true);
		_ui->spinBox->setDisabled(true);
		_ui->spinBox_2->setDisabled(true);
		_ui->tableWidget->setDisabled(true);
		_ui->pushButton_10->setDisabled(true);
		_ui->pushButton_11->setDisabled(true);

		_ui->label_21->setText(
			"..."
		);
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_RESULTS =
			QLogicaeSimNapseCore::AND_OR_NEURAL_NETWORK.train(
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS
			);

		_ui->horizontalSlider->setValue(
			static_cast<int>(
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_RESULTS.epoch_results.size()
				)
		);
		_ui->label_21->setText(
			QString::fromStdString(
				absl::StrCat(
					(QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_RESULTS.timestamp_ended -
						QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_RESULTS.timestamp_started) / 1'000'000'000
				)
			)
		);

		_ui->horizontalSlider->setDisabled(false);
		_ui->spinBox->setDisabled(false);
		_ui->tableWidget->setDisabled(false);
		_ui->pushButton_10->setDisabled(false);
		_ui->pushButton_11->setDisabled(false);
	}

	void Evaluation::_spin_box_value_changed(int value)
	{
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.maximum_learning_epoch =
			static_cast<size_t>(value);

		_ui->horizontalSlider->setMaximum(value);
	}

	void Evaluation::_reset_button_clicked()
	{
		_ui->spinBox->setDisabled(true);
		_ui->spinBox_2->setDisabled(true);
		_ui->horizontalSlider->setDisabled(true);
		_ui->tableWidget->setDisabled(true);
		_ui->pushButton_10->setDisabled(true);
		_ui->pushButton_11->setDisabled(true);

		_reset();

		_ui->spinBox->setDisabled(false);
		_ui->tableWidget->setDisabled(false);
		_ui->pushButton_10->setDisabled(false);
		_ui->pushButton_11->setDisabled(false);
	}

	void Evaluation::showEvent(QShowEvent* event)
	{

	}
}
