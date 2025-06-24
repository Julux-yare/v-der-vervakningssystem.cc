#include <iostream>
#include <vector>
#include "WeatherData.h"

class WeatherStation {
private:
    std::vector<WeatherData> records;  // Lista över väderdata för olika dagar

public:
    void addWeatherData(std::string date, double temperature, double humidity, double windSpeed);  // Lägg till väderdata
    void showAllWeatherData() const;  // Visa alla väderdata
    void showAverageTemperature() const;  // Visa genomsnittlig temperatur
};

void WeatherStation::addWeatherData(std::string date, double temperature, double humidity, double windSpeed) {
    records.push_back(WeatherData(date, temperature, humidity, windSpeed));  // Lägg till väderdata
    std::cout << "Weather data for " << date << " added successfully.\n";
}

void WeatherStation::showAllWeatherData() const {
    if (records.empty()) {
        std::cout << "No weather data available.\n";
        return;
    }

    std::cout << "\nWeather Data:\n";
    for (const auto& record : records) {
        record.displayWeatherInfo();
        std::cout << "----------------------\n";
    }
}

void WeatherStation::showAverageTemperature() const {
    if (records.empty()) {
        std::cout << "No weather data available.\n";
        return;
    }

    double totalTemperature = 0.0;
    for (const auto& record : records) {
        totalTemperature += record.getTemperature();  // Summera temperaturer
    }

    double averageTemperature = totalTemperature / records.size();  // Beräkna genomsnittlig temperatur
    std::cout << "Average Temperature: " << averageTemperature << " °C\n";
}

int main() {
    WeatherStation station;  // Skapa ett väderstationsobjekt
    int choice;
    std::string date;
    double temperature, humidity, windSpeed;

    do {
        // Meny för användaren
        std::cout << "\nWeather Station Menu:\n";
        std::cout << "1. Add Weather Data\n";
        std::cout << "2. Show All Weather Data\n";
        std::cout << "3. Show Average Temperature\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::cin.ignore();  // Ignorera newline från tidigare input
                std::getline(std::cin, date);  // Läs datum
                std::cout << "Enter temperature (°C): ";
                std::cin >> temperature;  // Läs temperatur
                std::cout << "Enter humidity (%): ";
                std::cin >> humidity;  // Läs luftfuktighet
                std::cout << "Enter wind speed (m/s): ";
                std::cin >> windSpeed;  // Läs vindhastighet
                station.addWeatherData(date, temperature, humidity, windSpeed);  // Lägg till väderdata
                break;

            case 2:
                station.showAllWeatherData();  // Visa alla väderdata
                break;

            case 3:
                station.showAverageTemperature();  // Visa genomsnittlig temperatur
                break;

            case 4:
                std::cout << "Goodbye!\n";  // Avsluta programmet
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";  // Ogiltigt alternativ
        }
    } while (choice != 4);  // Fortsätt tills användaren väljer att avsluta

    return 0;  // Programmet avslutas här
}
