Dictionary
----/----
GLEW: The OpenGL Extension Wrangler Library

A Framebuffer is a collection of buffers that can be used as the destination for rendering

GLU - OpenGL Utility Library


Working Sequence
------/---------
1. setup window management with GLFW (OpenGL doesn't contain code for window handling)
- glfwInit() (check validity)
- create window (check validity)
- make the window current context
- set the main loop with glfwWindowShouldClose and swap buffers, poll events there
- deinitialize window and glfw when done
- (optionally) set a callback on frame buffer size change and change viewport and projection matrix there
2. OpenGL stuff: programm the rendering loop
- glMatrix(GL_MODEL_VIEW_MATRIX)
- -||- (GL_PROJECTION)
- glColor..
- *draw*

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


Textures
---/----
We get the shader locations for the texture data and texture coordinates. In OpenGL, textures need to be bound to texture units before they can be used in rendering. A texture unit is what reads in the texture and actually passes it through the shader so it can be displayed on the screen. Different graphics chips have a different number of texture units, so you’ll need to check if additional texture units exist before using them.
First, we tell OpenGL that we want to set the active texture unit to the first unit, texture unit 0. Our call to glBindTexture() will then automatically bind the texture to the first texture unit. Finally, we tell OpenGL that we want to bind the first texture unit to the mTextureUniformHandle, which refers to “u_Texture” in the fragment shader.
  // Set the active texture unit to texture unit 0.
  GLES20.glActiveTexture(GLES20.GL_TEXTURE0);
  // Bind the texture to this unit.
  GLES20.glBindTexture(GLES20.GL_TEXTURE_2D, mTextureDataHandle);
  // Tell the texture uniform sampler to use this texture in the shader by binding to texture unit 0.
  GLES20.glUniform1i(mTextureUniformHandle, 0);

In short:
1. Set the active texture unit.
2. Bind a texture to this unit.
3. Assign this unit to a texture uniform in the fragment shader.
