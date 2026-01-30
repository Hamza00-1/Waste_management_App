# Gestion Déchet (Waste Management System)

[![Project Status](https://img.shields.io/badge/Status-Academic%20Project-blue.svg)](https://github.com/Hamza00-1/gestiondechet)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## 🌟 Project Overview

**Gestion Déchet** is a desktop application built with **C++** and the **Qt framework** to manage and track waste-related data. It emphasizes user authentication, a central dashboard, and dedicated waste entry workflows.

This repository now includes a **layered MVVM + repository** architecture scaffold under `src/` to separate UI, domain logic, and persistence. The original Visual Studio solution and Qt UI remain inside the Git LFS archive (`gestiondechet.zip`) until it is pulled and extracted.

### Academic Context

This project was developed as part of the curriculum at the **École d'Ingénierie Digitale et d'Intelligence Artificielle (EIDIA)** at the **Université Euro-Méditerranéenne de Fès (UEMF)**.

## ✨ Features

*   **Secure User Authentication:** Registration and login workflows.
*   **Local User Management:** Persistence via file-backed repositories (see `src/data`).
*   **Intuitive Dashboard:** Central navigation hub.
*   **Dedicated Waste Management Module:** Add and list waste entries.

## 🧱 Architecture Overview

The repository follows a layered MVVM architecture with a repository abstraction:

```
Presentation (Qt Widgets/QML)
  -> ViewModels (UI state + commands)
    -> Domain (models + services)
      -> Data (repositories + storage adapters)
```

See [`docs/architecture.md`](docs/architecture.md) for details and the `src/` scaffold for concrete interfaces and file-backed adapters.

## 🛠️ Technology Stack

| Component | Technology | Purpose |
| :--- | :--- | :--- |
| **Language** | C++ | Core application logic. |
| **Framework** | Qt 5/6 | Cross-platform desktop application development and UI. |
| **Build System** | Visual Studio | Project files (`.sln`, `.vcxproj`) are configured for MSVC compilation. |
| **File Handling** | Git LFS | Used to store the main project archive (`gestiondechet.zip`). |

## 🚀 Getting Started

Follow these steps to set up and run the project on your local machine.

### Prerequisites

1.  **Git:** For cloning the repository.
2.  **Git LFS (Large File Storage):** Required for the main project archive.
    ```bash
    git lfs install
    ```
3.  **Visual Studio:** The project is configured as a Visual Studio solution.
4.  **Qt Framework:** Install the Qt version compatible with your Visual Studio setup.

### Installation and Setup

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/Hamza00-1/gestiondechet.git
    cd gestiondechet
    ```

2.  **Download the Project Archive (using Git LFS):**
    ```bash
    git lfs pull
    ```

3.  **Extract the Project Files:**
    ```bash
    unzip gestiondechet.zip -d extracted_project
    ```

4.  **Review the Architecture Scaffold:**
    The `src/` directory contains the layered MVVM + repository scaffold that can be integrated into the extracted Visual Studio solution.

### Running the Application

1.  **Open the Solution:**
    ```
    extracted_project/gestiondechet/gestiondechet.sln
    ```

2.  **Configure and Build:**
    *   Ensure Visual Studio links against Qt.
    *   Select a configuration (e.g., `x64-Debug`).
    *   Build the solution (`Build > Build Solution`).

3.  **Execute:**
    Run from Visual Studio (`Debug > Start Debugging` or `F5`).

## 📂 Repository Structure

| Path | Description |
| :--- | :--- |
| `docs/architecture.md` | Layered MVVM + repository architecture notes. |
| `src/` | Architecture scaffold (domain, data, viewmodels, presentation). |
| `gestiondechet.zip` | **(LFS File)** Compressed archive containing the original solution. |
| `CONTRIBUTING.md` | Contribution guidelines. |

## 🤝 Contributing

We welcome contributions! Please see [CONTRIBUTING.md](CONTRIBUTING.md).

## 📄 License

This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.
