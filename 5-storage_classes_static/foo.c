int fun();

void foo()
{
    fun();

}

//! the fun() declared in main.c is extern by default.
//! but if we add a static keyword before it there in main.c ,
//! then we'll recieve an error in compilation-time,
//! cause we can't use fun() inside foo.c file then!