#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <algorithm>
#include <cstring>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "No input file supplied.\n";
        return 1;
    }

    // Create input file
    std::string file_path = argv[1];
    std::ifstream input_file(file_path);

    // Check if file successfully opened
    if (!input_file.is_open())
    {
        std::cout << "Failed to open file.\n";
        return 1;
    }

    // Preprocess file to remove non-Brainfuck characters
    std::string program((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    std::erase_if(program, [](char c)
                  { return !strchr("><+-.,[]", c); });

    // Init memory
    unsigned char mem[30000] = {0}, *ptr = mem;

    // Run program
    std::stack<std::streampos> loop_stack; // stack to keep track of loop positions
    std::size_t i = 0;
    while (i < program.length())
    {
        switch (program[i])
        {
        case '>':
            ++ptr;
            break;
        case '<':
            --ptr;
            break;
        case '+':
            ++*ptr;
            break;
        case '-':
            --*ptr;
            break;
        case '.':
            std::cout << *ptr;
            break;
        case ',':
            *ptr = getchar();
            break;
        case '[':
            if (*ptr != 0)
                loop_stack.push(i);
            break;
        case ']':
            *ptr ? void(i = loop_stack.top()) : loop_stack.pop();
            break;
        }
        ++i;
    }

    input_file.close();
    return 0;
}
