#include <string.h>
#include <stdlib.h>
#include "Employee.h"

int main(void)
{
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char *phoneNumber);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double targetSalary);

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    //Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");
    

    //Example found for phone
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "213-555-1212");
    if (matchPtr != NULL)
        printf("Phone number 213-555-1212 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Phone number 213-555-1212 is NOT found in the record\n");
    //Example not found for phone
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "213-840-1234");
    if (matchPtr != NULL)
        printf("Phone number 213-840-1234 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Phone number 213-840-1234 is NOT found in the record\n");
    
    //Example found for salary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);
    if (matchPtr != NULL)
        printf("Employee salary $7.80 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary $7.80 is NOT found in the record\n");
    //Example not found for salary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.50);
    if (matchPtr != NULL)
        printf("Employee salary $6.50 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary $6.50 is NOT found in the record\n");

    return EXIT_SUCCESS;
}
