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

TEST_CASE("Check parse coordinates")
{
	KMLParser instance5;

	const QString file_path = "02_SE_zone.kml";

	Intelsat intelsat = instance5.zone_coords(file_path);

	QVector<QPair<double, double>> coordinates = {
		{45.386746223462, 13.181295696355},
		{42.050382539545, 12.032097119667},
		{39.826334422264, 10.178926199335},
		{38.128760038462, 7.2869964086693},
		{37.310091904661, 4.7267376096803},
		{37.341515987541, 2.7781954014722},
		{38.069102684522, 0.57572423786537},
		{39.019317501561, -0.78571038280246},
		{40.4089854436, -1.9710338172251},
		{42.707532939741, -2.2774783872566},
		{44.918189810881, -1.7934254892289},
		{46.762732538231, -0.82606947755661},
		{48.255712765581, 0.31730184873227},
		{49.660803494797, 1.813050114365},
		{51.065311208023, 3.7475707860101},
		{52.29462068724, 6.4304624109006},
		{52.820805166456, 8.2304057667066},
		{52.498924462562, 10.677335328103},
		{51.065311208023, 12.5429720069},
		{48.973099028243, 13.290393558831},
		{45.386746223462, 13.181295696355},
	};

	REQUIRE(intelsat.zones[0].coordinates == coordinates);
}