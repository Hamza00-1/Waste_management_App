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

## Conventions

- Presentation is UI-only; no file/database access.
- ViewModels manage UI state and call domain services.
- Domain models and services avoid UI and persistence concerns.
- Data repositories provide persistence through storage adapters.
