
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;
class dynarray{
    int* data;
    unsigned int size;
    public:
        dynarray(unsigned int item=1){
            size = item;
            data = new int[item];
            for(unsigned int i=0;i<item;i++){
                data[i]=0;
            }
            
        }
        ~dynarray(){ delete[] data;}
        void operator =(const dynarray & src) {
            if (data!=nullptr)
                delete[] data;
            size = src.size;
            data = new int[size];
            memcpy(data, src.data, size*sizeof(int));
        }
        size_t getSize(){
            return size;
        }
        void foo(){
        for (unsigned i = 0; i < size; i++ )
            cout << data[i] << " ";
            cout << endl;
        }
        int& operator[] (int index){
        if(index >= 0 && index < size){
            return data[index];
        }else if(index > size){
            size_t size2 = size*2;
            int *buffer = new int[size2];
            for(size_t i=0;i<size ; i++){
                buffer[i] = data[i];
            }
            for(size_t i=size;i<size2;i++){
                buffer[i]=0;
            }
            delete [] data;
            data = buffer;
            size = size2;
            return data[index];
            
            
            cout << true;
        }  
        
    }
};




int main()
{
    dynarray a(3);
    dynarray b;
    
    a.foo();
    a[0] = -7;
    a[1] = 3; 
    a[5] = 2;
    a.foo();
    b=a;
    b.foo();
    a[7]=8;
    a.foo();
    //cout << a << endl;
    
}