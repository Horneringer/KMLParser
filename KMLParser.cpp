#include "KMLParser.h"


Intelsat KMLParser::Zone_coords(const QString& file_path)
{
	QFile file(file_path);

	file.open(QIODevice::ReadOnly);

	QXmlStreamReader reader;

	reader.setDevice(&file);

	Intelsat intelsat;
	

	// парсинг имени файла
	while (!reader.atEnd())
	{

		QString zone_name;
		if (reader.readNextStartElement())
		{
			if (reader.name().toString() == "name")
			{
				intelsat.file_name = reader.readElementText();
			}

			// парсинг имён зон
			if (reader.name() == "Placemark")
			{

				while (reader.readNextStartElement())
				{
					if (reader.name() == "name")
					{
						 zone_name =  reader.readElementText();
						qDebug() << zone_name << endl;
					}
				}
			}

			// парсинг координат
			if (reader.name() == "LinearRing")
			{
				while (reader.readNextStartElement())
				{

					if (reader.name() == "coordinates")
					{
						QVector<QPair<double, double>> coordinates;

						QString string_coordinates = reader.readElementText();

						string_coordinates = string_coordinates.trimmed();

						std::stringstream buf1(string_coordinates.toStdString());

						std::string temp;
						
						while (std::getline(buf1, temp, '\n'))
						{
							QVector<double> vec;

							std::stringstream buf2(temp.substr(0, temp.length() - 1));

							for (double num; buf2 >> num;)
							{
								if (buf2.peek() == ',')
									buf2.ignore();

								vec.push_back(num);
							}
							
							coordinates.push_back(qMakePair(vec[0], vec[1]));
						}
						 
						qDebug() << coordinates << endl;					
					}
					
				}
			}

		}

	}
	return intelsat;
}


