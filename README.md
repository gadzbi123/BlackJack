# Project for Black Jack in C++

Made in Visual Studio. Add to propery pages of the project:

Compile in Release Mode x86.

C/C++ -> General -> Additional Include Directories = "{project_path}\BlackJack\SFML\include";
C/C++ -> Preprocessor -> Preprocessor Definitions = SFML_STATIC; 

Linker -> General -> Additional Library Directories = "{project_path}\BlackJack\SFML\lib"
Linker -> Input -> Additional Dependencies = "sfml-graphics-s.lib";"sfml-window-s.lib";"sfml-system-s.lib";"opengl32.lib";"freetype.lib";"winmm.lib";"gdi32.lib";"user32.lib";"Advapi32.lib";
