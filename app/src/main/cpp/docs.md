# App components

```mermaid
---
title: App components
---
classDiagram
  Shared <-- Game : use
  Shared <-- AppOrLib : use
  Game <-- AppOrLib : use
  Platform <-- AppOrLib : use
  Platform <-- Game : use
  Shared <-- Platform : use
```
