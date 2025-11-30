#pragma once

#include "ui_splash.h"

namespace Ui
{
	class SplashClass;
}

namespace QLogicaeSimNapse
{
	class Splash :
		public QWidget
	{
		Q_OBJECT

	public:
		explicit Splash(QWidget* parent = nullptr);
		~Splash();

	signals:
		void on_animation_complete();

	protected:
		void showEvent(QShowEvent* event) override;

	private:
		Ui::SplashClass* _ui;
		
		QGraphicsOpacityEffect* _icon_effect;
		
		QGraphicsOpacityEffect* _label_effect;
		
		QPropertyAnimation* _icon_fade_animation;
		
		QPropertyAnimation* _label_fade_animation;

		QParallelAnimationGroup* _main_animation_group;

		void _setup_widgets();
	};
}
