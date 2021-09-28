#include "KMLParser.h"
#include <catch2.hpp>

TEST_CASE("Open file")
{

	KMLParser instance1;

	QString file_path = "02_Spot_3.kml";

	REQUIRE(instance1.openDoc(file_path) == 1);
}


TEST_CASE("Parse Document Name")
{

	KMLParser instance2;

	const QString file_path = "02_Spot_3.kml";

	REQUIRE(instance2.parseDocName(file_path) == "Intelsat-10-02-Spot-3");


}