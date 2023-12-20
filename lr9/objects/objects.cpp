#include "objects.h"

using namespace std;

int AbstractCar::getMilage()
{
    return totalDistance;
}

double AbstractCar::getFuelLevel()
{
    return fuelLevel;
}

AbstractCar::AbstractCar(int fuelConsumption, int maxFuel) : totalDistance(0), fuelLevel(0), fuelConsumption(fuelConsumption), maxFuel(maxFuel) {}

bool AbstractCar::drive(int kilometers)  {
    int requiredFuel = (kilometers * fuelConsumption) / 100;
    if (fuelLevel < requiredFuel) {
        std::cout << "Недостаточно топлива для прохождения дистанции." << std::endl;
        return false;
    }
    else {
        totalDistance += kilometers;
        fuelLevel -= requiredFuel;
        return true;
    }

}

void AbstractCar::refuel()  {
    fuelLevel = maxFuel;
    std::cout << "Бак заполнен" << std::endl;
}

void AbstractCar::printStatus()  {
    std::cout << "Общий пробег: " << totalDistance << " км" << std::endl;
    std::cout << "Остаток топлива в баке: " << fuelLevel << " литров" << std::endl;
}

Sedan::Sedan():AbstractCar(8, 60){}

Suv::Suv():AbstractCar(10, 70){}

Bus::Bus():AbstractCar(15, 150){}

int Bicycle::get_totalDistance()
{
    return totalDistance;
}

bool Bicycle::drive(int kilometrs)
{
    totalDistance += kilometrs;
    return true;
}

int Bicycle::getMilage()
{
    return totalDistance;
}

double Bicycle::getFuelLevel(){}

void Bicycle::refuel(){}

void Bicycle::printStatus()
{
    cout << "Общий пробег: " << get_totalDistance() << "km" << endl;
}



void Route::addPoint(const RoutePoint& point)
{
    points.push_back(point);
}

void Route::run(IVehicle* vehicle) {
    if (points.size() < 2)
    {
        cout << "there is less than 2 points";
    }
    else
    {
        for (int i = 1; i < points.size(); i++)
        {
            int distance = round(sqrt(pow(points[i - 1].xKm - points[i].xKm, 2) + pow(points[i - 1].yKm - points[i].yKm, 2)));
            bool driveSuccess = vehicle->drive(distance);
            if (!driveSuccess)
            {
                vehicle->refuel();
                if (!vehicle->drive(distance))
                {
                    cout << "не удалось проехать" << endl;
                    return;
                }
            }
            vehicle->printStatus();
        }
    }
}


