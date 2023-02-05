//
//  main.cpp
//  ООП ДЗ 23 преобразование типов
//
//  Created by Павел on 05.02.2023.
//

#include <iostream>

//Задача 3.
class Car{
public:
    virtual void Color(){
        std::cout<<"White"<< std::endl;
    }
};
class Van : public Car{
public:
    void Color() override{
        std::cout << "Red"<<std::endl;
        
    }
};


int main(int argc, const char * argv[]) {
    //Задача 3.
    Car car;
    Van van;
    
    
    //upcast - неявное преобразование
    Car *pCar = &van; // стек
    Car *pCar2 = new Van();// куча
    
    // downcast -  явное преобразование типа
    Van *pVan1 = (Van*)&car;
    Van *pVan2 = static_cast<Van *>(pCar);//через static cast (если наследование классов не виртуальное)
    pCar ->Color();// на экране Red
    pVan1 ->Color();// на экране White
    
    // downcast UB  - так делать нельзя :
   // Van *pVan3 = (Van *)&Car;
    
   // pVan3  ->Color(); // так делать нельзя
    
    
    
    //Задача 1.
    //Целочисленная часть выходит за диапазон предельных значений int, поэтому на экране мы увидим предельное значение диапазона
    double i = 32200030001.1;
    std::cout << "num_double = " << i << std::endl;
  
    // C-style conversion from double to int
    int num_int1 = (int)i;
    std::cout << "num_int1 = " << num_int1 << std::endl;// на экране предельное значение диапазона int   -2147483648
    
    // function-style conversion from double to int
    int num_int2 = int(i);
    std:: cout << "num_int2 = " << num_int2 << std::endl;//на экране то же  самое значение -2147483648
    
    
    // static_cast conversion from double to int
    int num_int3 = static_cast<double>(i);// на экране то же -2147483648
   std:: cout << "num_int3 = " << num_int3 << std::endl;
    
    //Задача 2. Снятие константности
    double c = 3.14;
    const double * pC = &c;
    double *ppC = const_cast<double*>(pC);
    std::cout<<"============="<<std::endl;
    std::cout<<*ppC<<std::endl;
    *ppC = 3.25;
    std::cout<<*ppC<<" "<<c<<std::endl;
    
    
    
    
    
    return 0;
}
