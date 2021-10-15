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

	Spot spot = kmlparser.zoneCoords(file_path);

	for (auto i = 0; i < spot.zones.size(); i++)
	{
		QPolygonF polygon;
		for (auto j = 0; j < spot.zones[i].coordinates.size(); j++)
		{
			polygon << QPoint(spot.zones[i].coordinates[j].first, -spot.zones[i].coordinates[j].second);
		}

		scene->addPolygon(polygon);
	}

	view.show();
	return QApplication::exec();
}