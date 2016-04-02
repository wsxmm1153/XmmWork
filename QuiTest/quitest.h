#ifndef QUITEST_H
#define QUITEST_H

#include <QtWidgets/QMainWindow>
#include "ui_quitest.h"

class QuiTest : public QMainWindow
{
	Q_OBJECT

public:
	QuiTest(QWidget *parent = 0);
	~QuiTest();

private:
	Ui::QuiTestClass ui;
};

#endif // QUITEST_H
