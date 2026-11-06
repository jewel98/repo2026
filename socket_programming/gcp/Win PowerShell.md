**The Visual Studio Graphic Interface**

Open Visual Studio and select Create a new project.

Choose Console App (make sure it's the C++ template, which natively compiles C code).

Delete the default boilerplate code in ProjectName.cpp and rename the file extension to .c (e.g., client.c).

Paste your client C code into the file.

**Important for Windows:** At the very top of your code, add the line from the next slide to tell Visual Studio to link the network libraries. 

Click the Local Windows Debugger (Play) button at the top to compile and run it.

Note: If Visual Studio gives you an error about inet_pton or inet_addr being unsafe, add #define _WINSOCK_DEPRECATED_NO_WARNINGS and #define _CRT_SECURE_NO_WARNINGS to the very top line of your code.
<img width="4247" height="654" alt="image" src="https://github.com/user-attachments/assets/d762130d-59a2-4f75-847c-cfa25a5a4a50" />
