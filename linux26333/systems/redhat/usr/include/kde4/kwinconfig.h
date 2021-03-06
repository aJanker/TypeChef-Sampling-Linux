/*

 This file includes config #define's for KWin's libraries
 that are installed. Installed files and files using them
 should be using these instead of their own.

*/

#ifndef KWINCONFIG_H
#define KWINCONFIG_H

#if 1
#define KWIN_HAVE_OPENGL 1
#else
#undef KWIN_HAVE_OPENGL
#endif

/*
 
 These should be primarily used to detect what kind of compositing
 support is available.

*/

/* KWIN_HAVE_COMPOSITING - whether any compositing support is available */
#define KWIN_HAVE_COMPOSITING

/* KWIN_HAVE_OPENGL_COMPOSITING - whether OpenGL-based compositing support is available */
#define KWIN_HAVE_OPENGL_COMPOSITING

/* KWIN_HAVE_XRENDER_COMPOSITING - whether XRender-based compositing support is available */
#define KWIN_HAVE_XRENDER_COMPOSITING


#endif
