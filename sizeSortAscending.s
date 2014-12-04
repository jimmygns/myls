/*
 * Filename: sizeSortAscending.s
 * Author: jinye xu
 * Description: sorting the file from small size to big size
 * Date: Nov. 29
 * Source of Help: Piazza, stackOverflow
 */

	.global sizeSortAscending

	.section	".text"

sizeSortAscending:
	
	set	offset,%o2
	ld	[%o2],%o5

	ld	[%o0+%o5],%o3
	ld	[%o1+%o5],%o4
	
	sub	%o3,%o4,%o0
	
	retl
	nop


