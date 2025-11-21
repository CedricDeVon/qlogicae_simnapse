#include "pch.hpp"

#include "../includes/splash.hpp"

namespace QLogicaeSimNapse
{
    Splash::Splash(QWidget* parent)
        : QWidget(parent),
        _ui(new Ui::SplashClass)
    {
        _ui->setupUi(this);

        _setup_widgets();
    }

    Splash::~Splash()
    {
        delete _ui;
        delete _icon_effect;
        delete _label_effect;
        delete _icon_fade_animation;
        delete _label_fade_animation;
        delete _main_animation_group;
    }

    void Splash::showEvent(QShowEvent* event)
    {
        QTimer::singleShot(
            500, this, [this]()
            {
                this->_main_animation_group->start();
            }
        );
    }

    void Splash::_setup_widgets()
    {

        QPalette window_palette = palette();
        window_palette.setColor(QPalette::Window, "#1E1F22");
        setPalette(window_palette);
        setAutoFillBackground(true);

        _icon_effect = new QGraphicsOpacityEffect(_ui->icon);
        _ui->icon->setGraphicsEffect(_icon_effect);
        _icon_effect->setOpacity(0.0);

        _label_effect = new QGraphicsOpacityEffect(_ui->label);
        _ui->label->setGraphicsEffect(_label_effect);
        _label_effect->setOpacity(0.0);

        _icon_fade_animation = new QPropertyAnimation(
            _icon_effect, "opacity", this
        );
        _icon_fade_animation->setDuration(2000);
        _icon_fade_animation->setStartValue(0.0);
        _icon_fade_animation->setKeyValueAt(0.5, 1.0);
        _icon_fade_animation->setEndValue(0.0);
        _icon_fade_animation->setEasingCurve(QEasingCurve::InOutQuad);

        _label_fade_animation = new QPropertyAnimation(
            _label_effect, "opacity", this
        );
        _label_fade_animation->setDuration(2000);
        _label_fade_animation->setStartValue(0.0);
        _label_fade_animation->setKeyValueAt(0.5, 1.0);
        _label_fade_animation->setEndValue(0.0);
        _label_fade_animation->setEasingCurve(QEasingCurve::InOutQuad);

        _main_animation_group = new QParallelAnimationGroup(this);
        _main_animation_group->addAnimation(_icon_fade_animation);
        _main_animation_group->addAnimation(_label_fade_animation);

        connect(
            _main_animation_group,
            &QParallelAnimationGroup::finished, this, [this]()
            {
                emit on_animation_complete();
            });
    }
}
