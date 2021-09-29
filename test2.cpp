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

	REQUIRE(instance2.parseDocName(file_path).toStdString() == "Intelsat-10-02-Spot-3");


}

TEST_CASE("Parse Gains")
{
	KMLParser instance3;

	const QString file_path = "02_Spot_3.kml";

	QVector<QString> gains = {"Gain 54.4 ", "Gain 52.4", "Gain 50.4", "Gain 48.4", "Gain 46.4", "Gain 44.4"};

	REQUIRE(instance3.Gains(file_path) == gains);


}