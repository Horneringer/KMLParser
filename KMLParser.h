#include<iostream>
#include <qxmlstream.h>
#include <qfile.h>
#include <qdebug.h>


class KMLParser
{

	public:
		
		bool openDoc(QString& file_path);

		QString parseDocName(const QString& file_path);
		QVector<QString> Gains(const QString& file_path);



};


