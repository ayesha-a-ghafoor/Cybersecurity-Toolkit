# 🛡️ C++ Defensive Cybersecurity Toolkit

A modular **command-line cybersecurity utility** engineered in **C++** to demonstrate fundamental concepts of defensive security, cryptography, authentication, and file integrity verification.

The toolkit combines password analysis, encryption utilities, and integrity-checking mechanisms into a unified interactive console dashboard designed for learning low-level cybersecurity concepts through practical implementation.

---

# 📌 Project Overview

This project was developed as a lightweight and modular defensive security toolkit capable of:

* Evaluating password strength using heuristic scoring models
* Encrypting and decrypting text using classical cryptographic techniques
* Performing low-level bitwise stream manipulation
* Detecting unauthorized file modifications through hashing mechanisms
* Providing real-time console-based security feedback

The system emphasizes **core cybersecurity principles** while maintaining a fully native C++ implementation without heavy third-party frameworks.

---

# ⚙️ Core Technical Features

# 🔐 1. Password Strength Assessment Engine

### ✔ Heuristic-Based Security Analysis

Analyzes user passwords against multiple validation rules including:

* Minimum length requirements
* Uppercase & lowercase combinations
* Numeric inclusion
* Symbol diversity
* Structural complexity patterns

### ✔ Security Scoring System

Computes an exact password score out of **7 security checkpoints** to estimate overall password resilience.

### ✔ Real-Time Feedback

Provides:

* Instant validation responses
* Weakness identification
* Improvement recommendations
* Risk-profile based suggestions

---

# 🔄 2. Stream & Rotation Cipher Implementations

## 🔹 Caesar Cipher

Implements classical rotational cryptography using configurable character shifting for:

* Encryption
* Decryption
* Custom shift-key transformations

### Features:

* Alphabet wrapping logic
* Uppercase/lowercase preservation
* Interactive shift control

---

## 🔹 XOR Stream Cipher

Developed a lightweight symmetric XOR encryption mechanism using:

* Bitwise operations
* Character-key masking
* Hexadecimal byte rendering

### Capabilities:

* Real-time text encryption
* Hexadecimal output formatting
* Reversible symmetric decryption

---

# 🧾 3. File Integrity Verification System

### ✔ Binary File Stream Reading

Reads underlying raw byte streams of selected files for integrity analysis.

### ✔ Defensive Hash Validation

Implements custom hashing functionality through:

* `file_hasher`
* Stream-based byte processing
* Baseline integrity checks

### ✔ Tamper Detection

Compares generated hashes against known trusted values to detect:

* Unauthorized modifications
* Data tampering
* Unexpected file changes

---

# 🏗️ System Architecture

The toolkit follows a modular structure:

```text
main.cpp
│
├── password_checker.cpp
├── caesar_cipher.cpp
├── xor_cipher.cpp
├── file_hasher.cpp
└── utility_modules.cpp
```

Each module is independently organized to improve:

* Code maintainability
* Reusability
* Scalability
* Feature extension

---

# 💻 Tech Stack & Standards

| Category                | Technology                         |
| ----------------------- | ---------------------------------- |
| **Language**            | C++                                |
| **Programming Style**   | Object-Oriented & Modular          |
| **Compilation Targets** | G++, Clang                         |
| **Platform**            | Cross-platform Console Application |
| **Terminal Rendering**  | ANSI Escape Sequences              |

---

# 📚 Core Libraries Utilized

```cpp id="p4e7f6"
<iostream>
<string>
<vector>
<limits>
<iomanip>
<fstream>
<sstream>
```

---

# 🚀 How to Run

## 1️⃣ Clone the Repository

```bash id="eq0uhv"
git clone <repository-link>
```

---

## 2️⃣ Compile the Project

Using **G++**:

```bash id="u2qesn"
g++ main.cpp password_checker.cpp caesar_cipher.cpp xor_cipher.cpp file_hasher.cpp -o toolkit
```

Using **Clang**:

```bash id="ngz8yb"
clang++ main.cpp password_checker.cpp caesar_cipher.cpp xor_cipher.cpp file_hasher.cpp -o toolkit
```

---

## 3️⃣ Run the Executable

### Linux / macOS

```bash id="13xnhx"
./toolkit
```

### Windows

```bash id="wtqh1m"
toolkit.exe
```

---

# 📊 Functional Highlights

The toolkit demonstrates:

* Password risk analysis
* Symmetric encryption techniques
* Classical cryptography concepts
* File integrity verification
* Stream-based data processing
* Bitwise logical operations
* ANSI terminal UI rendering
* Defensive cybersecurity workflows

---

# 🎯 Project Goals

* Demonstrate practical defensive security concepts
* Explore low-level cryptographic implementations
* Practice modular C++ software architecture
* Simulate real-world integrity verification workflows
* Build foundational cybersecurity programming skills

---

# 🔒 Cybersecurity Concepts Covered

* Password Security
* File Integrity Monitoring
* Stream Ciphers
* Classical Cryptography
* XOR Encryption
* Data Authentication
* Defensive Security Engineering
* Secure Coding Principles

---

# 👨‍💻 Project Domain

* Cybersecurity
* Defensive Security
* Cryptography
* Secure Software Development
* C++ Systems Programming
* Information Security

