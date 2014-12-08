/*
 * Filename: displayGroupName.s
 * Author: jinye xu
 * Date: Nov. 29
 * Source of Help: Piazza, stackOverflow
 */

	.global displayGroupName
	.section	".data"
str1:
	.asciz	"%-8s "
str2:
	.asciz	"%-8ld "
	
	.section	".text"
/*
 * Function name: displayGroupName()
 * Funciton prototype: void displayGroupName( const gid_t gid); 
 * Description: prints out group's name or gid 
 * Parameters: arg 1 is a git_t constant passed in 
 * Side Effects: none
 * Error Conditions: check for null object
 * Resturn Value: void
 */


displayGroupName:
	save	%sp,-96,%sp

	mov	%i0,%o0

	call	getgrgid
	nop
	
	mov	%o0,%l0			!holds the pointer

	cmp	%l0,%g0
	be	number
	nop

	set	str1,%o0
	ld	[%l0],%o1
	call	printf
	nop

	ret
	restore
number:
	set	str2,%o0
	ld	[%l0],%o1
	call 	printf
	nop

	ret
	restore
