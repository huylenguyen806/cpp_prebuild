#ifndef PREBUILD_H
#define PREBUILD_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __unix
#include <termios.h>
#include <unistd.h>
#include <term.h>
#endif

inline std::string HidePassword() {
      std::string pwd;

#ifdef _WIN32
      HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
      DWORD mode    = 0;
      GetConsoleMode(hStdin, &mode);
      SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

      getline(std::cin, pwd);

      SetConsoleMode(hStdin, mode);
#endif

#ifdef __unix
      termios oldt;
      tcgetattr(STDIN_FILENO, &oldt);
      termios newt = oldt;
      newt.c_lflag &= ~ECHO;
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);

      getline(std::cin, pwd);

      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif

      std::cout << std::endl;
      return pwd;
}

inline void clearscreen() {    // system is evil
#ifdef _WIN32
      system("cls");
#endif

#ifdef __unix
      system("clear");
#endif
}


inline void pausescreen() {    // system is evil
#ifdef _WIN32
      system("pause");
#endif

#ifdef __unix
      std::cout << "Press any key to continue" << std::endl;
      std::cin.get();
#endif
}

#endif