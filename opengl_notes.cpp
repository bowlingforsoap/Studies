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
