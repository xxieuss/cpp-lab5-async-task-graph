#include <iostream>
#include <syncstream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

void compute(const string &name, chrono::seconds duration) {
    this_thread::sleep_for(duration);
    osyncstream(cout) << name << endl;
}

int main() {
    compute("check", 1s);
    return 0;
}