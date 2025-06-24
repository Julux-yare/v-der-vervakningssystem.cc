#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <string>
#include <vector>

class WeatherData {
private:
    std::string date;        // Datum för väderdata
    double temperature;      // Temperatur för den dagen (i Celsius)
    double humidity;         // Luftfuktighet för den dagen (%)
    double windSpeed;       // Vindhastighet för den dagen (m/s)

public:
    WeatherData(std::string date, double temperature, double humidity, double windSpeed);
    void displayWeatherInfo() const;  // Visa väderinformation för en viss dag
    double getTemperature() const;   // Hämta temperatur
    double getHumidity() const;      // Hämta luftfuktighet
    double getWindSpeed() const;     // Hämta vindhastighet
    std::string getDate() const;     // Hämta datum
};

#endif
