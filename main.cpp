#include "handle.h"


using namespace std;


int main(){

	//�ŧi�@��assembler����
	handle assembler;

	assembler.inputTxtFile();
    assembler.pass1();
    assembler.pass2();
    assembler.opjectProgram();
	return 0;
}


