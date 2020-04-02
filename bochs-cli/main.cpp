#include <iostream>

#include "config.h"
#include "debug.h"

using namespace std;

int main() {

	const Bit8u *buffer = reinterpret_cast<const Bit8u *>("boch cli");
	cout << crc32(buffer, 8)<< endl;

	return 0;
}
