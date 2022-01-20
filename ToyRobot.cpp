#include "ToyRobot.h"

#include <iostream>
#include <vector>

//---------------------------------------------------------------------------------------------------------------------
const int ToyRobot::GridSize = 5;
const std::string ToyRobot::CommandPlace = "PLACE";
const std::string ToyRobot::CommandMove = "MOVE";
const std::string ToyRobot::CommandLeft = "LEFT";
const std::string ToyRobot::CommandRight = "RIGHT";
const std::string ToyRobot::CommandReport = "REPORT";
const std::string ToyRobot::CommandQuit = "QUIT";

const std::string ToyRobot::CommandNorth = "NORTH";
const std::string ToyRobot::CommandEast = "EAST";
const std::string ToyRobot::CommandSouth = "SOUTH";
const std::string ToyRobot::CommandWest = "WEST";
//---------------------------------------------------------------------------------------------------------------------
namespace
{
   const int InvalidPosition = -1;

   //---------------------------------------------------------------------------------------------------------------------
   bool ValidatePlaceCommand(int x, int y, const std::string &f)
   {
      if (x < 0 || x >= ToyRobot::GridSize)
      {
         std::cout << "X value (" << x << ") is invalid. Please use a value of 0 or greater and less than " << 
            ToyRobot::GridSize << std::endl;

         return false;
      }
      else if (y < 0 || y >= ToyRobot::GridSize)
      {
         std::cout << "Y value (" << y << ") is invalid. Please use a value of 0 or greater and less than " << 
            ToyRobot::GridSize << std::endl;

         return false;
      }
      else if (f != ToyRobot::CommandNorth &&
               f != ToyRobot::CommandEast &&
               f != ToyRobot::CommandSouth &&
               f != ToyRobot::CommandWest)
      {
         std::cout << "F value (" << f << ") is invalid. Please use a values " << ToyRobot::CommandNorth << "," << 
            ToyRobot::CommandEast << "," << ToyRobot::CommandSouth << "," << ToyRobot::CommandWest << std::endl;

         return false;
      }

      return true;
   }
   //---------------------------------------------------------------------------------------------------------------------
}

//---------------------------------------------------------------------------------------------------------------------
ToyRobot::ToyRobot() : m_x(InvalidPosition), m_y(InvalidPosition)
{
}
//---------------------------------------------------------------------------------------------------------------------
void ToyRobot::TurnLeft()
{
   if (m_facing == CommandNorth)
   {
      m_facing = CommandWest;
   }
   else if (m_facing == CommandWest)
   {
      m_facing = CommandSouth;
   }
   else if (m_facing == CommandSouth)
   {
      m_facing = CommandEast;
   }
   else if (m_facing == CommandEast)
   {
      m_facing = CommandNorth;
   }
}
//---------------------------------------------------------------------------------------------------------------------
void ToyRobot::TurnRight()
{
   if (m_facing == CommandNorth)
   {
      m_facing = CommandEast;
   }
   else if (m_facing == CommandEast)
   {
      m_facing = CommandSouth;
   }
   else if (m_facing == CommandSouth)
   {
      m_facing = CommandWest;
   }
   else if (m_facing == CommandWest)
   {
      m_facing = CommandNorth;
   }
}
//---------------------------------------------------------------------------------------------------------------------
void ToyRobot::Report()
{
   std::cout << "Output: " << m_x << "," << m_y << "," << m_facing << std::endl;
}
//---------------------------------------------------------------------------------------------------------------------
bool ToyRobot::Move()
{
   if (m_facing == CommandNorth)
   {
      if (m_y + 1 == GridSize)
      {
         std::cout << "Already at the northen most point." << std::endl;
         return false;
      }

      m_y += 1;
   }
   else if (m_facing == CommandSouth)
   {
      if (m_y - 1 < 0)
      {
         std::cout << "Already at the southern most point." << std::endl;
         return false;
      }

      m_y -= 1;
   }
   else if (m_facing == CommandEast)
   {
      if (m_x + 1 == GridSize)
      {
         std::cout << "Already at the eastern most point." << std::endl;
         return false;
      }

      m_x += 1;
   }
   else if (m_facing == CommandWest)
   {
      if (m_x - 1 < 0)
      {
         std::cout << "Already at the western most point." << std::endl;
         return false;
      }

      m_x -= 1;
   }
   else
   {
      //shouldn't happen
      return false;
   }

   return true;
}
//---------------------------------------------------------------------------------------------------------------------
bool ToyRobot::PerformCommand(const std::string& input)
{
   std::stringstream comdList(input);
   std::string command;
   comdList >> command;

   if (command == CommandPlace)
   {
      int x = 0;
      int y = 0;
      std::string f;

      std::string temp;
      std::vector<std::string> params;
      while(std::getline(comdList, temp, ',')) 
      {
         params.push_back(temp);
      }

      if (params.size() != 3)
      {
         std::cout << "PLACE expects 3 arguments. " << params.size() << " were given." << std::endl;
         return false;
      }

      try
      {
         x = std::stoi(params[0]);
         y = std::stoi(params[1]);
         f = params[2];
      }
      catch(const std::exception& e)
      {
         std::cerr << "Error in conversion: " << e.what() << std::endl;
         return false;
      }

      if (ValidatePlaceCommand(x, y, f) == false)
      {
         return false;
      }

      m_x = x;
      m_y = y;
      m_facing = f;
      return true;
   }

   if (m_x == InvalidPosition)
   {
      std::cout << "Please use the " << CommandPlace << " command first to initialise a position." << std::endl;
      return false;
   }
   else if (command == CommandMove)
   {
      return Move();
   }
   else if (command == CommandLeft)
   {
      TurnLeft();
   }
   else if (command == CommandRight)
   {
      TurnRight();
   }
   else if (command == CommandReport)
   {
      Report();
   }
   else
   {
      std::cout << "Invalid command " << command << std::endl;
      return false;
   }

   return true;
}

//---------------------------------------------------------------------------------------------------------------------
void ToyRobot::Run()
{
   std::cout << "Welcome to ToyRobot!" << std::endl;
   std::cout << "Please begin with the 'PLACE' command. Eg, \"PLACE 0,0,NORTH\"" << std::endl;

   while (true)
   {
      std::string buffer;
      std::getline(std::cin, buffer);

      if (buffer == CommandQuit)
      {
         return;
      }

      if (PerformCommand(buffer) == true)
      {
         std::cout << "Success" << std::endl;
      }
   }
}
//---------------------------------------------------------------------------------------------------------------------