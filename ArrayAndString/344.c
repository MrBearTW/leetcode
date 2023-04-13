// 344. Reverse String

void reverseString(char *s, int sSize)
{
    int l, r, temp;
    for (l = 0, r = sSize - 1; l <= r; l++, r--)
    {
        temp = s[l];
        s[l] = s[r];
        s[r] = temp;
    }
    return *s;
}