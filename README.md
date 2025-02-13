# Maginengine Audio Engine 2.0

## Introduction
<br>
This repository is a revised version of the Maginengine Audio Engine 1.0.
---
The Project started as an honours project which, after the first half of the 
year, received a complete overhaul. Main reasons for this were that the engine 
structure became incredibly convoluted and tightly coupled. <br>
After a thorough re-evaluation, I made the decision to redesign the engine.
By considering various design patterns, the engine is now loosely coupled at most
and easy to expand on.
---
## Keywords

- **Engine:** runs entire application
- **EventManager:** initialises engine hierarchy and “**PlaybackDevice**”. Handles multiple “**Events**”
- **PlaybackDevice:** contains “**audioCallback**” function
- **Event:** A container that handles multiple “**Tracks**”. Contains transport controls to trigger all 
Tracks at once
- **Track:** Is assigned an “**Asset**” and handles processing of audio data (i.e. volume, pan etc.). 
Contains transport controls for assigned Asset
- **Asset:** Loads an audio file and will be handled by a “**ResourceManager**” 
- **Voice:** Handles the processing of audio data to the “**PlaybackDevice**”
---
## Engine Structure

### Composite Pattern
I chose the composite pattern as it would be beneficial for setting up a hierarchy within the 
“**eventManager**” in which I am easily able to navigate through **composites** (events) and **leafs** (Tracks). 
This structure does not deviate too much from my original concept from engine 1.0. However, one big 
difference is that I am making use of an abstract base class interface that can be used for either 
composite or leaf. This base class provides opportunities to expand by simply adding more abstract 
functionality. 

### Object Pool Pattern
2 Object Pool patterns are in place to handle "**Real**" and "**Virtual**" Voices. When a **Track** is 
triggered to play their assigned **Asset**, a check will determine if the Track is able to assign
itself to a "**Real**" Voice. If the entire "**Real**" Voice pool is in use, then the Track will assign
itself to a "**Virtual**" Voice instead and keep track of the **play head**.







