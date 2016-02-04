#include <iostream>
#include <string>

class Country
{
public:
	std::string name;
	unsigned long int population;
	double gdp;
	std::string language;
	std::string location;
	unsigned int highestElevation;
	std::string highestPoint;
};

class Vehicle
{
public:
	std::string make;
	std::string model;
	unsigned long int milage;
	char fuelType;
};

void main()
{
	Country southAmerica[3];

	southAmerica[0].name = "Brazil";
	southAmerica[0].language = "Portuguese";
	southAmerica[0].population = 205338000;
	southAmerica[0].gdp = 300208000000;
	southAmerica[0].location = "East";
	southAmerica[0].highestElevation = 1491;
	southAmerica[0].highestPoint = "Pico da Neblina";

	southAmerica[1].name = "Argentina";
	southAmerica[1].language = "Spanish";
	southAmerica[1].population = 43417000;
	southAmerica[1].gdp = 964279000000;
	southAmerica[1].location = "South";
	southAmerica[1].highestElevation = 6960;
	southAmerica[1].highestPoint = "Ceroo Aconcagua";

	southAmerica[2].name = "Colombia";
	southAmerica[2].language = "Spanish";
	southAmerica[2].population = 48400388;
	southAmerica[2].gdp = 682977000000;
	southAmerica[2].location = "North";
	southAmerica[2].highestElevation = 5775;
	southAmerica[2].highestPoint = "Pico Simón Bolívar, La Guajira";

	for(unsigned int i = 0; i < 3; i++)
	{
		std::cout << "Number: " << i << "\nName: " << southAmerica[i].name << "\nLanguage: " << southAmerica[i].language << "\nPopulation: " << southAmerica[i].population
			<< "\nGDP: " << southAmerica[i].gdp << "\nLocation: " << southAmerica[i].location << "\nHighest Elevation: " << southAmerica[i].highestElevation 
			<< "\nHighest Point: " << southAmerica[i].highestPoint << std::endl  << std::endl ;
	}

	Vehicle volkswagen[3];

	volkswagen[0].make = "Volkswagen";
	volkswagen[0].model = "Golf";
	volkswagen[0].milage = 500000;
	volkswagen[0].fuelType = 'D';

	volkswagen[1].make = "Volkswagen";
	volkswagen[1].model = "Beetle";
	volkswagen[1].milage = 1000;
	volkswagen[1].fuelType = 'U';

	volkswagen[2].make = "Volkswagen";
	volkswagen[2].model = "Jetta";
	volkswagen[2].milage = 250000;
	volkswagen[2].fuelType = 'U';

	for(unsigned int i = 0; i < 3; i++)
	{
		std::cout <<"Number: " << i <<  "\nMake: " << volkswagen[i].make <<  "\nModel: " << volkswagen[i].model <<  "\nMilage: " << volkswagen[i].milage 
			<<  "\nFuel Type: " << volkswagen[i].fuelType << std::endl << std::endl;
	}

	system("pause");
}