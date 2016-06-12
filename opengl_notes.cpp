Dictionary
----/----
GLEW: The OpenGL Extension Wrangler Library

A Framebuffer is a collection of buffers that can be used as the destination for rendering

GLU - OpenGL Utility Library

Concepts
----/---
  OpenGL Implements a Client-Server Model
  OpenGL Commands Can Be Executed Asynchronously
  OpenGL applicationsshould be designed to reduce the frequency of client-server
synchronizations
  OpenGL guarantees that commands are executed in the order they are received by OpenGL.
  When an application calls an OpenGL function, the 'OpenGL client copies any data provided' in the parameters
before returning control to the application. For example, if a parameter points at an array of vertex data stored
in application memory, OpenGL must copy that data before returning. Therefore, an application is free to
change memory it owns regardless of calls it makes to OpenGL.
The 'data' that the client copies 'is often reformatted before it is transmitted to the server'. Copying, modifying,
and transmitting parameters to the server adds overhead to calling OpenGL. 'Applications should be designed
to minimize copy overhead'.

  'Primitive' - the fundamental unit of rendering in OpenGL
    OpenGL supports many types of 'primitives', but the 'three basic' ones are 'pointes, lines and triangles'

  Graphics pipeline parts:
    1. front-end (vector; vertex)
    2. back-end (discrete; pixel)

'Orthographic projection' - involves no persperctive /correction (the object on screen will remain the same size regardless of its distance from the camera)


Functions
----/----
The 'glBegin' and 'glEnd' functions delimit the list of vertices corresponding to a desired /primitive (e.g. GL_POINTS). The glBegin function accepts a set of symbolic constants that represent different drawing methods, including GL_POINTS, GL_LINES, and GL_TRIANGLES.

We can 'set the diameter of each point (in pixels)' with the glPointSize function. By default, a point has a diameter of 1 without anti-aliasing (a method to smooth sampling artifacts) enabled.

'glOrtho'
  set up an orthographic projection

  'glOrtho' function takes these 'parameters': the coordinates of the vertical clipping plane, the coordinates of the horizontal clipping plane, and the distance of the nearer and farther depth clipping planes. These parameters determine the projection matrix
