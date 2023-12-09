#include <iostream>

#include <SFML/Graphics.hpp>

/// <summary>
/// Here is a Basic example with DLL files
/// </summary>
/// <param name="It is using the DLL files from the DLL folder"></param>
/// <param name="As for the Example It includes SFML to Show the Example Working"></param>
/// <param name="Remember it requires Lib and includes Files to work fully, thought DLLs Including Itself does not require it! "></param>
/// <param name="Additionally all to do with SFML library has been added, it can be replaced with other libraries"></param>
///  <returns></returns>
int main(int args, char* argv[])
{

    /// <summary>
    /// To include DLLs in the Debug or to make sure it runs you need to:
    /// 1. Configuration Properties -> Debugging -> Working Directory -> DLLs 
    /// 2. VC++ Directories -> Reference Directories -> $(ProjectDir)DLLs;$(ReferencePath)
    /// 3. Configuration Properties -> Linker -> General -> Additional Library Directories -> 
    /// $(SolutionDir)\lib;%(AdditionalLibraryDirectories)
    /// 4. Configuration Properties -> C/C++ -> Input ->
    /// lib sfml-system-d.lib, 
    /// sfml - graphics - d.lib, 
    /// sfml - window - d.lib,
    /// sfml - audio - d.lib,
    /// sfml - network - d.lib 
    /// "Additional dependencies -> include " This here States to Look into the folder of Include and its contents"
    /// This tells the compiler how to include the directories of Include and link it to the project Make sure, you include all .lib endings of the Library that are required.
    
    /// 6. Last Linking DLLs from the Folder
    /// Configuration Properties -> Build Events -> Pre-link Event -> Command Line -> copy "$(ProjectDir)DLLs\*.dll" "$(TargetDir)"ping - n 6 127.0.0.1 > nul
    /// This will copy all the DLLs from the DLLs folder to the Debug folder, so it can run without any problems.
    

    /* HERE IS AN EXAMPLE OF THE SFML USE CASE To show the working example */

    // Create an SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Draw something (e.g., a red circle)
        sf::CircleShape circle(50.0f);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(375.0f, 275.0f); // Center the circle in the window
        window.draw(circle);

        // Display the contents of the window
        window.display();
    }

    return 0;
}