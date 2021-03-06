#include <cstdio>
#include <cstdlib>

struct A
{
        A(int i) : i(i)
        {
                printf("Constructing<%d>...\n", i);
        }
        ~A()
        {
                printf("Destructing<%d>...\n", i);
        }
        int i;
        A& operator=(const A& a)
        {
                i = a.i;
                return *this;
        }
};

int main(int argc, char** argv)
{
        A* a = new A(1);
        printf("======\n");
        delete a;
        a = new A(3);
        printf("======\n");
        delete a;
        a = new A(5);
        printf("======\n");
        delete a;
        printf("leaving main\n");
        return EXIT_SUCCESS;
}
