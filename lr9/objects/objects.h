#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

class Objects
{

public:
    Objects();
};

struct RoutePoint
{
    double xKm;
    double yKm;
    std::string name;
};

class IVehicle
{
public:
    virtual bool drive(int kilometrs) = 0;
    virtual void refuel() = 0;
    virtual void printStatus() = 0;
    virtual double getFuelLevel() = 0;
    virtual int getMilage() = 0;
};

class AbstractCar : public IVehicle
{
protected:
    int totalDistance;
    double fuelLevel;
    double fuelConsumption;
    double maxFuel;

public:
    AbstractCar(int fuelConsumption, int maxFuel);
    bool drive(int kilometers) override;
    void refuel() override;
    void printStatus() override;
    double getFuelLevel() override;
    int getMilage() override;
};

class Sedan : public AbstractCar
{
public:
    Sedan();
};

class Suv : public AbstractCar
{
public:
    Suv();
};

class Bus : public AbstractCar
{
public:
    Bus();
};

class Bicycle : public IVehicle
{
private:
    int totalDistance = 0;
public:
    int get_totalDistance();
    bool drive(int kilomentrs) override;
    void refuel() override;
    void printStatus() override;
    double getFuelLevel() override;
    int getMilage() override;
};

class Route
{
private:
    std::vector<RoutePoint> points;
public:
    void addPoint(const RoutePoint& point);
    void run(IVehicle* vehicle);
};


#endif // OBJECTS_H
