#include <iostream>
#include <cstdlib>

struct move_array;

std::ostream& operator<<(std::ostream&, const move_array&);

struct move_array
{
    int * array;
    int size;

    public:
    move_array() : array(nullptr), size(0)
    {
    }

    explicit move_array(int _size) : array(new int[_size]), size(_size)
    {
    }

    /* what a copy constructor would look like */
#if 0
    move_array(const move_array & m) : array(new int[m.size]), size(m.size)
    {
        int count;
        for(count = 0; count < size; ++count)
        {
            array[count] = m.array[count];
        }
    }
#endif
    /* move constructor */
    move_array(move_array && m) : array(std::move(m.array)), 
    size(std::move(m.size))
    {
        m.array = nullptr;
    }

    virtual ~move_array()
    {
        delete[] array;
    }
};

int main(void)
{
	move_array m(5);
    int count;
    for(count = 0; count < 5; ++count)
    {
        m.array[count]=count;
    }
    std::cout << m << std::endl;
    move_array n = move_array(std::move(m));
    std::cout << n << std::endl;
    /* comment out this line to remove segmentation fault
    */
    std::cout << m << std::endl;
    move_array n = m;
    return EXIT_SUCCESS;
}

std::ostream& operator<<(std::ostream& out, const move_array& array)
{
    int count;
    for(count = 0; count < array.size; ++count)
    {
        out << array.array[count] << '\t';
    }
    return out;
}

