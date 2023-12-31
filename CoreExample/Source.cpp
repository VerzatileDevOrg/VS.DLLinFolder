#include <iostream>

#include <SFML/Graphics.hpp>

/// <summary>
/// Here is a Basic example with DLL files
/// </summary>
/// <param name="It is using the DLL files from the DLL folder"></param>
/// <param name="As for the Example It includes SFML to Show the Example Working"></param>
/// <param name="Remember it requires Lib and includes Files to work fully, though DLLs Including Itself does not require it! "></param>
/// <param name="Additionally all to do with SFML library has been added, it can be replaced with other libraries"></param>
///  <returns></returns>
int main(int args, char* argv[])
{

    /// <summary>
    /// To include DLLs in the Debug or to make sure it runs you need to:
    /// 
    /// 1. Create a Folder called DLLs in the root of the project
    /// 
    /// 2. Configuration Properties -> Debugging -> Environment -> PATH=$(ProjectDir)\DLLs
    /// Note - Specify more paths by ";" separating them as example: " PATH=$(ProjectDir)\DLLs;$(ProjectDir)\DLLs2;$(ProjectDir)\DLLs3 "
    /// Alternativly you can specify " Working Directory " to start from the "DLLs" folder
    /// 
    /// 3. Configuration Properties -> Linker -> General -> Additional Library Directories -> 
    /// $(SolutionDir)\lib;%(AdditionalLibraryDirectories)
    /// 
    /// 4. Configuration Properties -> Linker -> Input ->
    /// lib sfml-system-d.lib, 
    /// sfml - window - d.lib,
    /// sfml - graphics - d.lib, 
    /// sfml - audio - d.lib,
    /// sfml - network - d.lib 
    /// 
    /// "Additional dependencies -> include " This here States to Look into the folder of Include and its contents"
    /// This tells the compiler how to include the directories of Include and link it to the project Make sure, you include all .lib endings of the Library that are required.
    ///
    /// --Optional--
    /// 5. Last Linking DLLs from the Folder to Debug Folder
    /// Configuration Properties -> Build Events -> Pre-link Event -> Command Line -> copy "$(ProjectDir)DLLs\*.dll" "$(TargetDir)"ping - n 6 127.0.0.1 > nul
    /// This will copy all the DLLs from the DLLs folder to the Debug folder directly, to the root of the debug folder.

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

        // After Proccessing do the following Listed
        // Clear the window
        window.clear();

        // Setup a circle shape with by defined properties
        sf::CircleShape circle(50.0f);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(375.0f, 275.0f); // Center the circle in the window
        window.draw(circle); // Draw the shape

        // Display the contents of the window
        window.display();
    }
    return 0;
}