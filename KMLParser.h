#include <QDebug>
#include <iostream>
#include <qfile.h>
#include <qregexp.h>
#include <qxmlstream.h>
#include <sstream>

struct Zone
{
	double gain;

	QVector<QPair<double, double>> coordinates;
};

struct Spot
{
	QString name;

	QVector<Zone> zones;
};

class KMLParser
{
public:
	Spot zoneCoords(const QByteArray& b_arr);
	Spot zoneCoords(const QString& file_path);

private:
	Spot parseByteArr(const QByteArray& b_arr);
};
