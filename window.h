#pragma once

#include<QtWidgets/qmainwindow.h>
#include<QtWidgets/qgraphicsview.h>
#include<QtWidgets/qgraphicsscene.h>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = 0);
	~MainWindow();

private:
	Ui::MainWindow* ui;
	QGraphicsView view;
	QGraphicsScene scene;
};