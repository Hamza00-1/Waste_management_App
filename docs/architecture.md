# Architecture Overview

## Goals

- Keep UI logic minimal and testable by separating state from widgets.
- Encapsulate domain rules (auth, waste tracking) away from persistence.
- Allow future storage upgrades (file -> SQLite) without UI rewrites.

## High-level Structure (Layered MVVM + Repository)

```
Presentation (Qt Widgets/QML)
  -> ViewModels (state + commands)
    -> Domain (models + services)
      -> Data (repositories + storage adapters)
```

### Presentation Layer

- Views render data and emit signals only.
- No direct file or database access.

### ViewModel Layer

- Holds UI-facing state.
- Performs validation and coordinates service calls.
- Emits signals to update views.

### Domain Layer

- Pure business logic and validation rules.
- Service APIs used by ViewModels.

### Data Layer

- Repositories abstract persistence.
- Storage adapters implement file or DB access.

## Implemented Scaffold

The `src/` directory contains a working scaffold for this architecture:

- **Domain models** in `src/domain/models` (`User`, `WasteEntry`).
- **Domain services** in `src/domain/services` (`AuthService`, `WasteService`).
- **Repository interfaces** in `src/data/repositories`.
- **File-backed stores** in `src/data/storage`.
- **ViewModels** in `src/viewmodel`.
- **Presentation stubs** in `src/presentation/views`.

This scaffold is intentionally UI-framework-agnostic so it can be wired into Qt Widgets or QML screens.

## Suggested Module Map

| Module | Responsibility | Example Types |
| --- | --- | --- |
| presentation | UI widgets and pages | `LoginView`, `DashboardView` |
| viewmodel | View state + commands | `AuthViewModel`, `WasteViewModel` |
| domain/models | Entities + value objects | `User`, `WasteEntry` |
| domain/services | Business use cases | `AuthService`, `WasteService` |
| data/repositories | Data access | `UserRepository`, `WasteRepository` |
| data/storage | Persistence implementations | `FileUserStore`, `FileWasteStore` |

## Data Flow Example (Login)

1. `LoginView` emits `loginRequested`.
2. `AuthViewModel` validates input, calls `AuthService`.
3. `AuthService` calls `UserRepository`.
4. `UserRepository` reads from storage adapter.
5. Result propagates back to update UI state.

## Extension Points

- Swap file storage with SQLite by adding a new storage adapter.
- Add reporting features by introducing new domain services.
- Introduce tests by mocking repository interfaces in ViewModels.

## Integration Checklist

- Pull the LFS archive and extract the Visual Studio solution.
- Add the `src/` folders to the solution or move the scaffold into the extracted
  project tree.
- Wire UI widgets or QML screens to the ViewModels and domain services.
- Replace the file-backed repositories with a database-backed adapter when
  ready for multi-user or larger datasets.
