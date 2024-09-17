#pragma once
#include <string>

using namespace std;

namespace WeatherSpace {
    class IWeatherSensor {
    public:
        virtual double TemperatureInC() const = 0;
        virtual int Precipitation() const = 0;
        virtual int Humidity() const = 0;
        virtual int WindSpeedKMPH() const = 0;
    };

    string Report(const IWeatherSensor& sensor) {
        int precipitation = sensor.Precipitation();
        // precipitation < 20 is a sunny day
        string report = "Sunny day";

        if (sensor.TemperatureInC() > 25) {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly cloudy";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }
}
