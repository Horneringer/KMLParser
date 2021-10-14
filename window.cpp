#include "KMLParser.h"
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qgraphicsscene.h>
#include <QtWidgets/qgraphicsview.h>
#include <QtWidgets/qwidget.h>

int main(int argc, char* argv[])
{
	KMLParser kmlparser;

	const QString file_path = "02_SE_zone.kml";

	QApplication a(argc, argv);
	/// Сцена, виджет для отображения сцены и т.д.
	QWidget* widget = new QWidget;
	QGraphicsScene* scene = new QGraphicsScene(0, 0, 500, 500);

	QGraphicsView view(scene);
	widget->setWindowTitle("Polygon");

	Intelsat intelsat = kmlparser.zone_coords(file_path);

	for (auto i = 0; i < intelsat.zones.size(); i++)
	{
		QPolygonF polygon;
		for (auto j = 0; j < intelsat.zones[i].coordinates.size(); j++)
		{
			polygon << QPoint(intelsat.zones[i].coordinates[j].first, -intelsat.zones[i].coordinates[j].second);
		}

		scene->addPolygon(polygon);
	}

	view.show();
	return QApplication::exec();
}