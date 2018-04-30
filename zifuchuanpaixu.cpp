// #include <iostream>
// #include <string>
// #include <list>
// using namespace std;

// class A//定义类A，并以友元重载<, == 和 <<
// {
// private:
//     string name;
// public:
//     A(string n): name(n) {}
//     friend bool operator < (const class A& a1, const class A& a2);
//     friend bool operator == (const class A& a1, const class A& a2)
//     {
//         if (a1.name.size() == a2.name.size())
//         {
//             return true;
//         } 
//         else
//         {
//             return false;
//         }
//     }
//     friend ostream& operator << (ostream& o, const A& a)
//     {
//         o << a.name;
//         return o;
//     }
//     string get_name() const
//     {
//         return name;
//     }
//     int get_size() const
//     {
//         return name.size();
//     }
// };
//在此处补充你的代码
bool operator < (const A& a1, const A& a2)
{
    return a1.get_size() < a2.get_size();
}

template <class Iterator, class Function>//函数模板
void Show(Iterator begin, Iterator end, Function print)
{
    for (Iterator iterator1 = begin; iterator1 != end; iterator1++)
    {
        print(*iterator1);
    }
}

class Print //函数对象类
{
public:
    void operator() (const A& a)
    {
        cout << a.get_name() << " ";
    }
};

template <class A>  //函数对象类模板
struct MyLarge
{
    inline bool operator() (const A& a1, const A& a2)
    {
        return a1.get_name() < a2.get_name();
    }
};

// int main(int argc, char* argv[])
// {
//     list<A> lst;
//     int ncase, n, i = 1;
//     string s;
//     cin >> ncase;
//     while(ncase--)
//     {
//         cout << "Case: " << i++ << endl;
//         cin >> n;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> s;
//             lst.push_back(A(s));
//         }
//         lst.sort();//如上已经重载的A类型的“<”号，按尺寸排序
//         Show(lst.begin(), lst.end(), Print());//Print()为函数对象,用途类似于函数指针或函数名字

//         cout << endl;
//         lst.sort(MyLarge<A>());//按照函数对象的方式进行排序
//         Show(lst.begin(), lst.end(), Print());
//         cout << endl;
//         lst.clear();
//     }
//     return 0;
// }