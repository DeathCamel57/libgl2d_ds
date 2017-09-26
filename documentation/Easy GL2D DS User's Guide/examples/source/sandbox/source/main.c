/******************************************************************************
*******************************************************************************
	Easy GL2D 
	Sandbox example
	Shows a some primitive capabilities of easy GL2D
	
	Relminator (Richard Eric M. Lope BSN RN)
	Http://Rel.Phatcode.Net
	
	
*******************************************************************************
******************************************************************************/ 

#include <nds.h>
#include <stdio.h>
#include <gl2d.h>

// Binary Radian PI cosLerp() and sinLerp()
// Expects to be used
#define BRAD_PI (1 << 14)


int main( void )
{
    
	// Set it to my favorite mode (Any mode that supports 3D should work)
    videoSetMode( MODE_5_3D );
   
     
    // Initialize GL2D
    glScreen2D();
   

    while( 1 )
    {

        // set up GL2D for 2d mode
        glBegin2D();

		
        // call Easy GL2D's 2D rendering functions here

		// Draw some primitives
		
		// fill the whole screen with a gradient box
		glBoxFilledGradient( 0, 0, 255, 191,
							 RGB15(  0, 31,  0 ),
							 RGB15( 31,  0,  0 ),
							 RGB15(  0,  0, 31 ),
							 RGB15( 31, 31, 31 )
						   );
		
		// draw a black box on the right
		glBoxFilled( 200, 10,
					 250, 180,
					 RGB15(0,0,0)
				    );
		
		// draw a border around the black box
		glBox( 200, 10,
			   250, 180,
			   RGB15(0,31,0)
		     );
		
		
		// draw a triangle
		glTriangle(  20, 100,
					200,  30,
					 60,  40,
					RGB15(31,0,31)
				   );
	
		// Draw some lines from the center
		// with a radius of 20
		int i;
		int radius = 60;
		for( i = 0; i < BRAD_PI * 2; i += 1024 )
		{
			int x = cosLerp(i) * radius;
			int y = sinLerp(i) * radius;
			// since sinLerp and cosLerp returns
			// a 20.12 fixed point value
			// we need to convert the results back 
			// to standard integers
			x = f32toint(x);  // same as x >> 12
			y = f32toint(y);
			
			// draw the lines radiating from the center
			glLine( 128, 96, 128 + x, 96 + y, RGB15(20,15,31) );
 
 
		}
		// draw a gradient triangle in
		// translucent mode with
		// Poly ID 1
		// POLY_ALPHA(16) controls how translucent
		// the current polygon is. 8/31
		glPolyFmt(POLY_ALPHA(8) | POLY_CULL_NONE | POLY_ID(1));
		glTriangleFilledGradient(  30, 10,
								  200, 80,
								  60, 140,
								  RGB15(31,0,0),
								  RGB15(0,31,31),
								  RGB15(31,0,31)
								);
		
        // end 2D rendering mode
        glEnd2D();
   
        glFlush(0);                    
        swiWaitForVBlank();
   
    }
   
   
}

