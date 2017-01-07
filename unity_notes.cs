Terminology
----/------
Rigidbody -	a component, that allows an object to be affected by physics.
	mass: affects how an object responces to collisions with other objects
	drag: how fast an object loses it''s velocity (stops)
	angular drag: how fast object stops rotating
	isKinematic: whether or not a rigigbody will react to physics (if isKinematic is active, an object reactions and behavior can be controlled by a script)
	iterpolate: used to smooth an object''s movement

MonoBehaviour is the base class/ every script derives from
Using Javascript every script automatically derives from MonoBehaviour. When using C# or Boo you have to explicitly derive from MonoBehaviour


Useful properties, methods, etc.
--------------/----------------
Time#deltaTime - the time in seconds it took to complete the last frame (Read Only)

#Destory: marks an object to be destroyed at the end of the frame

GameObject#FindWithTag (string : tag) - looks for a first GameObject in a scene, that is tagged as *tag*
	fairly inefficient


Prefabs
---/---
Prefab asset type that allows you to store a GameObject object complete with components and properties. The prefab acts as a template from which you can create new object instances in the scene. Any edits made to a prefab asset are immediately reflected in all instances produced from it but you can also override components and settings for each instance individually.

By draging an item from the Hierarchy to the Project view, one creates a new Prefab asset

