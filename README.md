# 🎮 Pong Game in C++ using Raylib

[![C++](https://img.shields.io/badge/Language-C++-blue)](https://isocpp.org/) 
[![Raylib](https://img.shields.io/badge/Library-Raylib-green)](https://www.raylib.com/)
[![License](https://img.shields.io/badge/License-MIT-yellow)](LICENSE)

A **classic Pong-style 2D game** developed in **C++ using Raylib**.  
This project demonstrates **Object-Oriented Programming (OOP)**, modular design, and basic **game development concepts**.  
Play against the computer with smooth ball and paddle movement, collision detection, and a **restart feature**.

---

## 🏆 Features
- **Player vs Computer** gameplay  
- Smooth ball and paddle movement  
- Accurate collision detection (ball–paddle & walls)  
- Real-time score tracking  
- **Restart button** on game over screen  
- Organized and modular code with **separate header (.h) and source (.cpp) files**  

---

## 💻 Technologies
- **Programming Language:** C++  
- **Graphics Library:** Raylib  
- **Compiler:** MinGW (g++)  
- **IDE:** Visual Studio Code  

---

## 🧠 Concepts Demonstrated
- C++ Classes, Objects, and Constructors  
- Encapsulation and modular programming  
- Game loop and frame-rate control  
- Handling user input and real-time graphics with Raylib  

---

# ⚙️ Pong Game Setup Instructions

This guide explains how to **build and run the Pong Game** created in **C++ using Raylib**.  
Follow these steps carefully to run the project without errors.

---

 1️⃣ Clone the Repository
Open a terminal and run:

```bash
git clone <your-repo-url>
This will download all the project files to your local machine.

2️⃣ Install Raylib
Download and install Raylib for your operating system: https://www.raylib.com

Ensure Raylib is properly linked with your C++ compiler (e.g., MinGW for Windows).

3️⃣ Open Project in Visual Studio Code
Launch Visual Studio Code

Open the folder you cloned in Step 1.

4️⃣ Build the Project
Use the terminal in VS Code or any command line to compile the project:

```bash
g++ src/*.cpp -o build/main.exe -lraylib -lopengl32 -lgdi32 -lwinmm
Make sure all .cpp and .h files are inside the /src folder.

5️⃣ Run the Executable
After compilation, execute the program:

```bash
./build/main.exe
The game window should open and the game will start.

6️⃣ Play the Game
Control your paddle with the keyboard or mouse.

The computer acts as the opponent.

Use the restart button after game over to play again.
