#include "xls.h"

using namespace std;

int main(){
	xls f;
    char filename [50] ="Estadistica_Semana8.xlsx";
    cout << "Bmp file:" << flush; // force output
    cout<< filename<<endl;
	
	f.OpenBmp(filename);
	f.PrintHeader();
}

