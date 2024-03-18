#include "header.h"

void printPacket(struct packet *p){  //always follow this format for printing the packet
    printf("{\n");
    printf("    Version: %d\n", p->version);
    printf("    Header Length: %d\n", p->headerLength);
    printf("    Total Length: %d\n", p->totalLength);
    printf("    Source Department: %d\n", p->srcDept);
    printf("    Destination Department: %d\n", p->destDept);
    printf("    CheckSum: %d\n", p->checkSum);
    printf("    Hops: %d\n", p->hops);
    printf("    Type: %d\n", p->type);
    printf("    ACK: %d\n", p->ACK);
    if(p->headerLength == 6){
        printf("    Source Campus: %d\n", p->srcCampus);
        printf("    Destination Campus: %d\n", p->destCampus);
    }
    printf("    Data: %s\n", p->data);
    printf("}\n");
}

unsigned char* serialize( struct packet* p){
    //unsigned char *buffer = 
    
    //code for serialization
    //return buffer;
}

struct packet *deserialize(unsigned char* buffer){
    // struct packet *p;
    // code for deserialization

    // return p;
}

struct packet *generatePacket(int version, int headerLength, int totalLength, 
                              int srcDept, int destDept, int checkSum, int hops, 
                              int type, int ACK, int srcCampus, int destCampus, char* data) {
    //feel free to write your own function with more customisations. This is a very basic func 
    struct packet *p;
    p = (struct packet *)malloc(sizeof(struct packet));
    p->version = version;
    p->headerLength = headerLength;
    p->totalLength = totalLength;
    p->srcDept = srcDept;
    p->destDept = destDept;
    p->checkSum = checkSum;
    p->hops = hops;
    p->type = type;
    p->ACK = ACK;
    p->srcCampus = srcCampus;
    p->destCampus = destCampus;
    strcpy(p->data, data);
    return p;
}
