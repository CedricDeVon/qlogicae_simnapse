#include "pch.hpp"

#include "../includes/loading.hpp"

namespace QLogicaeSimNapse
{
    Loading::Loading(QWidget* parent)
        : QWidget(parent),
        _ui(new Ui::LoadingClass),
        _current_dot_count(0)
    {
        _ui->setupUi(this);

        _setup_widgets();
    }

    Loading::~Loading()
    {
        delete _ui;
        delete _dot_timer;
        delete _progress_timer;
    }

    void Loading::update_loading_label()
    {
        QString text = "Loading";
        _current_dot_count = (_current_dot_count + 1) % 4;
        for (uint8_t index = 0;
            index < _current_dot_count;
            ++index)
        {
            text += " .";
        }

        _ui->label->setText(text);
    }

    void Loading::update_progress_bar()
    {
        uint8_t value = _ui->progressBar->value() + 10;
        if (value > _ui->progressBar->maximum())
        {
            _ui->progressBar->setValue(_ui->progressBar->maximum());
            emit on_loading_complete();

            return;
        }

        _ui->progressBar->setValue(value);
    }

    void Loading::showEvent(QShowEvent* event)
    {
        _dot_timer->start(1000);
        _progress_timer->start(16);
        update_progress_bar();
    }

    void Loading::_setup_widgets()
    {
        _dot_timer = new QTimer(this);
        connect(
            _dot_timer,
            &QTimer::timeout, this,
            &Loading::update_loading_label
        );

        _progress_timer = new QTimer(this);
        connect(
            _progress_timer,
            &QTimer::timeout, this,
            &Loading::update_progress_bar
        );
    }
}
