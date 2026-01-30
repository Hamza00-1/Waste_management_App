
# Source Layout

This folder contains the layered MVVM + repository scaffold. It is designed to be
integrated into the extracted Visual Studio/Qt solution after pulling the LFS
archive.
=======
# Source Layout (Proposed)

This folder outlines the intended structure for the application codebase.


```
src/
  presentation/
    views/
  viewmodel/
  domain/
    models/
    services/
  data/
    repositories/
    storage/
```


## What's Included

- **Domain models/services** for users and waste entries.
- **Repository interfaces** with file-backed implementations.
- **ViewModels** to coordinate UI state and domain logic.
- **Presentation stubs** that represent UI-facing entry points.

## Integration Tips

- Treat the presentation classes as placeholders for Qt Widgets or QML screens.
- Construct repositories and services in your app bootstrap, then inject them
  into ViewModels.
- Use a single shared storage location for user and waste data (e.g., an app
  data directory).

=======

## Conventions

- Presentation is UI-only; no file/database access.
- ViewModels manage UI state and call domain services.
- Domain models and services avoid UI and persistence concerns.
- Data repositories provide persistence through storage adapters.
