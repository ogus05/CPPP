#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

int main(){

    mutex mtx;  //mutual exclusion

    auto work_func = [&](const string & name){
        for(int i = 0;i<5;i++){
            this_thread::sleep_for(chrono::milliseconds(100));
            mtx.lock();
            cout << name << " " << this_thread::get_id() << " is working" << endl;
            mtx.unlock();
        }
    };

    thread t1 = thread(work_func, "JackJack");
    thread t2 = thread(work_func, "Dash");

    t1.join();
    t2.join();
}