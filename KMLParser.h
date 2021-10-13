#include <iostream>
#include <QDebug>
#include <qfile.h>
#include <qxmlstream.h>
#include <sstream>
#include<qregexp.h>


struct Zone
{
	double gain;

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
	Intelsat zone_coords(const QByteArray& b_arr);
	Intelsat zone_coords(const QString& file_path);

private:
	Intelsat parseByteArr(const QByteArray& b_arr);
};


