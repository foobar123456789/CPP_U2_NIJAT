#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "levenshtein.hpp"

TEST_CASE("Signature for helper function")
 {
 std::string original = "Originalwort";
 std::string katze = "Katzenwort";

 int *D = new int[(original.size()+1) * (katze.size()+1)];
 int i = 1;
 int j = 0;

 int result = minimal(D, &original, &katze, i, j);
 }

TEST_CASE("Edit-distance function")
 {
 std::string original = "Originalwort";
 std::string katze = "Katzenwort";
 int result = levenshtein_distance(original, katze);
 }

