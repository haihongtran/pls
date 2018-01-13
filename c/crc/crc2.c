#include <stdio.h>
#include <string.h>
#define N strlen(g)

char g[] = "10001000000100001";
char t[32] = {
    50, 48,  49, 49,  49, 48, 50,  49,  0,
    84, 114, 97, 110, 32, 72, 111, 110, 103, 32, 72, 97, 105, 0,
    49, 52,  48, 53,  49, 57, 57,  51,  0
};

char csArray[48];
char inputArray[48];
char csStruct[48];
char inputStruct[48];

typedef struct information {
    char id[9]; //9 bytes
    char fullname[14]; // 14 bytes
    char a[9]; //9 bytes
    char append[16]; // 16 bytes
} info;

int a,e,c;

void xor(char *cs)
{
    for (c = 1; c < N; c++)
        cs[c] = ((cs[c] == g[c])? '0':'1');
}

void crc(char* input, char* cs)
{
    for (e = 0; e < N; e++)
        cs[e] = input[e];
    do
    {
        if (cs[0]=='1')
            xor(cs);
        for (c=0;c<N-1;c++)
            cs[c]=cs[c+1];
        cs[c]=input[e++];
    }
    while (e<=a+N-1);
}

int main()
{
    int i;
    info *me;

    //Copy data from t to struct
    for (i = 0; i < 9; i++){
        (me->id)[i] = t[i];
    }
    for (i = 0; i < 14; i++){
        (me->fullname)[i] = t[i+9];
    }
    for (i = 0; i < 9; i++){
        (me->a)[i] = t[i+23];
    }
    // Append 16 '0' to Struct
    for (i = 0; i < N-1; i++){
        (me->append)[i] = '0';
    }

    a = 32; //length of array t
    // Display data in
    printf("Data in is: ");
    for (i = 0; i < a; i++)
    {
        printf("%c", t[i]);
    }
    printf("\nGenerating polynomial : %s", g);

    // Copy from t to input
    for (e = 0; e < a; e++)
    {
        inputArray[e] = t[e];
    }
    // Append '0' to Array
    for (e = a; e < a+N-1; e++) {
        inputArray[e] = '0';
        /* inputStruct[e] = '0'; */
        /* printf("\ne = %d, 0 appended.", e); */
    }

    /* for (i = 0; i < a+N-1; i++){ */
    /*     if (inputArray[i] == inputStruct[i]) */
    /*         printf("\ni = %d, True.", i); */
    /*     else */
    /*         printf("\ni = %d, False.", i); */
    /* } */

    /* printf("\n----------------------------------------"); */
    /* printf("\nModified data for Array is : "); */
    /* for (i = 0; i < a+N-1; i++) { */
    /*     printf("%c", inputArray[i]); */
    /* } */
    /* printf("\nModified data for Struct is : "); */
    /* for (i = 0; i < a+N-1; i++) { */
    /*     printf("%c", inputStruct[i]); */
    /* } */
    /* printf("\n----------------------------------------"); */

    crc(inputArray, csArray);
    /* crc(inputStruct, csStruct); */
    crc((char*)me, csStruct);

    printf("\nChecksum for Array is: %s", csArray);
    printf("\nChecksum for Struct is: %s", csStruct);
    printf("\n----------------------------------------");
    if (!strcmp(csArray, csStruct))
        printf("\nCRC encoded data for Array and Struct are IDENTICAL.");
    else
        printf("\nCRC encoded data for Array and Struct are DIFFERENT.");
    /* for (e = a; e < a+N-1; e++) { */
    /*     inputArray[e] = csArray[e-a]; */
    /*     inputStruct[e] = csStruct[e-a]; */
    /* } */
    /* printf("\n----------------------------------------"); */
    /* printf("\nFinal codeword for Array is : "); */
    /* for (i = 0; i < a+N-1; i++) { */
    /*     printf("%c", inputArray[i]); */
    /* } */
    /* printf("\nFinal codeword for Struct is : "); */
    /* for (i = 0; i < a+N-1; i++) { */
    /*     printf("%c", inputStruct[i]); */
    /* } */
    printf("\n----------------------------------------\n");

    return 0;
}
