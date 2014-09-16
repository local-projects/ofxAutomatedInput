ofxAutomatedInput
=====================================

Introduction
------------
ofxAutomatedInput is used to record and playback OF input events. This can be used for presentations, debugging, automation, etc. 

Based on [the addon by the same name](https://github.com/HeliosInteractive/ofxAutomatedInput) by Ben McChesney @ Helios Interactive.

Features
--------
* Supports Mouse, Key, and Touch input.
* Event types can be filtered on record and on playback.
* OF events triggered by default, meaning that your app's `mousePressed()`, `mouseReleased()`, `keyPressed()`, `keyReleased()`, etc methods will automatically get called.
* Option to turn off OF event triggering, in which case you can listen for events on the `ofxAutomatedInput` object directly.

Installation
------------
Just dropping the folder into `openFrameworks/addons/`.

Dependencies
------------
* ofxXmlSettings

Compatibility
------------
Tested with OF 0.8.4
