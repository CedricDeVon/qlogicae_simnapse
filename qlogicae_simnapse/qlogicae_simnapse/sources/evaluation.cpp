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
