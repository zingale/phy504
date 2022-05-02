#include <iostream>
#include <omp.h>

int main() {

    std::cout << "total number of threads = " << omp_get_max_threads() << std::endl;

    #pragma omp parallel
    {
        #pragma omp critical
        std::cout << "Hello from thread " << omp_get_thread_num() << std::endl;
    }
}
