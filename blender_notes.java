Shortcuts
---/-----
  H - hide an object
  Alt + H - unhide hidden objects
  Alt + M - merge
  Shift + C - cursor to the center
  Shift + S - a Snap Menu to snap cursor to the selected stuff or vice versa
  ? - remove duplicates (vertecies, faces, etc.)

Cycles
---/--
  Bump mapping
    Called 'Displacement' in cycles

  'Textures'
    Add Material -> Add Shaders -> Connect a texture (Image Texture node) to a Color circle in a shader

  'Lights':
    * Lamps
      - are kinda bad (better sse real objects (such as a Plane) and make it emit)
      - larger lights == softer shadows
      - Sun Lamp:
        # distance doesn''t matter
        # rotation does
    * The World has a default Gray material assigned to it

  'Shaders':
    * Glossy: 0 - a mirror
            1 ~ a diffuse
    * Mix Shader: combines a couple of shaders within one material
    * Subsurface Scattering
        an essential part of any skin shader
        the node becomes very noisy, if it''s not happy
        can be used to create a rubbery diffuse surfaced toy, for example
        falloff:
          Cubic - a much more sudden & short
            Sharpness: the amount of details (topology) to show on the model
              can be combined with Texture Blur to achieve the needed smoothness
          Gaussian - a much smoother & stretched-out falloff
        Scale: a multiplier for the following values
          Radius: RGB values ratios for components to be scattered
            the smaller the radius, the more the light stays in the model
          Texture Blur: how much to blur the texture ;)
            can be combined with Sharpness to achieve the needed smoothness
      * Skin shader
          3 layers: meat, fatty layer & the skin
          Glossy part reflects slightly blueish color (? have to check)
      * Toon shader
          "to make it work in Cycles, you'll have to turn a lot of stuff off"
          lower the Lamp size to get Sharper Shadows



  Render -> 'Sampling':
    500 - 2000 samples to get a normal end result
    0 - unlimited

  Render -> 'Render'
    Display: the output of the resulting image (into a 'New Window', 'Image Editor', 'Full Screen', etc.)

  Render -> 'Dimensions'
    the size 'resolution' of the end image

  Node Editor
    Neat actions
      (with the node selected) Node -> Detach Node:
        detaches the node leaving the outside connection (excludes the node, w/o breaking the link)

    Inputs and outputs are color coded:
      Green - a Shader
      Gray - a black and white image
      Purple - a math vector or a normal map
      Yellow - a colored image

    Image Texture node
      Input
        Vector - the coordinate system for the texture

    Texture Coordinate node
      A way to specify texture mapping on a mesh

    Mapping node
      Let''s one control the mapping of smth (e.g. texture) onto smth (e.g. plane)

    MixRgb
      The same as color mixing in Photoshop (Multiply, Overlay, etc.)

Camera
--/--
  'Navigation'
    N -> View -> Lock Camera to View
    ("locks the camera", so it can be conveniently rotated with a middle mouse button;
    "rotation" will happen "around" an "active [selected] object")


UVs
-/-
  Process: Mark seams (T -> Shading/UVs -> Mark Seam) -> U -> Unwrap


Freestyle
----/----
  Selection by toggles (toggle in or out to chose, what affects the final image):
    "Visibility" - render every single edge type
      Visible
      Hidden - detects lines on the geometry, that''s being occluded
      QI Range - render both Visible and Hidden with some setting
      to render Both Visible & Invisible disable the 'Visibility' check
    "Edge Types"
      Inclusive - render the selected edge types
      Exclusice - everything besides the selected edge types
      Types:
        'Suggestive Contours' - subtle chenges in the geometry (draws some lines which would form the contour of the mesh if the viewport was shifted)
          can be controlled through Render Layers -> Freestyle -> Advanced Options
        'Ridge & Valley' - shows peaks and drops in the geometry (depends on your Sphere Radius viewmap settings)
        'Crease' - shows only edges whose adjacent faces form an angle greater than the defined viewmap’s Crease Angle
        'Material Boundary' -draws lines where two materials meet on the same object. Must be activated in the viewmap settings.
        'Edge Mark' - draw only marked edges
          in the Edit Mode tap Ctrl + E -> Mark Freestyle Edge
    "Face Marks"
      similar to 'Edge Mark': Crtl + F -> Mark Freestyle Edge
    "Group"
      define a group of objects, which is affected by the freestyle setting
    "Image Border"
      saves computations by leaving out the objects, which are out of the frame
      may cause artifacts in animations, when object is first invisible, but then comes into frame

  Freestyle Line Style tabs (all affect the final image):
    "Strokes"
      Chaning - eliminates gaps between the strokes
      Splitting - splitting rules for the lines
        D; G; D; G; D; G; - dash/gap patern for splitting
      Selection - which lines to show
        Min 2D Length, Max 2D Lenght - min and max length of lines to show
      Caps - different types of the dash ends (Butt, Round, Square)
      Dashed Line - specify three pairs of dash and gap lengths in the unit of pixels (can be combined with splitting patter to achieve interesting results)
      Geometry - slick modifiers

Toon Shading
-----/------
  an unrealisticly high contrast between the parts of the geometry that are in light and those in shadow

  Smooth:
    lower values make transitions between shadow and light areas sharper


UV/Image Editor
-----/---------
  Alt + J to switch between the slots


Animation
----/----
  to create Key Frames, press the recording button - key frames will be automatically inserted on the change in postions & etc. (the Key Frame is inserted for LocRotScale)

  I -> choose the Type Of Frame to insert (to Manually Insert a Frame)


  Dope Sheet editor
    a Summary of the Animation
    Scaling of the keayframes is done relative to the  Play Head (green line with the number of the frame)

  Graph Editor
    ssed to Alter the Interpolation between the key frames
    Normalize checkbox to scale everything (all the curves) down to the same size (basically, normalize ;)
    choose Interpolation Type: T -> Linear | Constant | Bezier Curve | etc.

  Rendering a Movie Clip
    better render as an Image Sequence to be able to continue where you left of and not loose almost any data
    Render -> Output: to chose where to save the resulting images

    use Video Sequence Editor
    use H.264 codec (image compression algorithm)
    Bitrate: 2000 - 6000 (but have to check)
      the smaller the lighter the video will be


Rigging & Bones
-----/---------
  Armature -> X-Ray: checkbox to see bones through meshes
  W: Specials Menu
    subdivide - to subdiv the bone
  Ctrl + N: Recalculate the Bone Roll

  Forward & Inverse Kinematics
  ----------------------------
    forward - whatever you select everything in-front of it will move with it


  Pose Mode
  ---------
    Alt + S / G / R: resets Scaling, Transition and Rotations of the bones

    Weight Paint
      blue: not controlled by the chosen bone
      green: 50%
      T -> choose brushes
      Face & Vertex Selection mode to restrict the regions affected by the painting
