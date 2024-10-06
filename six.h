#include <cmath>
#include <iostream>

class Six {
    public:
        Six();
        Six(const size_t & n, unsigned char t = 0);
        Six(const std::initializer_list<unsigned char> &t);
        Six(const std::string &t);

        unsigned char * get_value() const;

        Six(const Six& other);
        Six(Six&& other) noexcept;

        Six& operator=(const Six & other);
        Six operator+(const Six & other) const;
        Six operator-(const Six & other) const;
        bool operator==(const Six & other) const;
        bool operator<(const Six& other) const;
        bool operator>(const Six& other) const;
        Six& operator+=(const Six & other);
        Six& operator-=(const Six & other);
        Six& operator=(Six&& other)  noexcept ;

        ~Six() noexcept;

    private:
        size_t size;
        unsigned char *array;
        static void swap(Six& h1, Six& h2) ;
};
