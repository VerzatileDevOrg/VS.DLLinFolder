# VS.DLLinFolder

#### Including DLL Files in a Visual Studio Project

## Introduction:
This guide demonstrates how to include DLL files in a folder and seamlessly integrate them into the Debug or Build folder to generate a working build directory. It is particularly useful when dealing with libraries that require specific DLL files.

## Example Library: SFML
In this example, we'll use the SFML (Simple and Fast Multimedia Library) for C++, including its "lib" and "include" files. However, you can replace SFML with any other library as needed.

**Note:** If your project doesn't utilize the included code within the main function, the "include" and "lib" folders are not necessary.

## Configuration Steps:

Two list of option: 

1. **Through Setting Working Directory:**
   - Open Project Properties (Right-click on the Solution -> Project Properties in Visual Studio).
   - Navigate to Configuration Properties -> Debugging -> Working Directory.
   - Add the folder "DLLs" to specify that the project starts building from the "DLLs" folder instead of the root directory.
  
 2. **Through Setting the directory to look from**
    - " Use the following if you want to or aim to specify multiple location such as project location (DLLs) or local system storage locations.
    - Navigate to Configuration Properties -> Debugging -> Environment.
    - Specify a path as an example ` PATH=$(ProjectDir)\DLLs `, Where `(ProjectDir)` specifies the project root and `\DLLs` its folder.
    - This example the Working directory should be of `$(ProjectDir)`.

The following option should be preffered as it lets you specify multiple areas for your DLLs


## Optional 
### (Specific to your application and not nessecary, used to showcase the Example working)

Setting up include directories and libraries:

1. **Configuring Include Directories:**
   - In Configuration Properties -> C/C++ -> Additional Include Directories, add the folder "include." These are the library build files used in your application.

2. **Linking with Library:**
   - Link the project with the library using ".lib" files.
   - Go to Configuration Properties -> Linker -> Input.
   - Add the necessary library dependencies (e.g., sfml-system-d.lib, sfml-graphics-d.lib, sfml-window-d.lib, sfml-audio-d.lib, sfml-network-d.lib).

## Final Step (Required)

1. **Building DLLs into output Directory:**
   - Navigate to Configuration Properties -> Build Events -> Pre-link Events.
   - Use the Copy function to move files from the "DLLs" folder to the build root.

2. **Add the Following Command:**
   ```bash
   copy "$(ProjectDir)DLLs*.dll" "$(TargetDir)"
   ping -n 6 127.0.0.1 > nul

   ```
    2.1  Notes for Expanding
      - Copy
        - `copy` function to copy all DLL files `(*.dll)` from the "DLLs" folder in your project directory `($(ProjectDir))` to the target directory where the final build is stored `($(TargetDir))`
        - Adjust the file path according to the folder names based on Configuration steps 1 or 2.
        - `.dll` Specifies that all with an extentsion of it should be added to the build.
       
        - Specify further `copy` in the next line, depending on the amount of DLL dependencies change the ping of `-n 6`
        - Alternativly the specification for specific `dll` can be called as such `copy "$(ProjectDir)DLLs\YourDLL1.dll" "$(TargetDir)"`, which instead using all in the directory calls the specified `.dll` file.
    
      - ping -n 6 127.0.0.1 > nul
        - Used to add additionaly day to ensure, that the project has sufficient time to link and build "dynamic libraries " DLLs
        - `ping` command, essentially specifying a delay with amount.
        - `-n 6` by 6 seconds
        - `127.0.0.1 ` Loopback address, send loop to Address of 6 times with a delay of 6 seconds.
        - `> nul` Supresses output from the display (Directing the output to void)
     

   
