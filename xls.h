#include "xlsx.h"

xlsx clase;

class xls{
	private:
		char *file_name;
		ifstream file_bmp;

		void ReadHeader(){
			file_bmp.seekg(0, ios_base::beg);
			file_bmp.read((char *) &reg_header, sizeof(reg_header));
			clase.pack(reg_header);
		};

	public:
		char reg_header[76];
		void OpenBmp(const char * filename){	
			file_name = (char *)filename;
			file_bmp.open(filename, ifstream::in|ifstream::binary);
			ReadHeader();
		};		
		void PrintHeader(){
			clase.unpack();
		};
};