#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <limits>
#include <stdio.h>
#include <stdint.h> 
#include <cstring>

using namespace std;

class xlsx{
    public:
    char* TYPE[8];
    char* CLSID[16];
    char * minVer[2];
    char * maxVer[2];
    char * byOrder[2];
    char * secShift[2];
    char * minSecShift[2];
    char * Reserved[6];
    char * noDir[4];
    char * noFat[4];
    char * FDir[4];
    char * transSigna[4];
    char * minStream[4];
    char * FminFat[4];
    char * NominFat[4];
    char * FDifat[4];
    char * NoDifat[4];

    void pack(char paquete[76]){
            
        char tipo[8];
        tipo[0]=paquete[0];
        tipo[1]=paquete[1];
        tipo[2]=paquete[2];
        tipo[3]=paquete[3];
        tipo[4]=paquete[4];
        tipo[5]=paquete[5];
        tipo[6]=paquete[6];
        tipo[7]=paquete[7];

        char clsid[16];
        clsid[0]=paquete[8];
        clsid[1]=paquete[9];
        clsid[2]=paquete[10];
        clsid[3]=paquete[11];
        clsid[4]=paquete[12];
        clsid[5]=paquete[13];
        clsid[6]=paquete[14];
        clsid[7]=paquete[15];
        clsid[8]=paquete[16];
        clsid[9]=paquete[17];
        clsid[10]=paquete[18];
        clsid[11]=paquete[19];
        clsid[12]=paquete[20];
        clsid[13]=paquete[21];
        clsid[14]=paquete[22];
        clsid[15]=paquete[23];

        char minver[2];
        minver[0]=paquete[24];
        minver[1]=paquete[25];

        char maxver[2];
        maxver[0]=paquete[26];
        maxver[1]=paquete[27];

        char byorder[2];
        byorder[0]=paquete[28];
        byorder[1]=paquete[29];

        char secshift[2];
        secshift[0]=paquete[30];
        secshift[1]=paquete[31];

        char minsecshift[2];
        minsecshift[0]=paquete[32];
        minsecshift[1]=paquete[33];

        char reserver[6];
        reserver[0]=paquete[34];
        reserver[1]=paquete[35];
        reserver[2]=paquete[36];
        reserver[3]=paquete[37];
        reserver[4]=paquete[38];
        reserver[5]=paquete[39];

        char nodir[4];
        nodir[0]=paquete[40];
        nodir[1]=paquete[41];
        nodir[2]=paquete[42];
        nodir[3]=paquete[43];

        char nofat[4];
        nofat[0]=paquete[44];
        nofat[1]=paquete[45];
        nofat[2]=paquete[46];
        nofat[3]=paquete[47];

        char fdir[4];
        fdir[0]=paquete[48];
        fdir[1]=paquete[49];
        fdir[2]=paquete[50];
        fdir[3]=paquete[51];

        char transsigna[4];
        transsigna[0]=paquete[52];
        transsigna[1]=paquete[53];
        transsigna[2]=paquete[54];
        transsigna[3]=paquete[55];

        char minstream[4];
        minstream[0]=paquete[56];
        minstream[1]=paquete[57];
        minstream[2]=paquete[58];
        minstream[3]=paquete[59];
        
        char fminfat[4];
        fminfat[0]=paquete[60];
        fminfat[1]=paquete[61];
        fminfat[2]=paquete[62];
        fminfat[3]=paquete[63];

        char nominfat[4];
        nominfat[0]=paquete[64];
        nominfat[1]=paquete[65];
        nominfat[2]=paquete[66];
        nominfat[3]=paquete[67];

        char fdiffat[4];
        fdiffat[0]=paquete[68];
        fdiffat[1]=paquete[69];
        fdiffat[2]=paquete[70];
        fdiffat[3]=paquete[71];


        char nodiffat[4];
        nodiffat[0]=paquete[68];
        nodiffat[1]=paquete[69];
        nodiffat[2]=paquete[70];
        nodiffat[3]=paquete[71];
        

        memcpy(TYPE,tipo,8);
        memcpy(CLSID,clsid,16);
        memcpy(minVer,minver,2);
        memcpy(maxVer,maxver,2);
        memcpy(byOrder,byorder,2);
        memcpy(secShift,secshift,2);
        memcpy(minSecShift,minsecshift,2);
        memcpy(Reserved,reserver,6);
        memcpy(noDir,nodir,4);
        memcpy(noFat,nofat,4);
        memcpy(FDir,fdir,4);
        memcpy(transSigna,transsigna,4);
        memcpy(minStream,minstream,4);
        memcpy(FminFat,fminfat,4);
        memcpy(NominFat,nominfat,4);
        memcpy(FDifat,fdiffat,4);
        memcpy(NoDifat,nodiffat,4);
    };
    void unpack(){
        char type[9];
        memcpy(type,&TYPE,8);
        type[8]='\0';
        
        char clsid[17];
        memcpy(clsid,&CLSID,16);
        clsid[16]='\0';
        
        uint16_t minver;
        memcpy(&minver,minVer,2);

        uint16_t maxver;
        memcpy(&maxver,maxVer,2);

        uint16_t byte;
        memcpy(&byte,byOrder,2);

        uint16_t sector;
        memcpy(&sector,secShift,2);

        uint16_t minsec;
        memcpy(&minsec,minSecShift,2);
        
        char reserver[7];
        memcpy(reserver,&Reserved,6);
        reserver[6]-'\0';

        int nodir;
        memcpy(&nodir,noDir,4);

        int nofat;
        memcpy(&nofat,noFat,4);

        char fdir[5];
        memcpy(fdir,&FDir,4);
        fdir[4]='\0';

        int trans;
        memcpy(&trans,transSigna,4);

        int minstream;
        memcpy(&minstream,minStream,4);

        char ffat[5];
        memcpy(ffat,&FminFat,4);
        ffat[4]='\0';

        char fdiffat[5];
        memcpy(fdiffat,FDifat,4);
        fdiffat[4]='\0';

        int nodif;
        memcpy(&nodif,NoDifat,4);

        cout<<"*************************"<<endl;
	    cout << "Tipo: " << type << endl;
        cout << "CLSID: " <<dec<< clsid << endl;
        cout<<"Minor Version: "<<minver<<endl;
        cout<<"Major Version: "<<dec<<maxver<<endl;
        cout<<"Byte Order: "<<byte<<endl;
        cout<<"Sector Shift: "<<dec<<sector<<endl;
        cout<<"Mini Sector Shift: "<<dec<<minsec<<endl;
        cout<<"Reserved: "<<reserver<<endl;
        cout<<"Number Of Directory Sectors: "<<nodir<<endl;
        cout<<"Number of FAT Sectors: "<<nofat<<endl;
        cout<<"First Directory Sector Location: "<<fdir<<endl;
        cout<<"Transaction Signature Number: "<<trans<<endl;
        cout<<"Mini Stream CutOff Size: "<<minstream<<endl;
        cout<<"First Mini FAT Location: "<<ffat<<endl;
        cout<<"First DIFAT Sector Location: "<<fdiffat<<endl;
        cout<<"Number Of DIFAT Sectors: "<<nodif<<endl;
        cout<<"*************************"<<endl;
    };
};