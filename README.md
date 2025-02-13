# Maginengine Audio Engine 2.0

## Introduction

This repository is a revised version of the Maginengine Audio Engine 1.0.
---
The Project started as an honours project which, after the first half of the 
year, received a complete overhaul. Main reasons for this were that the engine 
structure became increadibly convoluted and tightly coupled. <br>
After a thorough re-evaluation, I made the decision to redesign the engine.
By considering various design patterns, the engine is now loosly coupled at most
and easy to expand on.
---
## Keywords

- Engine: runs entire application
- EventManager: initialises engine hierarchy and “PlaybackDevice”. Handles multiple “Events”
- PlaybackDevice: contains “audioCallback” function
- Event: A container that handles multiple “Tracks”. Contains transport controls to trigger all Tracks at once
- Track: Is assigned an “Asset” and handles processing of audio data (i.e. volume, pan etc.). Contains transport controls for assigned Asset
- Asset: Loads an audio file and will be handled by a “ResourceManager” 
- Voice: Handles the processing of audio data to the “PlaybackDevice”
---
## Engine Structure

### Composite Pattern


### Object Pool Pattern








