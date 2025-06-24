#include "WeatherData.h"
#include <iostream>

WeatherData::WeatherData(std::string date, double temperature, double humidity, double windSpeed) {
    this->date = date;
    this->temperature = temperature;
    this->humidity = humidity;
    this->windSpeed = windSpeed;
}

void WeatherData::displayWeatherInfo() const {
    std::cout << "Date: " << date << "\n";
    std::cout << "Temperature: " << temperature << " °C\n";
    std::cout << "Humidity: " << humidity << " %\n";
    std::cout << "Wind Speed: " << windSpeed << " m/s\n";
}

double WeatherData::getTemperature() const {
    return temperature;
}

double WeatherData::getHumidity() const {
    return humidity;
}

double WeatherData::getWindSpeed() const {
    return windSpeed;
}

std::string WeatherData::getDate() const {
    return date;
}
