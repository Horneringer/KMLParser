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

TEST_CASE("Return struct")
{

	KMLParser instance5;

	const QString file_path = "02_Spot_3.kml";
	QVector<QString> gains = {"Gain 54.4", "Gain 52.4", "Gain 50.4", "Gain 48.4", "Gain 46.4", "Gain 44.4"};

	Zone zone;

	REQUIRE(instance5.Zone_coords(file_path).file_name == "Intelsat-10-02-Spot-3");
	REQUIRE(instance5.Zone_coords(file_path).zones[0].gain == gains[0]);

	for (auto i = 0; i < gains.size(); i++)
	{
		qDebug() << instance5.Zone_coords(file_path).zones[i].gain << endl;
		qDebug() << instance5.Zone_coords(file_path).zones[i].coordinates << endl;
	}
}
