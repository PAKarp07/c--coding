#include <iostream>


using namespace std;


template <typename T> class vector{

    private:

        T* arr;
        long long size;

    public:



        class iterator{

            private:

                T* ptr;

            public:

                explicit  iterator()
                    : ptr(nullptr)
                {
                }

                explicit iterator(T* dt)
                    : ptr(dt)
                {
                }







        };


    iterator begin() const{

        return iterator(arr);
    }
    iterator end() const{
        return iterator(arr + size);
    }



};



int main() {
    cout << "|-|-|-|-|-|-|-|-|-| Vector class template |-|-|-|-|-|-|-|-|-|" << endl;
    return 0;
}
