/*
 * Filename: sizeSortAscending.s
 * Author: jinye xu
 * Description: sorting the file from small size to big size
 * Date: Nov. 29
 * Source of Help: Piazza, stackOverflow
 */

	.global nameSortAscending

	.section	".text"
/*
 * Function name: nameSortAscending()
 * Funciton prototype: int nameSortAscending( const void *p1, const 
 *                                            void *p2);
 * Description : Compares name(characters) of two files
 * Parameters: arg 1: const void *p1 is a pointer to the first fileInfo struct
 * 	       arg 2: const void *p2 is a pointer to the second fileInfo struct
 *
 * Side Effects: none
 * Error Conditions: none
 * Resturn Value: int
 */

nameSortAscending:
	
	save	%sp,-96,%sp

	mov	%i0,%o0
	mov	%i1,%o1

	call	strcmp
	nop

	mov 	%o0,%i0

	ret
	restore
