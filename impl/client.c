#include "header.h"

//input in the below functions are the strings obtained from the 
//user through stdin in its entirety. 

struct packet* generateUnicastPacket(char* input)
{
	//code fore generating Unicast packets
	//Use for inputs starting from 1 and 2
}

struct packet* generateBroadcastPacket(char* input)
{
	//code for generating broadcast packets
	//Use for unputs starting with 3 aand 4
}

struct packet* generateControlPacket(char* input)
{
	//code for generating control packets
	//Use for inputs starting with 5
}

int main(int argc, char *argv[])
{
    if (argc != 4)
	{
		printf("Refer Qn for arguments\n");
        fflush(stdout);
		exit(1);
	}
    
	// extract the address and port from the command line arguments
	char* addr = argv[1];
	int port = atoi(argv[2]);
    int campus = atoi(argv[3]);
    char* department = argv[4];

	

    return 0;
}