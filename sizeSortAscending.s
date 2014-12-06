/*
 * Filename: sizeSortAscending.s
 * Author: jinye xu
 * Description: sorting the file from small size to big size
 * Date: Nov. 29
 * Source of Help: Piazza, stackOverflow
 */

	.global sizeSortAscending

	.section	".text"
/*
 * Function name: sizeSortAscending()
 * Funciton prototype: int sizeSortAscending( const void *p1, const 
 *                                            void *p2);
 * Description : Compares size of two files
 * Parameters: arg 1: const void *p1 is a pointer to the first fileInfo struct
 * 	       arg 2: const void *p2 is a pointer to the second fileInfo struct	
 * Side Effects: none
 * Error Conditions: none
 * Resturn Value: int
 */



sizeSortAscending:
	
	set	offset,%o2
	ld	[%o2],%o5

	ld	[%o0+%o5],%o3
	ld	[%o1+%o5],%o4
	
	sub	%o3,%o4,%o0
	
	retl
	nop


