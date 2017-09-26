Easy GL2D

	


Relminator 2011 
	
Richard Eric M. Lope BSN RN

	
Http://Rel.Phatcode.Net


A very small, simple, yet very fast DS 2D rendering lib using the DS' 3D core.


Reasons to use Easy GL2D:

1. Library size is very small (less than 10 kb)
2. Very fast
3. Easy to maintain and refactor existing code
4. Abstracted interface
5. Code is easily portable to other platforms
6. Can combine 2D and 3D seamlessly
7. Almost unlimited palette usage in a single frame
8. Can handle non-power of 2 sprites
9. 3 types of translucency (2 via textures and 1 via polygon format)
10. Lots of sprite effects (colors, alpha, rotation, scaling, shearing, etc.)
11. Optimum VRAM use
12. Paletted(almost limitless) and high-color mode can be used together.


Limitations:

1. Emulators are slower in emulating the 3d hardware than the OAM.
2. glPutPixel, glLine and glBox only works on a real DS and No$GBA and not on deSmuMe.
3. You still have to learn how to use the sub OAM and sub BG since this lib is main engine
   only. You can use the video capture to render on both screens but that would limit your
   FPS and would use valuable VRAM.

 

Installation: 

1 . Copy the distributable/libnds folder to your devkitPro directory.
    or you can copy the /include and /lib folders under the /libnds directory of devkitPro.
    ie.
	*Assuming you installed devkitPro in c:/devkitPro/
	
	c:/devkitPro/libnds/include/gl2d.h   
	c:/devkitPro/libnds/lib/libgl2d.a

2.  Edit this line in your makefile and add gl2d before libnds
    ie.
	LIBS	:= -lnds9


	to


	LIBS	:= -lgl2d -lnds9

   


4. Add #include <gl2d.h> to your source. 

5. Done! You can now use gl2d


Note:

Easy GL2D DS works perfectly on a Real DS.

However, if you are running this on an emulator...
No$GBA - works perfectly.
deSmuMe - use the soft rasterizer instead of OpenGL

Notice:
	
	* glColorTable() has been deprecated since the release of libnds 1.5.0.
	  Because of the it, stencil effects are not possible w/o some hacks so 
	  I just disabled it altogether.  However, rendering sprites in any palette
	  is a lot easier now since palettes are automatically managed by libnds. 

	* You also need to tell libnds what VRAM bank you want allocate for
	  texture palettes. See the example files.

Update 04/02/2011
	* Added gl[Get/Set]ActiveTexture() for Stencil FX (See Sprites example)

	* Added uoff and voff to glSpriteOnQuad for more FX
	* 
Changed Sprite Examples

Update 02/17/2011
	* Code overhaul for libnds 1.5.0 compatibility
	* Added 2 parameters to glSpriteLoad() and glSpriteLoad()
	* Fixed the examples to reflect changes
	* Doxygen generated reference
	* Bug fixes(reported by Enay, Mhaun, Alex Sinclair, etc)


Update 11/25/2010

	* Documentation and user's guide done.
	* Added a dual_screen example.
	* Updated the sprites example

Update 11/23/2010

	* Fixed a bug where drawing primitives messed up the sprite colors. (missing currenttexture = 0 call)



