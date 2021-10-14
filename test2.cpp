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
