# VS.DLLinFolder
 An Example how to Include DLL Files in a folder and send it to the Debug or build worlder from it to generate a working build directory.


1.  Add some kind of library or something that requires general .dll files that are not usually available on an avarage computer.


      * For the example I have included a Middleware library for C++ called " SFML ", which additionally has " lib " and " Include " files added with the folders to showcase the required example and can be replaced with any other example and don't nessecary need "SFML" To be added.
      * Remember that " Include " and " lib " are not needed if you don't add the code within Main, and just have your own or " return 0; " only.
      * dlls can be of any kind "Windows, Libraries, Additional Dependencies etc."

2. Open Project Properties by (Right click on the Solution -> Project Properties in visual studio).
3. Within the properties Go Configuration Properties -> Debugging -> Working Directory. (There you want to add the folder " DLLs " This means that the Project Starts building from the "DLLs" Folder instead of the Root of it.
4. Once that is done move onto Configuration Propperties -> C/C++ -> Additional Include Directories. (There you need to add the folder " include " these are the library build files that are used in your application.
5. To then link the Project with the Library you need to link them using ".lib" which can be performed through.
6. Configuration Properties -> Linker -> Input ( sfml-system-d.lib, sfml-graphics-d.lib, sfml-window-d.lib, sfml-audio-d.lib, sfml-network-d.lib ) " These will be different depending on the libraries that you are using but with these example are nessecary).
7. Last thing required to do is to build " DLLs " folder into the Final build directory by going: Configuration Properties -> Build Events -> Pre link Events. (There you want to use the Copy function that locates everything in the folder and takes them out of the folder and adds it to the build root).

   
9. The following command you need to add is

    
   " copy "$(ProjectDir)DLLs\*.dll" "$(TargetDir)"


   " ping -n 6 127.0.0.1 > nul  "


10. With this everything is setup and you need to make a Source.cpp file and have a " Main " function with "return 0;" And the build should work as intended.
