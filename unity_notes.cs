Terminology
----/------

Rigidbody -	a component, that allows an object to be affected by physics.
	mass: affects how an object responces to collisions with other objects
	drag: how fast an object loses it''s velocity (stops)
	angular drag: how fast object stops rotating
	isKinematic: whether or not a rigigbody will react to physics (if isKinematic is active, an object reactions and behavior can be controlled by a script)
	iterpolate: used to smooth an object''s movement


Useful properties, methods, etc.
--------------/----------------

Time.deltaTime - the time in seconds it took to complete the last frame (Read Only)

Destory: marks an object to be destroyed at the end of the frame


Prefabs
---/---

Prefab asset type that allows you to store a GameObject object complete with components and properties. The prefab acts as a template from which you can create new object instances in the scene. Any edits made to a prefab asset are immediately reflected in all instances produced from it but you can also override components and settings for each instance individually.
 
Draging an item from the Hierarchy to the Project view, one create a new Prefab asset

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

using UnityEngine.UI


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
	Use Mathf.Clamp to clamp position values in a desider range:
		rb.position = new Vector3
			(
				Mathf.Clamp (rb.position.x, boundary.xMin, boundary.xMax),
				0.0f,
				Mathf.Clamp (rb.position.z, boundary.zMin, boundary.zMax)
			);