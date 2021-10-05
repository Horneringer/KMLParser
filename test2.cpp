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

//TEST_CASE("Open file")
//{
//
//	KMLParser instance1;
//
//	QString file_path = "02_Spot_3.kml";
//
//	REQUIRE(instance1.openDoc(file_path) == 1);
//}
//
//
//TEST_CASE("Parse Document Name")
//{
//
//	KMLParser instance2;
//
//	const QString file_path = "02_Spot_3.kml";
//
//	REQUIRE(instance2.parseDocName(file_path).toStdString() == "Intelsat-10-02-Spot-3");
//
//
//}
//
//TEST_CASE("Parse Gains")
//{
//	KMLParser instance3;
//
//	const QString file_path = "02_Spot_3.kml";
//
//	QVector<QString> gains = {"Gain 54.4", "Gain 52.4", "Gain 50.4", "Gain 48.4", "Gain 46.4", "Gain 44.4"};
//
//	REQUIRE(instance3.Gains(file_path) == gains);
//
//
//}
//
//TEST_CASE("Parse Coordinates")
//{
//	KMLParser instance4;
//
//	const QString file_path = "02_Spot_3.kml";
//
//	QVector<QVector<QPair<double, double>>> coordinates = {};
//
//	REQUIRE(instance4.Coordinates(file_path) == coordinates);
//
//
//}

TEST_CASE("Return struct")
{

	KMLParser instance5;

	const QString file_path = "02_Spot_3.kml";
	QVector<QString> gains = {"Gain 54.4", "Gain 52.4", "Gain 50.4", "Gain 48.4", "Gain 46.4", "Gain 44.4"};

	Zone zone;

	REQUIRE(instance5.Zone_coords(file_path).file_name == "Intelsat-10-02-Spot-3");
	//REQUIRE(instance5.Zone_coords(file_path).zones[0].gain == gains[0]);

	//qDebug() << instance5.Zone_coords(file_path).file_name << endl;

	/*for (auto i = 0; i < instance5.Zone_coords(file_path).coordinates.size(); i++)
	{
		qDebug() << instance5.Zone_coords(file_path).gains[i] << endl;
		qDebug() << instance5.Zone_coords(file_path).coordinates[i] << endl;
	
	
	}*/

}

