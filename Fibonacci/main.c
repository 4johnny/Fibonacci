//
//  main.c
//  Fibonacci
//
//  Created by Johnny on 2015-01-14.
//  Copyright (c) 2015 Empath Solutions. All rights reserved.
//

#include <stdio.h>

int fibonacciIterative(int index) {
	
	if (index < 0) return -1;
	if (index == 0) return 0;
	
	// index >= 1
	int prevPrev;
	int prev = 0;
	int fibonacci = 1;
	for (; index > 1; index--) {
		
		prevPrev = prev;
		prev = fibonacci;
		
		fibonacci = prev + prevPrev;
	}

	return fibonacci;
}

int fibonacciRecursive(int index) {

	// Base Cases
	if (index < 0) return -1; // Input validation.
	if (index == 0) return 0;
	if (index == 1) return 1;
	
	// Recursive Case
	// index >= 2
	return fibonacciRecursive(index - 1) + fibonacciRecursive(index - 2);
}

int recursiveValueFibonacci(int remainingSteps, int previousNumber, int previousPreviousNumber) {
	
	if (remainingSteps == 0) return 0;
	if (remainingSteps == 1) return previousNumber;
	
	// remainingSteps >= 2
	int fibonacci = previousNumber + previousPreviousNumber;
	if (remainingSteps == 0) return fibonacci;
	
	return recursiveValueFibonacci(remainingSteps - 1, fibonacci, previousNumber);
}

int recursiveReferenceFibonacci(int remainingSteps, int *previousNumber, int *previousPreviousNumber) {
	if (remainingSteps == 0) return 0;
	if (remainingSteps == 1) return *previousNumber;
	
	// remainingSteps >= 2
	int fibonacci = *previousNumber + *previousPreviousNumber;
	if (remainingSteps == 0) return fibonacci;
	
	return recursiveReferenceFibonacci(remainingSteps - 1, &fibonacci, previousNumber);
}

int main(int argc, const char * argv[]) {

	int prevPrev = 0;
	int prev = 1;
	int fibonacciIndex = 20;
	printf("Fibonacci #%d\n", fibonacciIndex);
	printf("Iterative: %d\n", fibonacciIterative(fibonacciIndex));
	printf("Recursive: %d\n", fibonacciRecursive(fibonacciIndex));
	printf("Recursive By Val: %d\n", recursiveValueFibonacci(fibonacciIndex, 1, 0));
	printf("Recursive By Ref: %d\n", recursiveReferenceFibonacci(fibonacciIndex, &prev, &prevPrev));
	
	return 0;
}
