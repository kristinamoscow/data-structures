#include <iostream>
#include <random>
#include <limits>
#include <iomanip>
#include <list>

using namespace std;

#include "LinkedList.h"
#include "Cycler.h"

class myRand {
public:
    myRand() = default;
    myRand(std::mt19937::result_type seed) : eng(seed) {}
    int getNumber(int min, int max);

private:        
	std::mt19937 eng{ std::random_device{}() };
};

int myRand::getNumber(int min, int max) {
	return std::uniform_int_distribution<int>{min, max}(eng);
}

int main() {
	myRand rd;
	int n = rd.getNumber(1, 15);

	LinkedList<int> p;
	
	for (int i = 0; i < n; i++) {
		p.add(rd.getNumber(10, 99));
	}
	cout << p << endl;

	unsigned int distance;
	cin >> distance;

	Cycler::addCycle(p, distance);
	if (Cycler::isCycled(p)) {
		cout << (Cycler::findCycle(p))->data << endl;
		Cycler::removeCycle(p);
	}

	cout << p;

	return 0;
}