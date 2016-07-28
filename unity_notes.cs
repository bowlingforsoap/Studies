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
Workflow:
	1. Create Animator Controller in Project and attach as "Animator" Component to the object.
	2. Window -> Animator: a state machine to controll animations.
	3. Drag the animations from project into Animator.
	// Orange: Layer Default State.
	4. "Make Transition"s between the states based on Parameters.
	//Trigger - bool, which flips back to false.
	TODO: check "Has Exit Time", causes animations not to play
	5. Get Animator component in script and set it's parameters to manipulate animations.

Events during the animation
	Select your model with animation in Project -> Events -> Add Event -> Choose the name of the function to call


Raycasting
-----/----
1. Create a ray (e.g. from Camera.main)
2. Physics.Raycast(..) (e.g. into a certain LayerMask with a certain ray length)
(optional) 3. Create vector from Player to Intersection, convert to Quaternion.LookRotation(..) to rotate player in a direction of intersection.
