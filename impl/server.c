#include "header.h"

#define PILANI 1
#define GOA 2
#define HYDERABAD 3

int pilaniSocketId, goaSocketId, hydSocketId;
int myCampus;


int serverSetupPilani(char* addr, int goaPort, int hydPort){
    myCampus = PILANI;
    //code for server setup
    return 1;
}
int serverSetupGoa(char* addr, int pilaniPort, int hydPort){
    myCampus = GOA;
    //code for server setup

    return 1;
    
}
int serverSetupHyderabad(char* addr, int pilaniPort, int goaPort){
    myCampus = HYDERABAD;
    //code for server setup

    return 1;
   
}
int main(int argc, char *argv[])
{
    if (argc != 5)
	{
		printf("Refer Qn for arguments\n");
		return -1;
	}
    char* addr = argv[1];
	int port1 = atoi(argv[2]);
    int port2 = atoi(argv[3]);
    int port3 = atoi(argv[4]);
    int campus = atoi(argv[5]);

    if(campus == PILANI){
        serverSetupPilani(addr, port1, port2);
    }
    else if(campus == GOA){
        serverSetupGoa(addr, port1, port2);
    }
    else if(campus == HYDERABAD){
        serverSetupHyderabad(addr, port1, port2);
    }
    else{
        printf("Invalid campus\n");
        return -1;
    }

    //server setup should be done by now
    //start listening for department connections and subsequently create threads to handle them

  
}



