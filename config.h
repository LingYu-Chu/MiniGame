#define inw(reg)  (*((volatile unsigned int*) (reg)))
#define outw(reg, data) ((*((volatile unsigned int*) (reg)))=(unsigned int)(data))
/* lowlevel platform initialization if no bootcode.
 * Don't do this if there is bootcode on the platform, 
 * let bootcode do the work.*/
#define BURN		1 /* burn = 1, load = 0 */
//#define AG101         1 /* For AG101 board, else for XC5 board */
