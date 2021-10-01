#include "KMLParser.h"


Zone KMLParser::Zone_coords(const QString& file_path)
{
	QFile file(file_path);

	file.open(QIODevice::ReadOnly);

	QXmlStreamReader reader;

	reader.setDevice(&file);

	Zone zone;
	QVector<QString> string_coordinates;
	QVector<QVector<double>> v_vec;

	// парсинг имени файла
	while (!reader.atEnd())
	{
		if (reader.readNextStartElement())
		{
			if (reader.name().toString() == "name")
			{
				zone.file_name = reader.readElementText();
			}

			// парсинг имён зон
			if (reader.name() == "Placemark")
			{

				while (reader.readNextStartElement())
				{
					if (reader.name() == "name")
					{
						zone.gains.append(reader.readElementText());
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
						string_coordinates.append(reader.readElementText());
					}
				}
			}


		}
	}

	for (auto item : string_coordinates)
	{
		QVector<double> vec;

		std::stringstream buf(item.toStdString());

		for (double num; buf >> num;)
		{
			vec.push_back(num);

			if (buf.peek() == ',')
				buf.ignore();
		}

		v_vec.push_back(vec);
	}

	for (auto i = 0; i < v_vec.size(); i++)
	{
		for (auto j = 0; j < v_vec[i].size(); j++)
		{
			if (v_vec[i][j] == 0)
			{
				v_vec[i].erase(v_vec[i].begin() + j);
			}
		}
	}

	for (auto i = 0; i < v_vec.size(); i++)
	{
		QVector<QPair<double, double>> crd = {};
		for (auto j = 0; j < v_vec[i].size(); j++)
		{
			if (j % 2 == 0)
			{
				crd.push_back(qMakePair(v_vec[i][j], v_vec[i][j + 1]));
			}
		}

		zone.coordinates.push_back(crd);
	}

	

	return zone;
}


