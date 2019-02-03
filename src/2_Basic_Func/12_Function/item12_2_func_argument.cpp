
#include <iostream>

void updateBuildable(const float& i);
void gOK(double d, float r);
void updateUnBuildable(float& i);
void gNG(double d, float r);
void sampleFunc(float& a);

void updateBuildable(const float& i) {
  float tmp;
  tmp = i + 1.0f;
}

void gOK(double d, float r) {
  updateBuildable(2.0f);

  // double -> float への暗黙の型変換．警告が出る．
  updateBuildable(d);
  updateBuildable(r);
}

void updateUnBuildable(float& i) {
  float tmp;
  tmp = i + 1.0f;
}

void gNG(double, float r) {
  // Const を 非 Const の実引数として渡しているからダメ！
  //updateUnBuildable(2.0f);

  // 参照引数間での暗黙変換はなし？？
  //updateUnBuildable(d);

  // 
  updateUnBuildable(r);

  sampleFunc(r);
}

void sampleFunc(float& a) {
  a = a + 1.0f;
}

int main(int, char const**)
{
  std::cout << __FILE__ << "Started!" << std::endl;

  gOK(1.0, 2.0f);

  gNG(1.0, 2.0f);

  //sampleFunc(2.0f);

  return 0;
}
