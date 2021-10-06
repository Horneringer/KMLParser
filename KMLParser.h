#include <iostream>
#include <qdebug.h>
#include <qfile.h>
#include <qxmlstream.h>
#include <sstream>

struct Zone
{

	QString gain;

	QVector<QPair<double, double>> coordinates;
};

struct Intelsat
{
	QString file_name;

	QVector<Zone> zones;
};

class KMLParser
{

public:
	Intelsat Zone_coords(const QString& file_path);
};