Objects created as prefab instances will be shown in the hierarchy view in blue text (normal objects are shown in black text


Colliders
----/----
Dynamic and static Colliders

Static colliders - non-moving parts of your scene (the walls, the floor, etc.)

Static geometry is not effected by the collison, as opposed to dynamic one

Unity calculates all the volumes of all the static colliders and stores the data in cache. When a static collider is moved, Unity recalculates all the static colliders again, which takes resources

Any game object with a collider and a rigid body component is a dynamic object

Any GameObject with collider attached, but no rigid body is considered static


Properties
----/-----
If isKinematic is enabled, Forces, collisions or joints will not affect the rigidbody anymore. The rigidbody will be under full control of animation or script control by changing transform.position


User Interface (UI)
------/------------
Scripting
	using UnityEngine.UI
	Set up canvas after text creation

Editor
	The Canvas is the area that all UI elements should be inside. The Canvas is a Game Object with a Canvas component on it, and all UI elements must be children of such a Canvas

	Text element
		pivot (x,y) - a spot inside text element square, for which to count the position
		
RectTransform
	Transform for UI elements
	Pivot - for rotations and scale
	Anchors - for different displacement schemes 

Ordering UI elements (visibility sort)
	Reverse to PhotoShop (bottom -> on the surface)

Shaders
---/---
Diffuse = mat painting

Specular = glossy paint/shining plastic

Unlit/Texture = just as an original image

Particles/Additive: blacks are 0 and whites are 255; for bright objects (such as laser bolts)

Mobile/.:
	eats less resources
	may give a lower quality output
	may also leave out some of the full shader features
	
"Standard Shader"
	'Render modes':
		* Opaque - for most normal objects
		* Cutout - smth about cutting out parts of the model using alpha
		* Fade - to be able to fade out the object
		* Transparent - for objects such as glass, etc.
	'Main maps' - define how the object looks:
		* Albedo
			A color or a texture can be used
		* Metalic || Specular (for different PBS approaches ? TODO: google)
			A texture or a slider can be used.
				When texture is used, the R component sets the Metalic-ness / Specular-ness (BG are ignored) and the A channel sets the Smoothness (however for the Metalness all the RGB channels can be filled to make texture look grayscale).
				When a color is used, push the color to white to make a 'surface into mirror'
			- Smoothness - the more smooth the surface is, the less diffuse (more specular, mirror-like) it behaves.
		* Emmision
			Color option becomes visible when the value >0.
			Emmision texture can be applied (white - emissive spots). Textures can be one colored or with multiple colors to simulate e.g. computer screen.
	'Secondary maps'
		Details on top the Main maps.

Unity methods
-----/-------
Update:
	- called once per frame for every script, that uses it
	- used for regural updates:
		*moving non-physics objects
		*simple timers
		*receiving input
	- update time intervals vary

FixedUpdate:
	- called every just BEFORE each Physics Step (on a regural timeline)
	- used to adjust physics objects (rigid bodies, for example)
	- for example when adding a force to a rigidbody, you have to apply the force every fixed frame inside FixedUpdate instead of every frame inside Update


Player movements
------/--------
Ways to move an object:
	//physics friendly
	Vector3 movement = new Vector3 (moveHorizontal, 0.0f, moveVertical);
	rb.AddForce (movement * speed);

	//phisics foely
	rigidbody.velocity =  new Vector3(moveHorizontal * speed, 0.0f, moveVertical * speed);

Restrict free moving area:
	Use Mathf.Clamp to clamp position values in a desired range:
		rb.position = new Vector3
			(
				Mathf.Clamp (rb.position.x, boundary.xMin, boundary.xMax),
				0.0f,
				Mathf.Clamp (rb.position.z, boundary.zMin, boundary.zMax)
			);

Make camera follow with a lag:
	use Vectro3.Lerp(...) to linearly interpolate between the Camera position and Player position with interpolation factor 't'


Coroutines
-----/----
Coroutine functions return IEnumerator type

Return statement is: yield return ...

To start a Coroutine use #StartCoroutine function


Audio
--/--
3D Sound - a feature to compare a sound''s source positioning with the position of an active audio listener to calculate the appropriate volume and stuff

Audio Editing
	Attenuation - sound level
	Snapshot - a state of AudioMixer (essentially, a preset)
		- example of snapshots: paused (music volume preset when paused), unpaused
		- change AudioMixer's properties when Snapshot is selected to affect this Snapshot
		- use AudioMixerSnapshot#transitionTo(float numSeconds) to tansition to subject Snapshot in numSeconds
	

	Workflow:
		1. In Project create AudioMixer then Window -> AudioMixer to open the editor window
		2. Create groups to group soundfx (Music, Sfx, etc.)
			- to link AudioMixer to Group in another AudioMixed: drag one onto another -> choose the group
		3. "Add.." to Add Effects (see below)
		4. RMB -> Expose ".." to script, to make any of the Inspector parameters acceseble through scripting
			- use AudioMixer#SetFloat to change the value in the script
			- check Exposed parameters in right corner of AudioMixer Window
	
	Effects
		Send - sends output of one group to another
		Duck Volume - cut volume, when sound data from other Group's Send is above Threshold
		Lowpass Simple - attenuate (cut) the sound, when above threshold


MonoDevelop
----/------
Shortcuts
	control+Space - quick hints
	control+I - reformat code


Techniques
---/------
Find an instance of a GameObject
	use GameObject#FindWithTag to find the first GameObject with a given tag in a scene
	to access a component (for example, a script), use gameObject#GetComponent <class_that_extends_MonoBehavior | name_of_component>


Animations
---/------
Animator Controller Workflow:
	1. Create Animator Controller in Project and attach as "Animator" Component to the object.
	2. Select Window -> Animator: a state machine to controll animations.
	3. Drag the animations from project into Animator.
	// Orange: Layer Default State.
	4. "Make Transition"s between the states based on Parameters.
	//Trigger - bool, which flips back to false.
	TODO: check "Has Exit Time" (causes animations not to play)
	5. Get Animator component in script and set it's parameters to manipulate animations.
	
Animation Workflow:
	1. Window -> Animation
	2. Select the to-be animated GameObject in Hierarchy -> Animation Window -> Create animation
	3. Add Property for each property you wanna animate
// Red Play game buttons means you in Record Mode (everything you change gonna be key-framed)
// Looping can be turned of in Inspector with Animation selected in Project?

Events during the animation
	Select your model with animation in Project -> Events -> Add Event -> Choose the name of the function to call
	
GameObjects for animation
	AnimatiorOverrideController - allows to use an existing controller, but spoof animations for the new ones (good for similar enemies, for example).
		Workflow:
		1. Create -> Animator Override Controller.
		2. Choose the base Animator Controller and the spoof the animations.
		3. Don''t forget to the Animator Override controller to Animator.


Raycasting
-----/----
1. Create a ray (e.g. from Camera.main)
2. Physics.Raycast(..) (e.g. into a certain LayerMask with a certain ray length)
(optional) 3. Create vector from Player to Intersection, convert to Quaternion.LookRotation(..) to rotate player in a direction of intersection.
										      

2D
-/-
Sprite Renderer -> Sorting Layers
	Used to define Rendering Sequence (what goes on top what, i.e.: Floor, Player, Items, etc)
