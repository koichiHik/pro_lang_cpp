
#include <iostream>

// Prototype Declaration
void print_int(int);

// Function Definition.
void print_int(int a) { std::cout << a << std::endl; }

// 関数ポインタの実験ケース．
static void test1()
{
  {
    // 返り値が void, 引数が int の関数ポインタ pf の定義．
    void (*pf)(int) = print_int;
    // 1. 参照外しなしの呼び方．
    pf(1);
    // 2. 参照外しありの呼び方．
    (*pf)(1);
  }

  {
    // 関数ポインタの型を typedef する．
    typedef void (*void_int_func)(int);
    void_int_func pf = print_int;
    // 1. 参照外しなしの呼び方．
    pf(10);
    // 2. 参照外しありの呼び方．
    (*pf)(10);
  }

  {
    // 関数ポインタの型を using する．
    using void_int_func = void (*)(int);
    void_int_func pf = print_int;
    // 1. 参照外しなしの呼び方．
    pf(100);
    // 2. 参照外しありの呼び方．
    (*pf)(100);
  }
}

int main(int, char **)
{
  std::cout << __FILE__ << " Started!" << std::endl;
  test1();
}
