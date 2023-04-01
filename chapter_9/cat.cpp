#include <iostream>

using namespace std;

class Cat
{
public:
    int get_age() const { return age_; }
    int get_weight() const { return weight_; }
    //返回RGB值
    int get_color() const { return color_; }
    //返回R分量值
    int get_red() const { return color_ >> 16; }
    //返回G分量值
    int get_green() const { return (color_ >> 8) & 0xff; }
    //返回B分量值
    int get_blue() const { return color_ & 0xff; }

    void set_age(int age) { age_ = age; }
    void set_weight(int weight) { weight_ = weight; }
    //使用RGB值设置颜色
    void set_color(int color) { color_ = color; }
    //使用R,G,B分量设置颜色
    void set_color(int r, int g, int b) { color_ = r << 16 | g << 8 | b; }

private:
    int age_;
    int weight_;
    // RGB值
    int color_;
};

int main()
{
    Cat cat;
    cat.set_age(2);
    cat.set_weight(5);
    cat.set_color(0x00ff00);
    cout << "cat's age is " << cat.get_age() << endl;
    cout << "cat's weight is " << cat.get_weight() << endl;
    cout << "cat's red is " << cat.get_red() << endl;
    cout << "cat's green is " << cat.get_green() << endl;
    cout << "cat's blue is " << cat.get_blue() << endl;

    cat.set_color(0xff, 0, 0);
    cout << "cat's red is " << cat.get_red() << endl;
    cout << "cat's green is " << cat.get_green() << endl;
    cout << "cat's blue is " << cat.get_blue() << endl;
    return 0;
}