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

TEST_CASE("Check parse file name")
{
	KMLParser instance3;

	const QString file_path = "02_SE_zone.kml";

	Intelsat intelsat = instance3.zone_coords(file_path);

	REQUIRE(intelsat.file_name == "Intelsat-10-02-SE-zone");
}

TEST_CASE("Check parse gain")
{
	KMLParser instance4;

	const QString file_path = "02_SE_zone.kml";

	Intelsat intelsat = instance4.zone_coords(file_path);

	QVector<double> gains = {45.5, 43.4, 41.4, 39.4, 37.4};

	for (auto i = 0; i < gains.size(); i++)
	{
		REQUIRE(intelsat.zones[i].gain == gains[i]);
	}
}