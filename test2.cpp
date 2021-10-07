#include "KMLParser.h"
#include <catch2.hpp>

namespace Catch
{
/// Для нормального вывода QString в сообщениях catch2
template<>
struct StringMaker<QString>
{
	static std::string convert(const QString& value) { return value.toStdString(); }
};
} // namespace Catch



TEST_CASE("Overload function")
{

	KMLParser instance6;

	const QString file_path = "02_SE_zone.kml";

	QFile file(file_path);

	file.open(QIODevice::ReadOnly);

	QByteArray b_arr = file.readAll();

	qDebug() << instance6.zone_coords(b_arr).file_name << endl;


	for (auto i = 0; i < 5; i++)
	{
		qDebug() << instance6.zone_coords(b_arr).zones[i].gain << endl;
		qDebug() << instance6.zone_coords(b_arr).zones[i].coordinates << endl;
	}


}