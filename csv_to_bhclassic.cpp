#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "partio.h"
using namespace std;
using namespace Partio;

Partio::ParticlesDataMutable *data;
Partio::ParticleAttribute pHandle;
Partio::ParticleAttribute vHandle;
Partio::ParticleAttribute aHandle;
string output_filename, delimiter = " ";

int main(int argc, char *argv[]) {

string temp;

 Partio::ParticlesDataMutable& data=*Partio::create();
 Partio::ParticleAttribute positionAttr=data.addAttribute("position",Partio::VECTOR,3);


ifstream ifile(argv[1]);
while(ifile.fail()==false){

	getline(ifile,temp);
	if(ifile.fail()==false){
		std::replace( temp.begin(), temp.end(), ',', ' ');

		Partio::ParticleIndex index=data.addParticle();
        float* pos=data.dataWrite<float>(positionAttr,index);
        stringstream ss(temp);

        ss>>pos[0]>>pos[1]>>pos[2];

}
}

 Partio::write(argv[2],data);
	ifile.close();
	return 0;
}
	