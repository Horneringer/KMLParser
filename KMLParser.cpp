#include "KMLParser.h"

Intelsat KMLParser::zone_coords(const QString& file_path)
{
	QFile file(file_path);

	file.open(QIODevice::ReadOnly);

	QXmlStreamReader reader;

	reader.setDevice(&file);

	Intelsat intelsat;

	QString zone_name;

	while (!reader.atEnd())
	{

		if (reader.readNextStartElement())
		{
			if (reader.name().toString() == "name")
			{
				intelsat.file_name = reader.readElementText();
			}

			if (reader.name() == "Placemark")
			{

				while (reader.readNextStartElement())
				{
					if (reader.name() == "name")
					{

						zone_name = reader.readElementText();
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

						intelsat.zones.push_back({zone_name, coordinates});
					}
				}
			}
		}
	}

	return intelsat;
}

Intelsat KMLParser::zone_coords(const QString& file_path, QByteArray& b_arr)
{
	QFile file(file_path);

	file.open(QIODevice::WriteOnly);

	file.write(b_arr);

	return zone_coords(file_path);
}
