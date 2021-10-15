#include "KMLParser.h"

Spot KMLParser::parseByteArr(const QByteArray& b_arr)
{
	Spot spot;
	double gain;
	QXmlStreamReader reader(b_arr);
	QRegExp reg("[0-9]+.[0-9]+");

	while (!reader.atEnd())
	{
		if (reader.readNextStartElement())
		{
			if (reader.name().toString() == "name")
			{
				spot.name = reader.readElementText();
			}

			if (reader.name() == "Placemark")
			{
				while (reader.readNextStartElement())
				{
					if (reader.name() == "name")
					{
						QString zone_name = reader.readElementText();
						int pos = reg.indexIn(zone_name);
						zone_name = reg.cap();
						gain = zone_name.toDouble();
					}
				}
			}

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

						spot.zones.push_back({gain, coordinates});
					}
				}
			}
		}
	}

	return spot;
}

Spot KMLParser::zoneCoords(const QString& file_path)
{
	QFile file(file_path);

	file.open(QIODevice::ReadOnly);

	QByteArray b_arr = file.readAll();

	return parseByteArr(b_arr);
}

Spot KMLParser::zoneCoords(const QByteArray& b_arr)
{
	return parseByteArr(b_arr);
}
