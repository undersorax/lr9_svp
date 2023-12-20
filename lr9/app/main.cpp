#include <../objects/objects.h>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2) { cout << "no argument (path to the file)"; return 0; }

    setlocale(LC_ALL, "RUS");

    vector <Route> routes;

    ifstream f1;

    f1.open(argv[1]);
    if (!f1)
    {
        cout << "файл не удалось открыть" << endl;
        return 0;
    }
    Route route_temp;
    double a = 0, b = 0;
    string c;
    while (!f1.eof())
    {
        f1 >> a;
        f1 >> b;
        f1 >> c;
        route_temp.addPoint({ a, b, c });
    }
    routes.push_back(route_temp);

    IVehicle* vehicles[4] = { new Bus, new Suv, new Sedan, new Bicycle };
    for (int j = 0; j < routes.size(); j++) {
        for (int i = 0; i < 4; i++) {
            routes[j].run(vehicles[i]);
            cout << "\n\n";
        }
    }
    for (int i = 0; i < 4; i++)
    {
        delete vehicles[i];
    }
    system("pause");
    f1.close();
    return 0;
}
