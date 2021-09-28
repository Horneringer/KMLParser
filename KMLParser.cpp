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

	QString DocName;

	QXmlStreamReader reader;

	reader.setDevice(&file);

	while (!reader.atEnd())
	{
		if (reader.readNextStartElement())
		{
			if (reader.name().toString() == "name")
			{
				DocName = reader.readElementText();
			}
		}

	}


	return DocName;
}


