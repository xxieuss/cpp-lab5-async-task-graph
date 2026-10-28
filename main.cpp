#include <iostream>
#include <syncstream>
#include <thread>
#include <chrono>
#include <string>
#include <future>

using namespace std;

void compute(const string &name, chrono::seconds duration) {
    this_thread::sleep_for(duration);
    osyncstream(cout) << name << endl;
}

void work() {
    auto begin = chrono::steady_clock::now();
 
    auto chainB = async(launch::async, []
        {
            compute("B1", 1s);
            compute("B2", 7s);
            compute("B3", 1s);
        });
 
    compute("A1", 1s);
    compute("A2", 7s);
    compute("A3", 1s);
 
    chainB.get();
 
    compute("C", 1s);
 
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed = end - begin;
 
    cout << "Execution time: " << elapsed.count() << " s" << endl;
    cout << "Work is done!" << endl;
}

int main() {
    work();
    return 0;
}