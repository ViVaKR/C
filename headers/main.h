#include "vivstd.h"

#include "../demo/Advenced.c"
#include "../demo/ArithmeticOperators.c"
#include "../demo/Array.c"
#include "../demo/Array2D.c"
#include "../demo/ArrayB.c"
#include "../demo/ArrayPointer.c"
#include "../demo/ArrayShift.c"
#include "../demo/BinarySearchTree.c"
#include "../demo/Bits.c"
#include "../demo/Calculate.c"
#include "../demo/CallByPointer.c"
#include "../demo/CallByValue.c"
#include "../demo/CharArrayPointer.c"
#include "../demo/CheckInput.c"
#include "../demo/CopyMemory.c"
#include "../demo/DataStruct.c"
#include "../demo/DataType.c"
#include "../demo/Database.c"
#include "../demo/DefineTypedef.c"
#include "../demo/FGets.c"
#include "../demo/Fibo.c"
#include "../demo/FileReadWrite.c"
#include "../demo/Files.c"
#include "../demo/Function.c"
#include "../demo/GetChar.c"
#include "../demo/GetStringLength.c"
#include "../demo/Iterator.c"
#include "../demo/Jisikin.c"
#include "../demo/MallocMemset.c"
#include "../demo/Math.c"
#include "../demo/MaxAndMin.c"
#include "../demo/NumberReal.c"
#include "../demo/Operator.c"
#include "../demo/PointerArray.c"
#include "../demo/Pointers.c"
#include "../demo/PrintCurrentFile.c"
#include "../demo/Printf.c"
#include "../demo/Recursion.c"
#include "../demo/RecursiveForLoop.c"
#include "../demo/Scanf.c"
#include "../demo/Shape.c"
#include "../demo/StringConcat.c"
#include "../demo/StringCopy.c"
#include "../demo/StringToNumber.c"
#include "../demo/StructA.c"
#include "../demo/UnionAndStruct.c"
#include "../demo/Variable.c"
#include "../demo/WhileLoop.c"
#include "../demo/LinkedList.c"
#include "../demo/PrimeNumber.c"
#include "../demo/Ascii.c"
#include "../demo/CallbackEx.c"
#include "../demo/HanoiTower.c"
#include "../demo/CreateRandomNumber.c"

#include "../common/Clock.c"
#include "../common/Hanoi.c"
#include "../common/DiffTime.c" 

void PrintMenu();
void Exec(int choice);
void Printf();
void PointerArray();
void Pointers();
void DataType();
void ArithmeticOperators();
void Scanf();
void Math();
void Function();
void Operator();
void Array();
void ArrayB();
void Array2D();
void Files(bool rw, char *message);
void Recursion();
void DataStruct();
void ArrayPointer();
void MallocMemset();
void CopyMemory();
void CharArrayPointer();
void CallByValue();
void CallByPointer();
void WhileLoop();
void ArrayShift();
void StructA();
void Database();
void BinarySearchTree();
void FiboStart();
void NumberReal();
void Calculate();
void Advenced();
void Bits();
void FileReadWrite();
void RecursiveForLoop();
void StringConcat();
void StringCopy();
void MaxAndMin();
void DefineTypedef();
void LinkedList();
void PrimeNumber();
void Ascii();
void Shape();
void CallbackEx();
void HanoiTower();
void CreateRandomNumber();

void Clock();
void Hanoi(int n, const char *src, const char *use, const char *dest);
