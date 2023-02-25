#include <stdio.h>
#include <string.h>

// To Shorten long double
typedef long double LongD;

// Book Struct
struct Book
{
    char title[225];
    LongD price;
};


int main(int argc, char const *argv[])
{
    // Struct Fundamentals
    Book book1;
    book1.price = 15000;
    strcpy(book1.title, "Harry Potter");

    printf("%s %.2Lf\n", book1.title, book1.price);

    // Array of Struct
    Book books[5];
    books[0].price = 20000;
    strcpy(books[0].title, "Narnia");

    printf("%s %.2Lf\n", books[0].title, books[0].price);
    return 0;
}
