#include "../BootCamp/Playground/Snippets/Advenced.c"
#include "../BootCamp/Playground/Snippets/ArithmeticOperators.c"
#include "../BootCamp/Playground/Snippets/Array.c"
#include "../BootCamp/Playground/Snippets/Array2D.c"
#include "../BootCamp/Playground/Snippets/ArrayB.c"
#include "../BootCamp/Playground/Snippets/ArrayPointer.c"
#include "../BootCamp/Playground/Snippets/ArrayShift.c"
#include "../BootCamp/Playground/Snippets/Ascii.c"
#include "../BootCamp/Playground/Snippets/BinarySearchTree.c"
#include "../BootCamp/Playground/Snippets/Bits.c"
#include "../BootCamp/Playground/Snippets/Calculate.c"
#include "../BootCamp/Playground/Snippets/CallByPointer.c"
#include "../BootCamp/Playground/Snippets/CallByValue.c"
#include "../BootCamp/Playground/Snippets/CallbackEx.c"
#include "../BootCamp/Playground/Snippets/CharArrayPointer.c"
#include "../BootCamp/Playground/Snippets/CheckInput.c"
#include "../BootCamp/Playground/Snippets/CopyMemory.c"
#include "../BootCamp/Playground/Snippets/CreateRandomNumber.c"
#include "../BootCamp/Playground/Snippets/DataStruct.c"
#include "../BootCamp/Playground/Snippets/DataType.c"
#include "../BootCamp/Playground/Snippets/Database.c"
#include "../BootCamp/Playground/Snippets/DefineTypedef.c"
#include "../BootCamp/Playground/Snippets/FGets.c"
#include "../BootCamp/Playground/Snippets/Fibo.c"
#include "../BootCamp/Playground/Snippets/FileReadWrite.c"
#include "../BootCamp/Playground/Snippets/Files.c"
#include "../BootCamp/Playground/Snippets/Function.c"
#include "../BootCamp/Playground/Snippets/GetChar.c"
#include "../BootCamp/Playground/Snippets/GetStringLength.c"
#include "../BootCamp/Playground/Snippets/HanoiTower.c"
#include "../BootCamp/Playground/Snippets/Iterator.c"
#include "../BootCamp/Playground/Snippets/Jisikin.c"
#include "../BootCamp/Playground/Snippets/LinkedList.c"
#include "../BootCamp/Playground/Snippets/MallocMemset.c"
#include "../BootCamp/Playground/Snippets/Math.c"
#include "../BootCamp/Playground/Snippets/MaxAndMin.c"
#include "../BootCamp/Playground/Snippets/NumberReal.c"
#include "../BootCamp/Playground/Snippets/Operator.c"
#include "../BootCamp/Playground/Snippets/PointerArray.c"
#include "../BootCamp/Playground/Snippets/Pointers.c"
#include "../BootCamp/Playground/Snippets/PrimeNumber.c"
#include "../BootCamp/Playground/Snippets/PrintCurrentFile.c"
#include "../BootCamp/Playground/Snippets/Printf.c"
#include "../BootCamp/Playground/Snippets/Recursion.c"
#include "../BootCamp/Playground/Snippets/RecursiveForLoop.c"
#include "../BootCamp/Playground/Snippets/Scanf.c"
#include "../BootCamp/Playground/Snippets/Shape.c"
#include "../BootCamp/Playground/Snippets/StringConcat.c"
#include "../BootCamp/Playground/Snippets/StringCopy.c"
#include "../BootCamp/Playground/Snippets/StringToNumber.c"
#include "../BootCamp/Playground/Snippets/StructA.c"
#include "../BootCamp/Playground/Snippets/UnionAndStruct.c"
#include "../BootCamp/Playground/Snippets/Variable.c"
#include "../BootCamp/Playground/Snippets/WhileLoop.c"
#include "vivstd.h"

#include "../common/Clock.c"
#include "../common/DiffTime.c"
#include "../common/Hanoi.c"

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

void StringUtils();
