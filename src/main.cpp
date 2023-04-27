#include <cinttypes>
#include <iostream>

static std::uintmax_t argToUmax(char *argv[], int argIndex, int base)
{
  char *endptr;
  std::uintmax_t value = std::strtoumax(argv[argIndex], &endptr, base);
  if (*endptr != '\0')
  {
    throw std::invalid_argument(
      std::string(argv[argIndex]) + " is invalid in base " + std::to_string(base));
  }
  return value;
}

int main(int argc, char *argv[])
{
  if (argc < 5)
  {
    std::cout << "Usage: brutty format_str start_number end_number file.zip\n";
    return 2;
  }
  try
  {
    argToUmax(argv, 2, 10);
    argToUmax(argv, 3, 10);
  }
  catch (const std::invalid_argument &except)
  {
    std::cout << except.what() << '\n';
    return 1;
  }

  return 0;
}
