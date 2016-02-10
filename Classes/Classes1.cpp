#include <iostream>
#include <string>

class Country // task 1
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

class AltCountry
{
private:
	double GNP;
	unsigned long int population;
public:
	// Sets Gross National Product of a country
	void setGNP(double x);
	// Sets the population of a country
	void setPopulation(unsigned long int x);
	// Returns the Gross National Product of a country
	double getGNP() const;
	// Returns the population of a country
	unsigned long int getPopulation() const;
	// Calculates the GNP per Capita
	double calculateGNPPerCapita() const;
};

void AltCountry::setGNP(double x)
{
	GNP = x;
}

void AltCountry::setPopulation(unsigned long int x)
{
	population = x;
}

double AltCountry::getGNP() const
{
	return GNP;
}

unsigned long int AltCountry::getPopulation() const
{
	return population;
}

double AltCountry::calculateGNPPerCapita() const
{
	return GNP / population;
}

class Vehicle // task 4
{
public:
	std::string make;
	std::string model;
	unsigned long int milage;
	char fuelType;
};

void main()
{
	AltCountry example[2];

	example[0].setGNP(3000000);
	example[0].setPopulation(3000);
	double x = example[0].getGNP();
	x = example[0].getPopulation();
	x = example[0].calculateGNPPerCapita();

	example[1].setGNP(5400000);
	example[1].setPopulation(10000);
	x = example[1].getGNP();
	x = example[1].getPopulation();
	x = example[1].calculateGNPPerCapita();

	Country southAmerica[3]; // task 2 create array of 3 countries

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

	for(unsigned int i = 0; i < 3; i++) // task 3 print out country class
	{
		std::cout << "Number: " << i << "\nName: " << southAmerica[i].name << "\nLanguage: " << southAmerica[i].language << "\nPopulation: " << southAmerica[i].population
			<< "\nGDP: " << southAmerica[i].gdp << "\nLocation: " << southAmerica[i].location << "\nHighest Elevation: " << southAmerica[i].highestElevation 
			<< "\nHighest Point: " << southAmerica[i].highestPoint << std::endl  << std::endl ;
	}

	Vehicle volkswagen[3]; // task 5 create array of three vehicles

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

	for(unsigned int i = 0; i < 3; i++) // task 6 print out vehicle class
	{
		std::cout <<"Number: " << i <<  "\nMake: " << volkswagen[i].make <<  "\nModel: " << volkswagen[i].model <<  "\nMilage: " << volkswagen[i].milage 
			<<  "\nFuel Type: " << volkswagen[i].fuelType << std::endl << std::endl;
	}

	system("pause");
}