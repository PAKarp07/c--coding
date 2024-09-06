#include <iostream>


using namespace std;


template <typename T> class vector{

    private:

        T* arr;
        size_t  size_;
        size_t  capacity_;



    public:

        vector() : size_(0), capacity_(1), arr(new T[1]) {}
        ~vector() {delete[] arr;}

        T operator[](long long index) const{
            return at(index);
        }

        vector& operator=(const vector& other){

            if(this == &other) return *this;

            delete[] arr;

            size_ = other.size();
            capacity_ = other.size();
            arr = new T[capacity_];

            for(size_t i = 0; i < size_; i++)
                arr[i] = other.at[i];

            return *this;
        }

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

                T& operator*() {return *ptr;}
                iterator operator++() {ptr++; return *this; }
                iterator operator--() {ptr--; return *this; }
                iterator operator+(const iterator& other) {return (ptr + other); }
                iterator operator-(const iterator& other) {return (ptr - other); }
                bool operator==(const iterator& other){ return (ptr == other); }
                bool operator!=(const iterator& other){ return (ptr != other); }
                bool operator<=(const iterator& other){ return (ptr <= other); }
                bool operator>=(const iterator& other){ return (ptr >= other); }
                bool operator>(const iterator& other){ return (ptr > other); }
                bool operator<(const iterator& other){ return (ptr < other); }


                void advance(const iterator& it, int n){
                    return (it + n);
                }


        };


        T at(long long index){

            if(index >= capacity_){
                cout << "Error! Index out of bounds." << endl;
                exit(0);
            }

            return *(arr + index);

        }

        void resize(size_t new_capacity){

            T* new_array = new T[new_capacity];
            for(int i = 0; i < size_; i++)
                new_array[i] == arr[i];

            delete[] arr;
            arr = new_array;
            capacity_ = new_capacity;

        }

        void push_back(const T& value){

            if(size_ == capacity_){
                resize(2 * capacity_);
            }

            arr[size_++] = value;

        }

        void pop_back(){

            if(size_ > 0){
                arr[size_-1] = {};
                size_--;
            }else{
                throw underflow_error("Error! Vector already empty!");

            }


        }

        void clear(){

            delete[] arr;
            size_ = 0;

        }

        size_t size(){

            return size_;
        }


        size_t capacity(){

            return capacity_;
        }

        T front(){

            if(size_ > 0)
                return at(0);
            else
                throw underflow_error("Error! Vector is empty!");
        }

        T back(){

            if(size_ > 0)
                return at(size_ - 1);
            else
                throw underflow_error("Error! Vector is empty!");
        }

        iterator begin(){

            return iterator(arr);
        }
        iterator end(){
            
            return iterator(arr + size_);
        }


};



int main() {
    cout << "|-|-|-|-|-|-|-|-|-| Vector class template |-|-|-|-|-|-|-|-|-|" << endl;

    vector<int> v;




    return 0;
}
