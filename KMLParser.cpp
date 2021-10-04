#include "KMLParser.h"


Intelsat KMLParser::Zone_coords(const QString& file_path)
{
	QFile file(file_path);

	file.open(QIODevice::ReadOnly);

	QXmlStreamReader reader;

	reader.setDevice(&file);

	Intelsat intelsat;
	QVector<QString> string_coordinates;
	QVector<QVector<double>> v_vec;

	// парсинг имени файла
	while (!reader.atEnd())
	{
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
						intelsat.zones.push_back({reader.readElementText()});
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

						QVector<double> vec;

						std::stringstream buf(reader.readElementText().toStdString());

						for (double num; buf >> num;)
						{
							
							vec.push_back(num);

							if (buf.peek() == ',')
								buf.ignore();

							
						}

						for (auto i = 0; i < vec.size(); i++)
						{
								if (vec[i] == 0)
								{
									vec.erase(vec.begin() + i);
								}
							
						}


						for (auto i = 0; i < vec.size(); i++)
						{
							if (i % 2 == 0)
							{
								qMakePair(vec[i], vec[i + 1]);
							
							}
						
						
						}

						//intelsat.zones.push_back({vec});
					}
				}
			}


		}
	}

	/*for (auto item : string_coordinates)
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
	}*/

	

	return intelsat;
}


