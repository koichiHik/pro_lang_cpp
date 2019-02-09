
// Standart Library
#include <iostream>

class Example {
public:
  void print_int(int a) { std::cout << a << std::endl; }
};

int main(int, char **) {
  std::cout << __FILE__ << " Started!" << std::endl;

  // Class メンバ関数へのポインタ定義．
  {
    // Class メンバ関数へのポインタ定義．
    void (Example::*pf)(int) = &Example::print_int;
    Example ex1;
    // 通常の呼び方．
    ex1.print_int(10);
    // メンバ関数ポインタを用いた呼び方．
    (ex1.*pf)(20);
  }

  // using を使ったメンバ関数のポインタ型の定義．
  {
    // int を引数とし，void を返すメンバ関数ポインタの型定義．
    using pf = void (Example::*)(int);
    pf pf2 = &Example::print_int;
    Example ex2;
    (ex2.*pf2)(100);

    // オブジェクトへのポインタからの呼び方．
    ((&ex2)->*pf2)(200);
  }

  return 0;
}
