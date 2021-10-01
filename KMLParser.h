#include<iostream>
#include <qxmlstream.h>
#include <qfile.h>
#include <qdebug.h>
#include <sstream>

struct Zone
{
	QString file_name;

	QVector<QString> gains;

	QVector<QVector<QPair<double, double>>> coordinates;

	
};

class KMLParser
{

	public:
		
		bool openDoc(QString& file_path);

		QString parseDocName(const QString& file_path);
		QVector<QString> Gains(const QString& file_path);
		QVector<QVector<QPair<double, double>>> Coordinates(const QString& file_path);

		Zone Zone_coords(const QString& file_path);

		
};


