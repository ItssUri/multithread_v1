#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <string>

int main() {
     // We initialize our srand seed to generate difference pseudo random numbers everytime. 
    int processNumbers;
    std::cout << "How many processes do you want to create? ";
    std::cin >> processNumbers; // We retrieve the number of processes from the user
    std::vector<std::string> processNames; // We will be using a vector of strings. A vectpor is just like a Java ArrayList.
    pid_t pid;
    
    for (int i = 0; i < processNumbers; i++)
    {
        std::cout << "&\ti = " << i << std::endl; // Prints the iteration number that we are currently on. Like a lap counter.
        pid = fork(); // Creates a child process.
        srand(time(NULL));
        if (pid != 0) // Checks if the process running this is a parent or a child.
        {
            std::cout << "&\tGenerated process " << pid << std::endl;
        } else { // If the process running this, it will print so.
            std::cout << "&\tGenerated Child Process" << std::endl;
        }
        
        if (pid == 0) // Only child processes will run this
            {
                std::string processName;
                std::cout << "&\tEnter name for this process: "; // Asks for a process name
                std::cin >> processName;
                processNames.push_back(processName); // Adds the process name to the vector.
                std::cout << "&\tAppended item " << processName;
                std::string randomName = processNames[(rand()%processNames.size())]; // Gets a random item from our vector
                std::cout << "\n&\tThis process has picked process " << randomName << " as a random one."  << std::endl  << std::endl; // Prints the random item
                
                // Example of an output
                // &       i = 0                                                            ==> Current lap/iteration
                // &       Generated process 21898                                          ==> Parent process_id
                // &       Generated Child Process                                          
                // &       Enter name for this process: Process_name
                // &       Appended item Process_name                                       ==> Appends the process name to the vector
                // &       This process has picked process Process_name as a random one.    ==> Shows the randomly picked item from the vector
            
            } else {
                wait(NULL); // This will run only if the process running it is a parent process, which will wait for the child process to end
                break;
            }
    }
}