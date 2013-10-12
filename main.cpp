#include <iostream>
#include <fstream>
#include "partio.h"
using namespace std;
using namespace Partio;

Partio::ParticlesDataMutable *data;
Partio::ParticleAttribute pHandle;
Partio::ParticleAttribute vHandle;
Partio::ParticleAttribute aHandle;


int main(int argc, char *argv[])
{
	if (argc == 3) {
		data = Partio::read(argv[1]);
	} else {
		cout << "NEED INPUT BGEO FILE, AND OUTPUT CSV FILE, EXITING!" << endl;
		return 0;
	}

	for (int i = 0; i < data->numAttributes(); i++) {
		Partio::ParticleAttribute attr;
		data->attributeInfo(i, attr);

		if (attr.name == "position") {
			pHandle = attr;
		}

	}

	ofstream ofile(argv[2]);

	for (int i = 0; i < data->numParticles(); i++) {
		const float *pos_d = data->data<float>(pHandle, i);
		ofile << pos_d[0] << " " << pos_d[1] << " " << pos_d[2] << endl;
	}
    ofile.close();
	return 0;
}
