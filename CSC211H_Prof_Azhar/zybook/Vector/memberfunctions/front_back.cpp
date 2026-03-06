#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main()
{

    vector<string> name = {"Holly Water", "Spring Water", "Vocano Water"};

    // assert(name.front() == "Holly Beer"); // assumption is not true
    assert(name.back() == "Vocano Water");

    return 0;
}