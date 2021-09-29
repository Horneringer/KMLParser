#include "KMLParser.h"

bool KMLParser::openDoc(QString& file_path)
{

	QFile* file = new QFile(file_path);
	if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}

	else
	{

		return true;
	}
}

QString KMLParser::parseDocName(const QString& file_path)
{

	QFile file (file_path);
	file.open(QIODevice::ReadOnly);

	QXmlStreamReader reader;

	reader.setDevice(&file);

	while (!reader.atEnd())
	{
		if (reader.readNextStartElement())
		{
			if (reader.name().toString() == "name")
			{
				QString DocName = reader.readElementText();

				return DocName;
			}

		}

	}

	return "";
	
}

QVector<QString> KMLParser::Gains(const QString& file_path)
{
	QFile file(file_path);

	file.open(QIODevice::ReadOnly);

	QXmlStreamReader reader;

	QVector<QString> gains;

	reader.setDevice(&file);

	while (!reader.atEnd())
	{

		if (reader.readNextStartElement())
		{

			if (reader.name() == "Placemark")
			{

				while (reader.readNextStartElement())
				{
					if (reader.name() == "name")
					{
						gains.append(reader.readElementText());
						
						
					}
				}
				
			}	
		}
	
	}
	return gains;
	
}

QVector<QString> KMLParser::Coordinates(const QString& file_path)
{

	QFile file(file_path);

	file.open(QIODevice::ReadOnly);

	QXmlStreamReader reader;

	reader.setDevice(&file);

	QVector<QString> coordinates;

	while (!reader.atEnd())
	{
		if (reader.readNextStartElement())
		{
			if (reader.name() == "LinearRing")
			{
				while (reader.readNextStartElement())
				{
					if (reader.name() == "coordinates")
					{
						coordinates.append(reader.readElementText());
					
					}
				
				}
			
			}
		
		}	
	}

	return coordinates;
}


