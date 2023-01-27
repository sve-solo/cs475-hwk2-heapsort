#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main(int argc, char *argv[]) {
	//Employee emp;

	//array to hold employees
	Employee employees[MAX_EMPLOYEES];

	//ask user to enter MAX_EMPLOYEES names and salaries
	for(int i = 0; i < MAX_EMPLOYEES; i++){
		printf("\nName: ");
		scanf("%s", employees[i].name);

		printf("Salary: ");
		scanf("%d", &employees[i].salary);
	}

	
	//print out list of employees
	printf("Before: ");
	printList(employees, MAX_EMPLOYEES);

	//buildHeap(employees, MAX_EMPLOYEES);
	//swap(&employees[2], &employees[8]);
	heapSort(employees, MAX_EMPLOYEES);

	//print out list of employees
	printf("After: ");
	printList(employees, MAX_EMPLOYEES);

	return 0;
}
