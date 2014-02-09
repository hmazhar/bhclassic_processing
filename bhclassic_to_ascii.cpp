#include <iostream>
#include <fstream>
#include <string>
#include "partio.h"
using namespace std;
using namespace Partio;

Partio::ParticlesDataMutable *data;
Partio::ParticleAttribute pHandle;
string output_filename, delimiter = " ";

int main(int argc, char *argv[]) {

	if (argc == 3) {
		data = Partio::read(argv[1]);
		output_filename = argv[2];

	} else if (argc == 4) {
		data = Partio::read(argv[1]);
		output_filename = argv[2];
		delimiter = argv[3];
	} else {
		cout << "NEED INPUT BHCLASSIC FILE, OUTPUT FILENAME AND OPTIONALLY DELIMITER, EXITING!" << endl;
		return 0;
	}

	for (int i = 0; i < data->numAttributes(); i++) {
		Partio::ParticleAttribute attr;
		data->attributeInfo(i, attr);

		if (attr.name == "position") {
			pHandle = attr;
		}
	}

	ofstream ofile(output_filename.c_str());

	for (int i = 0; i < data->numParticles(); i++) {
		const float *pos_d = data->data<float>(pHandle, i);
		ofile << pos_d[0] << delimiter << pos_d[1] << delimiter << pos_d[2] << endl;
	}
	ofile.close();
	return 0;
}
