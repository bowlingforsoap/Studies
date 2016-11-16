Dictionary
==========
An 'activity' is a single, focused thing that the user can do. Almost all activities interact with the user, so the Activity class takes care of creating a window for you in which you can place your UI with setContentView(View). While activities are often presented to the user as full-screen windows, they can also be used in other ways: as floating windows (via a theme with windowIsFloating set) or embedded inside of another activity (using ActivityGroup).




(res/)R(.java)
==============
Resource Objects
A 'resource object' is a unique integer name thats associated with an app resource, such as a bitmap, layout file, or string.
Every resource has a corresponding resource object defined in your projects gen/R.java file. You can use the object names in the R class /to refer to your resources, such as when you need to specify a string value for the android:hint attribute. You can also create arbitrary resource IDs that you associate with a view using the android:id attribute, which allows you to reference that view from other code.
The 'SDK tools generate the R.java' file each time you compile your app. You should never modify this file by hand.

'References to resources are always scoped by the resource type' (such as id or string), so using the same name does not cause collisions.

String Resources
----------------
By default, your Android project includes a string resource file at res/values/strings.xml

Instead of using a hard-coded string as the value, the "@string/edit_message" value refers to a string resource defined in a separate file. Because this refers to a concrete resource (not just an identifier), it does not need the plus sign.

For more information about using string resources to localize your app for other languages, see the 'Supporting Different Devices' class.


Android manifest
================
The manifest file describes the fundamental characteristics of the app and defines each of its components.


Application context
===================


Activity
========
The Activity class /is a subclass /of Context

All subclasses of Activity must implement the onCreate() method. This method is where the activity receives the intent with the message, then renders the message. Also, the onCreate() method must define the activity layout with the setContentView() method. This is where the activity performs the initial setup of the activity components.

XML
---
The at sign (@) is required when youre referring to any resource object from XML. It is followed by the resource type (id in this case), a slash, then the resource name (edit_message).

For more information, read the guide to Providing Resources.
The plus sign (+) before the resource type is needed only when youre defining a resource ID for the first time. When you compile the app, the SDK tools use the ID name to create a new_ resource ID in your projects gen/R.java file that refers to the EditText element. With the resource ID declared once this way, other references to the ID do not need the plus sign. Using the plus sign is necessary only when specifying a new_ resource ID and not needed for concrete resources such as strings or layouts. See the sidebox for more information about resource objects


Intent
======
An Intent is an object that provides runtime binding between separate components (such as two activities). The Intent represents an app’s "intent to do something." You can use intents for a wide variety of tasks, but most often they’re used to start another activity. For more information, see Intents and Intent Filters.

Example:
Intent intent = new Intent(this, DisplayMessageActivity.class); //this is used because the code is inside an Activity class, which is a subclass of Context

An Intent can carry data types as key-value pairs called extras. The putExtra() method takes the key name in the first parameter and the value in the second parameter.
It's generally a good practice to define keys for intent extras using your app's package name as a prefix. This ensures the keys are unique, in case your app interacts with other apps.

All subclasses of Activity must implement the onCreate() method. 'This method is where the activity receives the intent with the message', then renders the message.


Layout
======
The graphical user interface /for an Android app is built using a hierarchy of View and ViewGroup objects. View objects are usually UI widgets such as buttons or text fields. ViewGroup objects are invisible view containers that define how the child views are laid out, such as in a grid or a vertical list.

Layouts are subclasses of the ViewGroup.

Linear Layout
-------------
To fill the unused screen width with the text field, do this inside a LinearLayout with the weight property, which you can specify using the android:layout_weight attribute.

The weight value is a number that specifies the amount of remaining space each view should consume, relative to the amount consumed by sibling views. This works kind of like the amount of ingredients in a drink recipe: "2 parts soda, 1 part syrup" means two-thirds of the drink is soda. For example, if you give one view a weight of 2 and another one a weight of 1, the sum is 3, so the first view fills 2/3 of the remaining space and the second view fills the rest. If you add a third view and give it a weight of 1, then the first view (with weight of 2) now gets 1/2 the remaining space, while the remaining two each get 1/4.

