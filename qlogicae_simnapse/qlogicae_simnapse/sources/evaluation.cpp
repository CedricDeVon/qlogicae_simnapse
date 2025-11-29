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
		
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.name = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_NAME;
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.maximum_learning_epoch = static_cast<size_t>(QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_FINAL_EPOCH);
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.inputs = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_INPUTS;
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.outputs = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_OUTPUTS;
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.weights = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_WEIGHTS;
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.bias = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_BIAS;
		QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.learning_rate = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_LEARNING_RATE;
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
				QLogicaeSimNapseCore::AndOrNeuralNetworkTrainingEpochResults epoch_results =
					QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_RESULTS.epoch_results[value - 1];

				_ui->spinBox_2->setValue(
					value
				);

				int k;
				for (k = 0; k < 4; ++k)
				{
					_ui->tableWidget->item(k, 3)->setText(
						QString::fromStdString(
							absl::StrCat(
								epoch_results.errors[k]
							)
						)
					);
				}
				for (k = 0; k < 4; ++k)
				{
					_ui->tableWidget->item(k, 4)->setText(
						QString::fromStdString(
							absl::StrCat(
								epoch_results.predictions[k]
							)
						)
					);
				}

				double errors = 0;
				for (k = 0; k < 4; ++k)
				{
					errors += (epoch_results.errors[k] != 0);
				}
				errors = errors / 4 * 100;

				_ui->label_16->setText(
					QString::fromStdString(
						absl::StrCat(
							errors
						)
					)
				);				
			}
		);

		connect(
			_ui->tableWidget,
			&QTableWidget::itemChanged,
			this,
			[this](QTableWidgetItem* item)
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
		);

		connect(
			_ui->spinBox, 
			&QSpinBox::valueChanged,
			this,
			[this](int value)
			{
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.maximum_learning_epoch =
					static_cast<size_t>(value);

				_ui->horizontalSlider->setMaximum(value);
			}
		);

		connect(
			_ui->pushButton_10, 
			&QPushButton::clicked,
			this,
			[this]()
			{
				_ui->horizontalSlider->setDisabled(true);
				_ui->spinBox->setDisabled(true);
				_ui->spinBox_2->setDisabled(true);
				_ui->tableWidget->setDisabled(true);
				_ui->pushButton_10->setDisabled(true);
				_ui->pushButton_11->setDisabled(true);
				
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_RESULTS =
					QLogicaeSimNapseCore::AND_OR_NEURAL_NETWORK.train(
						QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS
					);

				_ui->horizontalSlider->setValue(
					static_cast<int>(
						QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_RESULTS.epoch_results.size()
					)
				);

				_ui->horizontalSlider->setDisabled(false);
				_ui->spinBox->setDisabled(false);
				_ui->tableWidget->setDisabled(false);
				_ui->pushButton_10->setDisabled(false);
				_ui->pushButton_11->setDisabled(false);
			}
		);

		connect(
			_ui->pushButton_11, 
			&QPushButton::clicked,
			this,
			[this]()
			{
				_ui->horizontalSlider->setDisabled(true);
				_ui->spinBox->setDisabled(true);
				_ui->spinBox_2->setDisabled(true);
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

				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.maximum_learning_epoch = static_cast<size_t>(QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_FINAL_EPOCH);
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.inputs = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_INPUTS;
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.outputs = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_OUTPUTS;
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.weights = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_WEIGHTS;
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.bias = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_BIAS;
				QLogicaeSimNapse::UTILITIES.NEURAL_NETWORK_TRAINING_CONFIGURATIONS.learning_rate = QLogicaeSimNapse::UTILITIES.DEFAULT_EVALUATION_LEARNING_RATE;

				_ui->spinBox->setDisabled(false);
				_ui->tableWidget->setDisabled(false);
				_ui->pushButton_10->setDisabled(false);
				_ui->pushButton_11->setDisabled(false);
			}
		);

		_ui->spinBox->setDisabled(false);
		_ui->tableWidget->setDisabled(false);
		_ui->pushButton_10->setDisabled(false);
		_ui->pushButton_11->setDisabled(false);
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
