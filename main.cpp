#include <iostream>

template <typename T>
class GenericArray{
private:
    T* array;
    int array_size;

public:
    GenericArray(){
        array = nullptr;
        array_size = 0;
    }

    ~GenericArray(){
        delete[] array;
    }

    void addElement(T element){
        T* new_array = new T[array_size + 1];
        for (int i = 0; i < array_size; i++){
            new_array[i] = array[i];
        }
        new_array[array_size] = element;
        delete[] array;
        array = new_array;
        array_size++;
    }

    T at(int param) const{
        return array[param];
    }

    int size() const{
        return array_size;
    }

    T sum() const{
        T total = T();
        for (int i = 0; i < array_size; i++) {
            total += array[i];
        }
        return total;
    }

    T max() const{
        if (array_size == 0) return T();
        T maxVal = array[0];
        for (int i = 1; i < array_size; i++) {
            if (array[i] > maxVal) maxVal = array[i];
        }
        return maxVal;
    }

    T min() const{
        if (array_size == 0) return T();
        T minVal = array[0];
        for (int i = 1; i < array_size; i++) {
            if (array[i] < minVal) minVal = array[i];
        }
        return minVal;
    }

    T* slice(int begin, int end) const{
        if (begin < 0) begin = 0;
        if (end >= array_size) end = array_size - 1;
        if (begin > end || array_size == 0) return nullptr;
        int newSize = end - begin + 1;
        T* newArray = new T[newSize];
        for (int i = 0; i < newSize; i++) {
            newArray[i] = array[begin + i];
        }
        return newArray;
    }
};

int main(){
    GenericArray<int> arr;
    arr.addElement(10);
    arr.addElement(20);
    arr.addElement(30);
    arr.addElement(40);
    arr.addElement(50);

    std::cout << "size : " << arr.size() << std::endl;
    std::cout << "at -1 : " << arr.at(-1) << std::endl;
    std::cout << "at 3 : " << arr.at(3) << std::endl;
    std::cout << "at 10 : " << arr.at(10) << std::endl;
    std::cout << "sum : " << arr.sum() << std::endl;
    std::cout << "max : " << arr.max() << ", min : " << arr.min() << std::endl;

    int* sliced1 = arr.slice(1, 3);
    std::cout << "slice(1,3): ";
    for (int i = 0; i <= 2; i++) std::cout << sliced1[i] << " ";
    std::cout << std::endl;
    delete[] sliced1;

    int* sliced2 = arr.slice(-1, 10);
    std::cout << "slice(-1,10): ";
    for (int i = 0; i < arr.size(); i++) std::cout << sliced2[i] << " ";
    std::cout << std::endl;
    delete[] sliced2;

    int* sliced3 = arr.slice(-2, 3);
    std::cout << "slice(-2,3): ";
    for (int i = 0; i <= 3; i++) std::cout << sliced3[i] << " ";
    std::cout << std::endl;
    delete[] sliced3;

    int* sliced4 = arr.slice(1, 9);
    std::cout << "slice(1,9): ";
    for (int i = 0; i < arr.size() - 1; i++) std::cout << sliced4[i] << " ";
    std::cout << std::endl;
    delete[] sliced4;

    return 0;
} 
