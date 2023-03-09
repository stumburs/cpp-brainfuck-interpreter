#include <iostream>
#include <string>
#include <fstream>
#include <stack>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "No input file supplied.\n";
        std::cin.ignore();
        return 1;
    }

    // Create input file
    std::string file_path = argv[1];
    std::ifstream input_file(file_path);

    // Check if file successfully opened
    if (!input_file.is_open())
    {
        std::cout << "Failed to open file.\n";
        std::cin.ignore();
        return 1;
    }

    // Init memory
    unsigned char mem[30000] = {0};
    unsigned char *ptr = mem;

    // Read file
    char ch;
    std::stack<std::streampos> loop_stack; // stack to keep track of loop positions
    while (input_file.get(ch))
    {
        if (ch == '>')
            ++ptr;
        if (ch == '<')
            --ptr;
        if (ch == '+')
            ++*ptr;
        if (ch == '-')
            --*ptr;
        if (ch == '.')
            std::cout << *ptr;
        if (ch == ',')
            *ptr = getchar();
        if (ch == '[')
            if (*ptr != 0)
                loop_stack.push(input_file.tellg());
        if (ch == ']')
            if (*ptr != 0)
                input_file.seekg(loop_stack.top(), std::ios_base::beg);
            else
                loop_stack.pop();
    }

    input_file.close();
    std::cin.ignore();
    return 0;
}