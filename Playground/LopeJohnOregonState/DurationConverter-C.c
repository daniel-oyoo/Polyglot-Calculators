/*
Example Usage
./DurationConverter 3600 sec hour
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define VALID_TYPE_NUM 4
#define ERROR_MSG_LEN 3
static char *ValidTypes[] = {"second","minute","hour","day"};

bool TypeValidation_Helper(char *type){
    for (int i = 0; i < VALID_TYPE_NUM; i++){
        if (strcmp(type, ValidTypes[i]) == 0)
            return true; // input type matches one of the valid types
    }
    return false; // input type does not match one of the valid types
}

/* Checks to see if any input validation measures created an error message
    true - if there is an error present
    false - if there is not an error present
*/
bool CheckforErrors(int error_msgs_len ,char *error_msgs[]){
    for (int i = 0; i < error_msgs_len; i++){
        if (error_msgs[i] != NULL)
            return true; // there is an error
    }
    return false; // no errors
}

bool DurationConverter(int val, char *source, char *target){
    int error_msgs_len = ERROR_MSG_LEN;
    char *error_msgs[ERROR_MSG_LEN] = {NULL, NULL, NULL};
    /*Check if value is less than 0*/
    if (val < 0){
        error_msgs[0] = "Value is less than";
    }

    /*Check if incorrect source type*/
    if (!TypeValidation_Helper(source)){
        error_msgs[1] = "Incorrect source type";
    }

    /*Check if incorrect target type*/
    if (!TypeValidation_Helper(target)){
        error_msgs[2] = "Incorrect target type";
    }

    /*If there is an error present*/
    if (CheckforErrors(error_msgs_len, error_msgs)){
        for (int i = 0; i < error_msgs_len; i++){
            if (error_msgs[i] != NULL) // print error messages
                printf("%s\n", error_msgs[i]);
        }
        return false; // exit program
    }

    
}

int main(int argc, char *argv[]){
    /*Input Validation*/
    if (argc < 4){
        char *error_msg = "Please enter 3 arguments";
        printf("%s\n", error_msg);
        return 1;
    }

    /*TypeCast and return function*/
    int input_val = atoi(argv[1]);
    if(DurationConverter(input_val, argv[1], argv[2]))
        return 0;
    else
        return 1;
}