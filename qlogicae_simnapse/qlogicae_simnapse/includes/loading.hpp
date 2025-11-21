#pragma once

#include "ui_loading.h"

class Loading : public QWidget
{
	Q_OBJECT

public:
	Loading(QWidget *parent = nullptr);
	~Loading();

private:
	Ui::LoadingClass ui;
};

