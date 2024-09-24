#include "pch.h"
#include "WeatherReport.h"

using namespace WeatherSpace;

/// This is a stub for a weather sensor. For the sake of testing
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development

class SensorStub : public IWeatherSensor{

    int m_humidity;
    int m_precipitation;
    int m_temp;
    int m_windspd;

public:
    SensorStub(int humidity, int precipitation, int temp, int windspd)
    {
        m_humidity = humidity;
        m_precipitation = precipitation;
        m_temp = temp;
        m_windspd = windspd;
    }

    int Humidity() const override {
        return m_humidity;
    }

    int Precipitation() const override {
        return m_precipitation;
    }

    double TemperatureInC() const override {
        return m_temp;
    }

    int WindSpeedKMPH() const override {
        return m_windspd;
    }
};

TEST(TestWeather, TestSunny) {

	SensorStub sensor(72,18,26,52);

  string report = Report(sensor);
  EXPECT_TRUE(report.find("Sunny day") != string::npos);
}

TEST(TestWeather, TestRainy) {
    SensorStub sensor(72,70,40,52);
    string report = Report(sensor);
    EXPECT_TRUE(report.find("rain") != string::npos);
}

TEST(TestWeather, TestHighPrecipitationAndLowWindspeed) {
    SensorStub sensor(72,65,26,45);

    // strengthen the assert to expose the bug
    // (function returns Sunny day, it should predict rain)
    string report = Report(sensor);
    EXPECT_TRUE(report.find("rain") != string::npos);
}