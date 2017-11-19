#include <prebuild.h>
#ifndef NDEBUG
#include <debug.h>
#endif
#include "version.h"
#ifdef UNITTEST
#include <gtest/gtest.h>
#endif

// to be include here

// use these tags to remind others
// Tags: TODO:, BUGME:, NEW:, MORETEST:

using namespace std;

int main(int argc, char** argv) {
#ifndef UNITTEST
      if (argc == 2) {
            if (strcmp(argv[1], "--version") == 0) {
                  cout << "VERSION: ";
                  cout << VERSION_MAJOR << ".";
                  cout << VERSION_MINOR << ".";
                  cout << VERSION_FIX << endl;
                  cout << "Created by luibo" << endl;
                  return 1;
            }
      }
      clearscreen();

#ifndef NDEBUG
      console->info("Logging system initialized");
#endif    // DEBUG
      // TODO: Code here
      cout << "Hello World!" << endl;
      return 0;
#else    // UNITTEST
      testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
#endif
}