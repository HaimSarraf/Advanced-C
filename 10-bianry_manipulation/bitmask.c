int main()
{
    int flags = 15;       // 0000 1111

    int mask = 182;       // 1011 0110

    flags = flags | mask; // 1011 1111

    flags = flags & ~mask;// 0000 1001

    flags = flags ^ mask; // 1011 1001

    /*
        if(flags == mask) puts("WOW"); //? doesn't work right
        ?? even if bit 1 in flags is set to 1,
        ?? the other bit setting in flags can
        ?? make the comparison untrue

        !! first mask the other bits in flags so that
        !! you can compare only bit 1 of flags with mask
        if((flags & mask) == mask) puts("WOW"); //? That's true !
    */

    return 0;
}