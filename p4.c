#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 26

int charToIndex(char c) {
    return toupper(c) - 'A';
}


char indexToChar(int idx) {
    return (idx % N) + 'A';
}


void matVecMult(int mat[][3], int vec[], int res[], int size) {
    for (int i = 0; i < size; i++) {
        res[i] = 0;
        for (int j = 0; j < size; j++) {
            res[i] = (res[i] + (mat[i][j] * vec[j])) % N;
        }
    }
}

void processMsg(int mode, int mat[][3], char msg[], int size) {
    int len = strlen(msg);

    for (int i = 0; i < len; i += size) {
        int vec[3] = {0};
        int res[3] = {0};

        for (int j = 0; j < size; j++) {
            if (i + j < len) {
                vec[j] = charToIndex(msg[i + j]);
            }
        }

        matVecMult(mat, vec, res, size);

        for (int j = 0; j < size; j++) {
            if (i + j < len) {
                msg[i + j] = indexToChar(res[j]);
            }
        }
    }
}

int main() {
    int size, mat[3][3];
    char msg[100], encMsg[100], decMsg[100];

    printf("Enter matrix size (2 or 3): ");
    scanf("%d", &size);

    printf("Enter key matrix elements:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Enter the message: ");
    scanf("%s", msg);
    strcpy(encMsg, msg);
   
    processMsg(1, mat, encMsg, size);
    printf("Encrypted message: %s\n", encMsg);


    printf("Decrypted message: %s\n", msg);

    return 0;
}



// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// void toUpperCase(char *str) {
//     for (int i = 0; i < strlen(str); i++) {
//         str[i] = toupper(str[i]);
//     }
// }

// int main() {
//     unsigned int encryptionMatrix[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
//     unsigned int decryptionMatrix[3][3] = {{8, 5, 10}, {21, 8, 21}, {21, 12, 8}};
    
//     unsigned int plaintextVector[3], ciphertextVector[3];
//     char plaintext[20];
//     int i, j, temp;
    
//     printf("Enter the plaintext (3 characters): \n");
//     scanf("%s", plaintext);

//     toUpperCase(plaintext);
    
//     if (strlen(plaintext) != 3) {
//         printf("Error: Plaintext must be exactly 3 characters long.\n");
//         return 1;
//     }

//     for (i = 0; i < 3; i++) {
//         plaintextVector[i] = plaintext[i] - 'A';
//     }

//     for (i = 0; i < 3; i++) {
//         temp = 0;
//         for (j = 0; j < 3; j++) {
//             temp += encryptionMatrix[i][j] * plaintextVector[j];
//         }
//         ciphertextVector[i] = temp % 26;
//     }

//     printf("\nEncrypted ciphertext: ");
//     for (i = 0; i < 3; i++) {
//         printf("%c", ciphertextVector[i] + 'A');
//     }

//     for (i = 0; i < 3; i++) {
//         temp = 0;
//         for (j = 0; j < 3; j++) {
//             temp += decryptionMatrix[i][j] * ciphertextVector[j];
//         }
//         plaintextVector[i] = temp % 26;
//     }

//     printf("\nDecrypted plaintext: ");
//     for (i = 0; i < 3; i++) {
//         printf("%c", plaintextVector[i] + 'A');
//     }

//     return 0;
// }
