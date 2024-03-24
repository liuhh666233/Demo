template <typename E>
bool isLuck(E &&p) = delete;

bool isLuck(int p)
{
    return p == 7;
}

int main()
{
    isLuck(8);
    isLuck(3.5);
}
