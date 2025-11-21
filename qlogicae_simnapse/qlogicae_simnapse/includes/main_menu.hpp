#pragma once

#include "ui_main_menu.h"

class MainMenu : public QWidget
{
	Q_OBJECT

public:
	MainMenu(QWidget *parent = nullptr);
	~MainMenu();

private:
	Ui::MainMenuClass ui;
};

