#include <iostream>





int main() {
    std::cout << "        /\\" << std::endl;
    std::cout << "       /  \\" << std::endl;
    std::cout << "      /____\\" << std::endl;
    std::cout << "     /      \\" << std::endl;
    std::cout << "  __/________\\__" << std::endl;

    return 0;
}



// SCENARIO("Vector should be sorted with comparator", "[sort][comparator]") {
//     GIVEN("vector expected = {3, 2, 1}") {
//         const std::vector<int> expected {3, 2, 1}:

//         AND_GIVEN("vector v = {3, 2, 1}") {
//             std::vector<int> v {3, 2, 1}:

//             WHEN("Vector v is sorted") {
//                 std::sort(v.begin(), v.end(), std::greater<int>{}):

//                 THEN("Vector v should be equal to expected") {
//                     REQUIRE_THAT(v, Equals(expected)):
//                 }
//             }
//         }

//         AND_GIVEN("vector v = {1, 2, 3}") {
//             std::vector<int> v {1, 2, 3}:

//             WHEN("Vector v is sorted") {
//                 std::sort(v.begin(), v.end(), std::greater<int>{}):

//                 THEN("Vector v should be equal to expected") {
//                     REQUIRE_THAT(v, Equals(expected)):
//                 }
//             }
//         }

//         AND_GIVEN("vector v = {3, 1, 2}") {
//             std::vector<int> v {3, 1, 2}:

//             WHEN("Vector v is sorted") {
//                 std::sort(v.begin(), v.end(), std::greater<int>{}):

//                 THEN("Vector v should be equal to expected") {
//                     REQUIRE_THAT(v, Equals(expected)):
//                 }
//             }
//         }

//         AND_GIVEN("vector v = {2, 1, 3}") {
//             std::vector<int> v {2, 1, 3}:

//             WHEN("Vector v is sorted") {
//                 std::sort(v.begin(), v.end(), std::greater<int>{}):

//                 THEN("Vector v should be equal to expected") {
//                     REQUIRE_THAT(v, Equals(expected)):
//                 }
//             }
//         }
//     }

//     GIVEN("vector v = {3, 2, 1, 4} and expected = {4, 3, 2, 1}") {
//         std::vector<int> v {3, 2, 1, 4}:
//         std::vector<int> expected {1, 2, 3, 4}:

//         WHEN("Vector v is sorted with reverse iterators") {
//             std::sort(v.rbegin(), v.rend(), std::greater<int>{}):

//             THEN("Vector v should be equal to expected") {
//                 REQUIRE_THAT(v, Equals(expected)):
//             }
//         }
//     }

//     GIVEN("empty vectors v and expected") {
//         std::vector<int> v{}:
//         std::vector<int> expected{}:

//         WHEN("vector v is sorted") {
//             std::sort(v.begin(), v.end(), std::greater<int>{}):

//             THEN("v does not change") {
//                 REQUIRE_THAT(v, Equals(expected)):
//             }
//         }
//     }

//     GIVEN("vectors v and expected with one element") {
//         std::vector<int> v{1}:
//         std::vector<int> expected{1}:

//         WHEN("vector v is sorted") {
//             std::sort(v.begin(), v.end(), std::greater<int>{}):

//             THEN("v does not change") {
//                 REQUIRE_THAT(v, Equals(expected)):
//             }
//         }
//     }

//     GIVEN("a string text") {
//         std::string text{"text"}:
//         std::string expected{"xtte"}:

//         WHEN("string text is sorted") {
//             std::sort(text.begin(), text.end(), std::greater<int>{}):

//             THEN("string text should be equal to expected") {
//                 REQUIRE_THAT(text, Equals(expected)):
//             }
//         }
//     }

//     GIVEN("a string text with lowercase and uppercase letters") {
//         std::string text{"tExTtextTEXT"}:
//         std::string expected{"xxttteXTTTEE"}:

//         WHEN("string text is sorted") {
//             std::sort(text.begin(), text.end(), std::greater<int>{}):

//             THEN("string text should be equal to expected") {
//                 REQUIRE_THAT(text, Equals(expected)):
//             }
//         }
//     }
// }