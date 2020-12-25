#include<vector>
#include<iostream>
using namespace std;

class ParkingSystem {
public:
    vector<int> lots;
    ParkingSystem(int big, int medium, int small) {
        lots.reserve(3);
        lots[0] = big;
        lots[1] = medium;
        lots[2] = small;
    }
    
    bool addCar(int carType) {
        int index = carType - 1;
        if(lots[index] > 0) {
            lots[index]--;
            return true;
        }

        return false;
    }
};

int main() {
    ParkingSystem p (1, 1, 0);

    cout << p.addCar(1) << endl;
    cout << p.addCar(2) << endl;
    cout << p.addCar(3) << endl;
    cout << p.addCar(1) << endl;

    cout<< endl;
}