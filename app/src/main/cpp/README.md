# App components

```mermaid
---
title: App components
---
classDiagram
direction BT
  StringsFormatter <-- Shared
  EventBus <-- Shared
  Platform <-- Shared
  Shared <-- LinuxPlatform
  Shared <-- Game
  Shared <-- AndroidPlatform
  Game <-- LinuxApp
  Game <-- AndroidLib
  LinuxPlatform <-- LinuxApp
  AndroidPlatform <-- AndroidLib
```