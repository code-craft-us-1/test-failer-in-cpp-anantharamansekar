#include "pch.h"
#include "WeatherReport.h"

using namespace WeatherSpace;

/// This is a stub for a weather sensor. For the sake of testing
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development

class SensorStub : public IWeatherSensor {
    int Humidity() const override {
        return 72;
    }

    int Precipitation() const override {
        return 70;
    }

    double TemperatureInC() const override {
        return 26;
    }

    int WindSpeedKMPH() const override {
        return 52;
    }
};

class SensorStub2 : public IWeatherSensor {
    int Humidity() const override {
        return 72;
    }

    int Precipitation() const override {
        return 18;
    }

    double TemperatureInC() const override {
        return 26;
    }

    int WindSpeedKMPH() const override {
        return 52;
    }
};

class SensorStub3 : public IWeatherSensor {
    int Humidity() const override {
        return 72;
    }

    int Precipitation() const override {
        return 65;
    }

    double TemperatureInC() const override {
        return 26;
    }

    int WindSpeedKMPH() const override {
        return 45;
    }
};

TEST(TestWeather, TestSunny) {

	SensorStub2 sensor;

  string report = Report(sensor);
  EXPECT_TRUE(report.find("Sunny day") != string::npos);
}

TEST(TestWeather, TestRainy) {
    SensorStub sensor;
    string report = Report(sensor);
    EXPECT_TRUE(report.find("rain") != string::npos);
}

TEST(TestWeather, TestHighPrecipitationAndLowWindspeed) {
    SensorStub3 sensor;

    // strengthen the assert to expose the bug
    // (function returns Sunny day, it should predict rain)
    string report = Report(sensor);
    EXPECT_TRUE(report.find("rain") != string::npos);
}