/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	buildHeap(A, n);

	while(n > 0){
		swap(&A[n - 1], &A[0]);
		//printList(A, size);
		n--;


		for(int i = 0; i < n - 1; i++){
			heapify(A, i, n);
		}

	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	for(int i = n/2; i >= 0; i--){
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	
	//calculate left child index
	int li = (2 * (i + 1)) -1;
	//calculate right child index
	int ri = (2 * (i + 1)); 

	//if node has no children, break out of method
	if(li >= n && ri >= n){
		return;
	}

	//get left child
	Employee leftChild = A[li];

	//get right child
	Employee rightChild = A[ri];

	//smaller child element
	Employee smallerEle;
	//index of smaller element
	int smaller;

	//if A[i] is not smaller than children, do nothing
	if(A[i].salary <= leftChild.salary && A[i].salary <= rightChild.salary){
		return;
	}
	else{
		//if there is only one child, the left node, set leftChild to smaller
		if(ri >= n){
			smallerEle = leftChild;
			smaller = li;
		}
		// //if there is only one child, the right node
		// else if(li >= n){
		// 	smallerEle = rightChild;
		// 	smaller = ri;
		// }
		//if both children exist:
		else if(leftChild.salary <= rightChild.salary){
			smallerEle = leftChild;
			smaller = li;
		}
		else{
			smallerEle = rightChild;
			smaller = ri;
		}
		//swap elements
		if(A[i].salary > smallerEle.salary){
			Employee temp = A[i];
			A[i] = smallerEle;
			A[smaller] = temp;

			//recursively call heapify()
			heapify(A, smaller, n);
			//stop when A[i].salary is smaller than it's children
		}
	}

}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	//temp gets the content of e1 (since e1 is deref'd)
	Employee temp = *e1;
	
	//put content of e2 into content e1 (since e1 and e2 are deref'd)
	*e1 = *e2;
	
	//puts content of e1 into content e2 (since e2 is deref'd)
	*e2 = temp;
	
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	for(int i = 0; i < n; i++){
		printf("[id=%s ", A[i].name);
		printf("sal=%d]  ", A[i].salary);
	}
	printf("\n\n");
}
