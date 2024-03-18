#include "header.h"


void ser_test(unsigned char ans[], unsigned char* buffer, int size)
{
    printf("Serialized buffer:\n");
    int c = size;
    char* m = buffer;
    while(c--){
        printf("0x%02x ", *(m++));
    }
    printf("\n");

    for( int i = 0; i < 11; i++){
        if( buffer[i] != ans[i]){
            printf("Serialization Test Failed\n");
            return;
        }
    }
    printf("Serialization Test Passed\n");
}


void deser_test(struct packet* p, struct packet* p2)
{
    printf("Deserialized struct:\n");
    printPacket(p2);
    if(p->version != p2->version)
        printf("Deserialization Test Failed\n");
    else if(p->headerLength != p2->headerLength)
        printf("Deserialization Test Failed\n");
    else if(p->totalLength != p2->totalLength)
        printf("Deserialization Test Failed\n");
    else if(p->srcDept != p2->srcDept)
        printf("Deserialization Test Failed\n");
    else if(p->destDept != p2->destDept)
        printf("Deserialization Test Failed\n");
    else if(p->checkSum != p2->checkSum)
        printf("Deserialization Test Failed\n");
    else if(p->hops != p2->hops)
        printf("Deserialization Test Failed\n");
    else if(p->type != p2->type)
        printf("Deserialization Test Failed\n");
    else if(p->ACK != p2->ACK)
        printf("Deserialization Test Failed\n");
    else if(p->headerLength == 6 && p->srcCampus != p2->srcCampus)
        printf("Deserialization Test Failed\n");
    else if(p->headerLength == 6 && p->destCampus != p2->destCampus)
        printf("Deserialization Test Failed\n");
    else if(strcmp(p->data, p2->data))
        printf("Deserialization Test Failed\n");
    else
        printf("Deserialization Test Passed\n");
}


int main(int argc, char *argv[])
{
    printf("TEST 1:\n");
    struct packet *p;
    p = (struct packet *)malloc(sizeof(struct packet));
    p = generatePacket( 1, 6, 11, 2, 3, 300, 1, 2, 3, 4, 2, "Hello");
    unsigned char ans[11] = {22, 11, 77, 44, 43, 66, 72, 101, 108, 108, 111};
    unsigned char *buffer = serialize(p);
    ser_test(ans, buffer, 11);
    if((void*)p == (void*)buffer)
    {
        printf("Deserialization Test Failed");
    }
    else
    {
        struct packet* p_ans = deserialize(buffer);
        deser_test(p, p_ans);
    }
    printf("\nTEST 2:\n");
    struct packet *p2;
    p2 = (struct packet *)malloc(sizeof(struct packet));
    p2 = generatePacket( 1, 6, 19, 1, 0, 300, 0, 0, 0, 1, 2, "Mayday!Mayday");
    unsigned char ans2[19] = {0x16, 0x13, 0x21, 0x2c, 0x00, 0x12, 0x4d, 0x61,  0x79, 0x64, 0x61, 0x79, 0x21, 0x4d, 0x61,  0x79, 0x64, 0x61, 0x79};
    unsigned char *buffer2 = serialize(p2);
    ser_test(ans2, buffer2, 19);
    if((void*)buffer2 == (void*)p2)
    {
        printf("Deserialization Test Failed");
    }
    else
    {
        struct packet* p_ans2 = deserialize(buffer2);
        deser_test(p2, p_ans2);
    }
    printf("\nTEST 3:\n");
    struct packet *p3;
    p3 = (struct packet *)malloc(sizeof(struct packet));
    p3 = generatePacket( 1, 5, 17, 1, 0, 300, 0, 0, 0, 4, 5, "Internal msg");
    unsigned char ans3[17] = {0x15, 0x11, 0x21, 0x2c, 0x00, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0x20, 0x6d, 0x73, 0x67};
    unsigned char *buffer3 = serialize(p3);
    ser_test(ans3, buffer3, 17);
    if((void*)buffer3 == (void*)p3)
    {
        printf("Deserialization Test Failed\n");
    }
    else
    {
        struct packet* p_ans3 = deserialize(buffer3);
        deser_test(p3, p_ans3);
    }
}