The default weight for all views is 0, so if you specify any weight value greater than 0 to only one view, then that view fills whatever space remains after all views are given the space they require.

To improve the !!!'layout efficiency'!!! when you specify the weight, you should change the width of the EditText to be zero (0dp - 0 density-independent pixels). Setting the width to zero improves layout performance because using "wrap_content" as the width requires the system to calculate a width that is ultimately irrelevant because the weight value requires another width calculation to fill the remaining space.


Gradle
======
The manifest file describes the fundamental characteristics of the app and defines each of its components.
build.gradle file for the module, in this case the app or application module.


raw/
====
Arbitrary files to save in their raw form. To open these resources with a raw InputStream, call Resources.openRawResource() with the resource ID, which is R.raw.filename.

However, if you need access to original file names and file hierarchy, you might consider saving some resources in the assets/ directory (instead of res/raw/). Files in assets/ are not given a resource ID, so you can read them only using AssetManager.

File-based resource names must contain only lowercase a-z, 0-9, or underscore


=============
CARDBOARD API
=============
CardboardView will only render when the activity is in fullscreen mode


=========
OPENGL ES
=========
GLSurfaceView - provides a dedicated surface for OpenGL rendering
  The essential code for a GLSurfaceView is minimal, so for a quick implementation, it is common to just create an inner class /in the activity that uses it.

  One other optional addition to your GLSurfaceView implementation is to set the render mode to only draw the view when there is a change to your drawing data using the GLSurfaceView.RENDERMODE_WHEN_DIRTY setting
    setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
    This setting prevents the GLSurfaceView frame from being redrawn until you call requestRender()

  By default, OpenGL ES assumes a coordinate system where [0,0,0] (X,Y,Z) specifies the center of the GLSurfaceView frame, [1,1,0] is the top right corner of the frame and [-1,-1,0] is bottom left corner of the frame.

Renderer - responsible for the actual OpenGL rendering. The Renderer class /implements the key event functions—onDrawFrame, onSurfaceChanged, and onSurfaceCreated—in the rendering loop.
  Unless the structure (the original coordinates) of the shapes you use in your program change during the course of execution, you should initialize them in the onSurfaceCreated() method of your renderer for memory and processing efficiency

  Since drawing options can vary by shape, it's a good idea to have your shape classes contain their own drawing logic.
  

Shaders
=======
'Compiling' OpenGL ES 'shaders and linking programs is expensive' in terms of CPU cycles and processing time, so you should avoid doing this more than once.

===
NDK
===
ABIs can be set in 3 places:
  1. Gradle (android.defaultConfig.ndk.abiFilters);
  2. Application.mk (APP_ABI);
  3. Android.mk (TARGET_ARCH_ABI).

JNI
---
Steps:
1. Set android.useDeprecatedNdk = true in gradle.properties (http://stackoverflow.com/questions/31979965/after-updating-android-studio-to-version-1-3-0-i-am-getting-ndk-integration-is)
2. Create a class containing JNI public static native void function names
3. Build the project
4. Navigate to the folder containing the .class files and use javah (javah full.qualified.class.Name) to generate a corresponding native interface header file with functions with correct (more like fucked up) names (as specified here:
http://stackoverflow.com/questions/19365853/javah-error-cannot-find-class-file
[if the one ontop doesn't help: http://stackoverflow.com/questions/986262/javah-error-while-using-it-in-jni])
5. For build-ndk to work, use APP_PLATFORM := here_goes_the_sdk_version?/*not sure*/ (23 worked fine)
6. Add:
android.sourceSets {
    main {
        jni.srcDirs = [] // tells gradle not to build NDK on it's own
        jniLibs.srcDir 'src/main/libs' // specifies the directory with the compiled ndk code
    }
}
to the module's build.gradle.

